#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int i, sum = 0;
    for(i=1;i<=100;i++){
        sum += i;
        msg(i, sum)
    }

    return 0;
}
