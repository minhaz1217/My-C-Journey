#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){

    long long int n,k, counter,i,a;
    string str;
    cin >> n >> k;
    int arr[n+4];
    counter = 0;
    for(i=0;i<=n;i++){
        arr[i] = 0;
    }

    while(k--){
        cin >> str;
        if(str == "CLICK"){
            cin >> a;
            if(arr[a] == 0){
                arr[a] = 1;
                counter++;
            }else{
                arr[a] = 0;
                counter = max((long long int)0, counter-1);
            }
        }else{
            counter=0;
            for(i=0;i<=n;i++){
                arr[i] = 0;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
