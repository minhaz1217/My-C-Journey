#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int tc,n,i,j,temp,k,counter,cc;
    int flag = 0,multiCounter;


    int arr[11];
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<long long int>v;
        for(i=0;i<11;i++){
            arr[i] = 0;
        }
        flag = 1;
        multiCounter = 1;
        counter = 1;
        while(flag){
            cc = n*multiCounter;
            //msg("MEH ", cc)
            multiCounter++;

            for(i=0;i<v.size();i++){
                if(v[i] == cc){
                    //cout << "HI" << n << endl;
                    flag = 0;
                    break;
                }
            }
            v.push_back(cc);
            temp = cc;
            while(temp!=0 && flag){
                k = temp%10;
                if(arr[k] == 0){
                    arr[k] = 1;
                    counter++;
                }
                temp = temp/10;
            }
            if(counter > 10 ){
                flag = 1;
                break;
                //cout << n << endl;
            }
        }
        if(flag == 0){
            cout << "INSOMNIA" << endl;
        }else{
            cout << cc << endl;
        }
    }

    return 0;
}
