#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 1000006
int mat[MX][10];
long long int mine[MX];
long long int g(long long int n){
    long long int temp,sum;
    //cc(n)
    if(n< 10){
        return n;
    }else{
        temp = n;
        sum = 1;
        while(temp != 0){
            if(temp%10 != 0){
                sum = sum * (temp%10);
            }
            temp = temp / 10;
        }
        //msg(n, sum)
        return g(sum);
    }
}

int main(){
    int i;
    long long int ss,a,b,c,n,counter;
    cin >> n;
    cc(g(n))
    while(n--){
        cin >> a >> b >> c;
        counter = 0;
        for(i=a;i<=b;i++){
            if(g(i) == c){
                counter++;
            }
        }
            cc(counter)
        msg(mat[a][c], mat[b][c])
    }


    return 0;
}
