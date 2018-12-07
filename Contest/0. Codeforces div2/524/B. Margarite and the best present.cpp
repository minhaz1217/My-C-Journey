#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
long long int term(int ai){
    if(ai %2 == 0){
        return ai;
    }
    else{
        return ai*-1;

    }
}

int howManyEven(int l, int r){
    if(l%2 == 0 && r%2==0){
        return (r-l)/2 +1;
    }else if(l%2 != 0 && r%2 != 0){
        return (r-l)/2 ;
    }else{
        int n;
        n = r-l+1;
        if(n%2 == 0){
            return n/2;
        }
        return floor((double)n/2);
    }




}
int howManyOdd(int l, int r){
    if(l%2 == 0 && r%2==0){
        return (r-l)/2 ;
    }else if(l%2 != 0 && r%2 != 0){
        return (r-l)/2 +1;
    }else{
        int n = r-l+1;
        if(n%2 == 0){
            return n/2;
        }
        return ceil((double)n/2);
    }
}

long long int sum(int l, int r){
    //int n = howManyEven(r-l);
    double ne,no,even,odd;
    if(l%2 == 0){
        ne = howManyEven(l,r);
        no = howManyOdd(l,r);
        even = (ne/2) * (2 * l + (ne-1)*2);
        odd = (no/2) * (2*( l+1) + (no-1)*2);
    }else{
        ne = howManyEven(l,r);
        no = howManyOdd(l,r);
        even = (ne/2) * (2 * (l+1) + (ne-1)*2);
        odd = (no/2) * (2*( l) + (no-1)*2);
    }
    //msg2("H",even,odd)
    return even + (odd*-1);
}


int main(){
    long long int n,l,r;
    cin >> n;
    while(n--){
        cin >> l >> r;
        //msg(howManyEven(l,r), howManyOdd(l,r))
        cout << sum(l,r) << endl;
    }



    return 0;
}
