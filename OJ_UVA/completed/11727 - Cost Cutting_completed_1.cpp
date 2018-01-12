#include<iostream>
using namespace std;
int main(){
    int a,i,num[3],arrCounter=0,temp;
    cin >> a;
    int arr[a];
    for(i=0;i<a;i++){
        cin >> num[0] >> num[1]>> num[2];
        if(num[0] >= num[1] && num[0] >= num[2]){
            temp = num[2];
            num[2] = num[0];
            num[0] = temp;
        }else if(num[1] >= num[0] && num[1] >= num[2]){
            temp = num[2];
            num[2] = num[1];
            num[1] = temp;
        }
        if(num[0] > num[1]){
            temp = num[1];
            num[1] = num[0];
            num[0] = temp;
        }
        arr[arrCounter] = num[1];
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << "Case " << i+1 << ": " << arr[i]<< endl;
    }

    return 0;
}
