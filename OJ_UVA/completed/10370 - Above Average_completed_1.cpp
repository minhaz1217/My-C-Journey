#include<iostream>
using namespace std;
int main(){
    int b,k,a,arrCounter = 0,i;
    double sum=0,numCounter = 0;
    cin >> a;
    double arr[a];
    for(i=0;i<a;i++){
        cin >> b;
        int num[b];
        sum = 0;
        numCounter = 0;
        for(k=0;k< b;k++){
            cin >> num[k];
            sum += num[k];
        }
        sum = sum/b;
        for(k=0;k<b;k++){
            if(num[k] > sum){
                numCounter++;
            }
        }
        arr[arrCounter] = (numCounter*100/b);
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout.precision(3);
        cout <<fixed<< arr[i] <<"%" <<endl;
    }
	return 0;
}
