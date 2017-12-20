#include<iostream>
using namespace std;
int main(){
    int a,i,arrCounter = 0,num[7],temp;
    cin >> a;
    int arr[a];
    for(i=1;i<=a;i++){
        cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4] >> num[5] >> num[6];
        if(num[5] > num[4] && num[5] > num[6]){
            temp = num[4];
            num[4] = num[5];
            num[5] = temp;
        }else if(num[6] > num[4] && num[6] > num[5]){
            temp = num[4];
            num[4] = num[6];
            num[6] = temp;
        }
        if(num[6] >= num[5]){
            temp = num[5];
            num[5] = num[6];
            num[6] = temp;
        }
        arr[arrCounter] = num[0] + num[1] + num[2] + num[3] + ((num[4] + num[5])/2);
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        if(arr[i]>= 90){
            cout << "Case "<< i+1 <<": A"<<endl;
        }else if(arr[i]>= 80 && arr[i] < 90){
            cout << "Case "<< i+1 <<": B"<<endl;
        }else if(arr[i]>= 70 && arr[i] < 80){
            cout << "Case "<< i+1 <<": C"<<endl;
        }else if(arr[i]>= 60 && arr[i] < 70){
            cout << "Case "<< i+1 <<": D"<<endl;
        }else if(arr[i] < 60){
            cout << "Case "<< i+1 <<": F"<<endl;
        }
    }





    return 0;
}
