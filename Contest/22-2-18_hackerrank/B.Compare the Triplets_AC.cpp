#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int arr[4],arr2[4],i,j,alice = 0, bob=0;
    for(i=1;i<=3;i++){
        cin >> arr[i];
    }
    for(i=1;i<=3;i++){
        cin >> arr2[i];
        if(arr[i] > arr2[i]){
            alice++;
        }else if(arr[i] < arr2[i]){
            bob++;
        }
    }
    cout << alice << " " << bob << endl;





    return 0;
}
