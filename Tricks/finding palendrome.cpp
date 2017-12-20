///////////////////////////////////////////////////////////////
//check if a number is pelendrome or not. pelendrome means the digits are equal left to right.
//like 44544 is a pelendrome, 43544 is not.
///////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int checkPalendrome(int num1){
    int arrCounter=0, temp,i,j,flag = 0;
    char arr[20];
    temp = num1;
    while(temp!=0){
        arr[arrCounter++] = (temp%10) + 48;
        temp = temp/10;
    }
    arr[arrCounter] = NULL;
    for(i=0,j=arrCounter-1;i<=j;i++,j--){
        if(arr[i] != arr[j]){
            flag = 1; //not palendrome
            break;
        }
    }
    if(flag == 1){
        return 0;
    }else{
        return 1;
    }
}
int main(){
    int num1,arrCounter=0, temp,i,j,flag = 0;
    cout << checkPalendrome(11211);
    char arr[20];
    cin >> num1;
    temp = num1;
    while(temp!=0){
        arr[arrCounter++] = (temp%10) + 48;
        temp = temp/10;
    }
    arr[arrCounter] = NULL;
    for(i=0,j=arrCounter-1;i<=j;i++,j--){
        if(arr[i] != arr[j]){
                cout << "hi" << endl;
            flag = 1; //not palendrome
            break;
        }
    }
    if(flag == 1){
        cout << "The number is not palendrome" << endl;
    }else{
        cout << "The number is palendrome.";
    }
	return 0;
}
