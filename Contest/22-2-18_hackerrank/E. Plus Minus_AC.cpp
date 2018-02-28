#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    double a,n,pos,neg,zero;
    int i;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a;
        if(a > 0){
            pos++;
        }else if(a < 0){
            neg++;
        }else{
            zero++;
        }
    }
    printf("%.6f\n%.6f\n%.6f\n", pos/n,neg/n,zero/n);


    return 0;
}
