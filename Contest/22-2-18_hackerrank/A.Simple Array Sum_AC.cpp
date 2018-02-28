#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,i,a,sum;
    cin >> n;
    sum = 0;
    while(n--){
        cin >> a;
        sum += a;
    }
    cout << sum << endl;
    return 0;
}
