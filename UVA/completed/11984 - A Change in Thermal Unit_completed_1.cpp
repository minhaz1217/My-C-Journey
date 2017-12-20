#include<iostream>
using namespace std;
int main(){
    int i,arrCounter = 0,a;
    double f,c;
    cin >> a;
    double arr[a];
    for(i=0;i<a;i++){
        cin >> c >> f;
        arr[arrCounter] = c + f*5/9;
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout.precision(2);
        cout<<"Case " << i+1 << ": " <<  fixed<< arr[i]<< endl;
    }


    return 0;
}
