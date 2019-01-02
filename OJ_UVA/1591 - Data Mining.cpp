#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
int p,q,A,B;
int P(int i){
    return p*i;
}
int Q(int i){
    return (P(i)/ p ) * q;
}
int Qp(int i){
    return (( P(i) +(P(i)<<A) ) >> B);
}
int main(){
    int n;
    cin >> n >> p >> q;
    A= 0;
    B = 0;

            set<int>st;
            for(int i=0;i<n;i++){
                st.insert(Qp(i));
            }
            /*
    for(A= 0;A<=10;A++){
        for(B=0;B<=10;B++){
            set<int>st;
            for(int i=0;i<n;i++){
                st.insert(Qp(i));
            }
            msg3(A,B,Qp(n-1),st.size())
        }
    }*/

    return 0;
}
