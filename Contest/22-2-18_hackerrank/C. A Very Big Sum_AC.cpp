#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    long long int a,sum= 0,n;
    cin >> n;
    while(n--){
        cin >> a;
        sum += a;
    }
    cout << sum << endl;
    return 0;
}
