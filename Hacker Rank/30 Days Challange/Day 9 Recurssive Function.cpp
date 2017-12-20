#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long factorial(long long n){
    if(n == 1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}

int main() {
    long long a;
    cin >> a;
    cout << factorial(a);
    return 0;
}
