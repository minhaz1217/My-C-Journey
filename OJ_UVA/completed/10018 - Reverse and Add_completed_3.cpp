#include<iostream>
using namespace std;
int main(){
    long long int num1=0,num2=0,temp,sum;
    int arrCounter = 0,i,j,flag=0,counter = 1,a;
    char  arr[20];
    cin >> a;
    while(a--){
    cin >> num1;
    counter = 1;
    for(;;){
        flag = 0;
        num2 =0;
        arrCounter = 0;
        temp = num1;
        while(temp!=0){
            num2 = (num2*10) + temp %10;
            temp = temp/10;
        }
        sum = num1 + num2;
        temp = sum;
        while(temp!=0){
            arr[arrCounter++] = (temp%10) + 48;
            temp = temp/10;
        }
        arr[arrCounter] = NULL;
        for(i=0,j=arrCounter-1;i<=j;i++,j--){
            if(arr[i]!=arr[j]){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            cout << counter << " " << arr << endl;
            break;
        }
        num1 = 0;
        for(j=arrCounter-1;j>=0;j--){
            num1 = (num1*10) + (arr[j] -48);
        }
        counter++;
    }
    }

	return 0;
}
