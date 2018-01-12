#include<iostream>
using namespace std;
int main(){
    int i;
    long a,sum = 1, num=0,arr[10000],arrCounter = 0;
    for(;;){
        sum = 1;
        num=0;
        cin >> a;
        if(a<0){break;}
        for(i=0;i<=a;i++){
            sum += num;
            num++;
        }
        arr[arrCounter] = sum;
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << arr[i] << endl;
    }
	return 0;
}
