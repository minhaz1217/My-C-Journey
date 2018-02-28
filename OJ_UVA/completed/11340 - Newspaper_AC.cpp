

// had to check for non ascii characters. ascii characters go from 0 to 127.
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 1000
int arr[MX];
int main(){
    int tc,n,i,j,b;
    char a;
    double sum;
    string str;
    cin >> tc;
    while(tc--){
        cin >> n;
        for(i=0;i<MX;i++){
            arr[i] = 0;
        }
        for(i=0;i<n;i++){
            cin >> a >> b;
            arr[(int)a] = b;
        }
        cin >> n;
        cin.ignore();
        sum = 0;
        for(i=0;i<n;i++){
            getline(cin,str);
            for(j=0;str[j];j++){
                if((int)str[j] >=0 && (int)str[j] <= 127){
                    sum += arr[str[j]];
                }
            }
        }
        printf("%.2f$\n", sum/100);
        //cout << sum << "$"<< endl;
    }

    return 0;
}
