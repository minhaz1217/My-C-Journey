#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MX_ELEMENT 1002
vector<int>A,B,C;

void quickSort(int n){

    B.assign(n,0);
    C.assign(MX_ELEMENT,0); // the maximum element value possible is 1000
    for(int i=0;i<A.size();i++){
        C[ A[i] ]++;
    }
    for(int i=1;i<MX_ELEMENT;i++){
        C[i] = C[i] + C[i-1];
    }
    for(int i=A.size()-1;i>=0;i--){
        B[ C[ A[i] ]-1 ] = A[i];
        C[ A[i] ]--;
    }

    cc("AFTER SORING")
    for(int i=0;i<B.size();i++){
        cout << B[i] << " ";
    }
    cout << endl;

}


int main(){

    for(int i=0;i<10;i++){
        A.push_back( (rand()*1000) % MX_ELEMENT );

    }
    cc("BEFORE SORING")
    for(int i=0;i<A.size();i++){
        cout << A[i] << " ";
    }
    cout << endl;
    quickSort(A.size());

    return 0;
}
