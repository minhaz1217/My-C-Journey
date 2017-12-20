#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a, b,big, small,sq1,sq2;
    while(1){
        cin >> a >> b;
        if(a ==0 && b ==0){
            break;
        }
        big = a>=b? a : b;
        small = a<b? a: b;
        a = ceil(sqrt(big)) - ceil(sqrt(small));
        sq1 = sqrt(big);
        if(sq1*sq1 == big){
            a++;
        }
        cout << a << endl;
    }
    return 0;
}

