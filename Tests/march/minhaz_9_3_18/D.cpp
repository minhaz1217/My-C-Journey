#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;
#define sv 100004
bool prime[sv];
int arr[sv];

void sieve(){
    int root,i,j;
    root = sqrt(sv)+1;
    for(i=0;i<=sv;i++){
        prime[i] = 1;
    }
    for(i=2;i<=root;i++){
        if(prime[i]){
            for(j=i;j*i <=sv;j++){
                prime[i*j] = 0;
            }
        }
    }

}

int main(){
    sieve();
    int sz,n,i,j,counter,flag;
    vector<pair<int, int> >vec;
    scanf("%d", &n);
    //cc(n)
    for(i=1;i<=n;i++){
        scanf("%d", &arr[i]);
    }
    flag = 1;
    counter = 0;
    for(i=1;i<=n-1 && flag;i++){
        for(j=i+1;j<=n && flag;j++){
            if(prime[arr[j-i+1]] && arr[i] > arr[j]){
                swap(arr[i],arr[j]);
                counter++;
                vec.push_back(make_pair(arr[i], arr[j]));
                //printf("%d %d\n", arr[j], arr[i]);
            }
            if(counter > 5*n){
                flag = 0;
                break;
            }
        }
    }
    printf("%d\n",counter);
    sz = vec.size();
    for(i=0;i<sz;i++){
        printf("%d %d\n",vec[i].first, vec[i].second);
    }



    return 0;
}
