#include<iostream>
#include<cstdio>
using namespace std;

int main(){

    long long tc, a,n,k,i,sum,counter, lastIndex,myMx, people;
    cin >> tc;
    while(tc--){
        lastIndex = 0;
        people = 0;
        counter = 0;
        myMx = 0;
        sum = 0;

        cin >> n >> k;
        long long arr[n+4];
        for(i=0;i<n;i++){
            scanf("%lld", &a);
            arr[i] = a;
            if(sum + a > k){
                while(sum+a > k && lastIndex != i){
                    sum = sum - arr[lastIndex];
                    lastIndex = lastIndex +1;
                    counter--;
                }
                if(lastIndex == i){
                    sum = 0;
                    counter = 0;
                }
            }else{
                sum += a;
                counter++;
            }
            if(counter > myMx){
                myMx = counter;
                people = sum;
            }else if(counter == myMx){
                people = min(people, sum);
            }
        }
        cout << people << " " << myMx << endl;
        //msg(people, myMx);
        //check(lastIndex)
    }

    return 0;
}
