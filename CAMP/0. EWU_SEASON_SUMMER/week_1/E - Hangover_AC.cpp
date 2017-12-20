#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    double n, i=2, sum = 0,counter= 0;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        i = 2;
        sum =0;
        counter =0;
        while(sum <= n){
            sum += 1/i;
            i++;
            counter++;
        }

        cout << (int)counter << " card(s)" << endl;

    }

    return 0;
}
