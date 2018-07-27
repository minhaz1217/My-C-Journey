#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

void rec4(int i, int n){
    if(i==n-1){
        cout << " x^" << i << endl;
        return;
    }
    if(i==0){
        cout << 1 << " +";
    }else{
        cout << " x^" << i << " +";
    }
    rec4(i+1, n);
}
void rec4_2(int i, int n){
    if(i<n){
        if(i==0){
            cout << 1;
        }else if(i==1){
            cout << " + x";
        }else{
            cout << " + x^" << i;
        }
        rec4_2(i+1, n);
    }
}


void rec5(int i, int n,int x, int sum){
    msg("HI", sum)
    if(i<n){
        if(i==0){
            sum += 1;
        }else{
            sum += pow(x,i);
        }
    }else{
        cout << sum << endl;
        return;
    }
    rec5(i+1,n,x,sum);

}
int rec5_2(int i, int n, int x){
    if(n==0){
        return 1;
    }
    if(i<n){
        return pow(x, i) + rec5_2(i+1,n,x);
    }
    return 0;
}

// factorial
int rec6(int i){
    if(i==1){
        return 1;
    }else{
        return i * rec6(i-1);
    }
}
int rec6_prac(int i, int n){
    if(i!=n){
        return i*rec6_prac(i+1,n);
    }
}

// n th fib
int rec7(int i){
    if(i<3){
        return 1;
    }else{
        return (rec7(i-1) + rec7(i-2));
    }
}




int main(){
    int n,x;
    cin >> n;
    cout << rec7(n) << endl;
    return 0;
}
