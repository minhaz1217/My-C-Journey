#include<iostream>
using namespace std;
int main(){
    int a[10],i, sum =0, maxNum, minNum;
    double avg =0;
    for(i=0;i<10;i++){
        cout << "Enter a number: ";
        cin >> a[i];
    }
    maxNum = a[0];
    minNum = a[0];
    for(i=0;i<10;i++){
        if(a[i] > maxNum){
            maxNum = a[i];
        }
        if(a[i] < minNum ){
            minNum = a[i];
        }
        sum += a[i];
    }
    avg = static_cast<double>(sum)/10;
    cout << "Maximum: " << maxNum << endl;
    cout << "Minumum: " << minNum << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;

    return 0;
}
