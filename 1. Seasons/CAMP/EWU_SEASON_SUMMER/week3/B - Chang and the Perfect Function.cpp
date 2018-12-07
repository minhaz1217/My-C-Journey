#include<iostream>
#include<cmath>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int a,b,i,j,sq,mul,counter= 0;
    cin >> a >> b;
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            mul = i*i + j;
            sq = sqrt(mul);
            if( sq * sq == mul){
                counter++;
            }
        }
    }
    cout << counter << endl;

    return 0;
}
