#include<iostream>
using namespace std;
int main(){
    int n,k,sum = 0,arr[10000],arrCounter = 0;
    for(;;){
        sum = 0;
        cin >> n;
        if(cin.eof()){
            break;
        }
        cin >> k;
        if(cin.eof()){
            break;
        }
        sum += n;
        while(n >= k){
            n -= k;
            n++;
            sum++;
        }
        arr[arrCounter] = sum;
        arrCounter++;
    }
    for(n=0;n<arrCounter;n++){
        cout << arr[n] << endl;
    }
	return 0;
}
