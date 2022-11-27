#include<bits/stdc++.h>
using namespace std;

int main(){
    int mark[11];
    int arr[9] = {1,6,3,4,5,10,7,8,9};

    for(int i=0;i<11;i++){
        mark[i] = 0;
    }

    for(int i=0;i<9;i++){
        mark[ arr[i] ] = 1;
    }

    for(int i=1;i<=10;i++){
        if(mark[i] == 0){
            cout << "The missing number is: " << i << endl;
            return 0;
        }
    }
    return 0;
}
