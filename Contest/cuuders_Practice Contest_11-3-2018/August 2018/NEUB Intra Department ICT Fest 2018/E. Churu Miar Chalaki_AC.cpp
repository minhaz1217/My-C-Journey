#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,m,q;
    cin >> n >> m >> q;
    while(q--){
        string str;
        char c;
        long long int a;
        cin >> str;
        c = str[0];
        str = str.substr(1, str.size()-1);
        stringstream ss(str);
        ss >> a;
        if(c == 'L'){
            for(long long int i=1;i<=m;i++){
                if(i>1){
                    printf(", ");
                }
                printf("(%lld,%lld)", a, i);
            }
            printf("\n");
        }else if(c == 'R'){
            for(long long int i=m;i>=1;i--){
                if(i<m){
                    printf(", ");
                }
                printf("(%lld,%lld)", a, i);
            }
            printf("\n");
        }else if(c == 'D'){
            for(long long int i=n;i>=1;i--){
                if(i<n){
                    printf(", ");
                }
                printf("(%lld,%lld)", i, a);
            }
            printf("\n");
        }else{
            for(long long int i=1;i<=n;i++){
                if(i>1){
                    printf(", ");
                }
                printf("(%lld,%lld)", i, a);
            }
            printf("\n");
        }
    }


    return 0;
}
