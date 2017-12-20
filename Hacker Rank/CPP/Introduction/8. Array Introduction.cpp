#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a,i;
    cin >> a;
    int arr[a];
    for(i=a-1;i>=0;i--){
        cin >> arr[i];
    }
    for(i=0;i<a;i++){
        cout << arr[i] << " ";
    }



    return 0;
}
