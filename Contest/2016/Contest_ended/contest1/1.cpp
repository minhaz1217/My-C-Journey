#include<iostream>
using namespace std;
int main(){
    int a,arrCounter = 0,i,j;
    string str;

    cin >> a;
    cin.ignore();
    double arr[a],wei1,wei2;
    for(i=0;i<a;i++){
        wei1 = 0;
        wei2 = 0;
        getline(cin , str);
        cout << str;
        //
        for(j=0;str[j];j++);
        if(j>=1 && j<=4){
            wei1 = str[0] - 48;
        }else if(j>4 && j<=8){
            wei1 = str[0] - 48;
            wei2 = str[4] - 48;
        }
        arr[arrCounter] = (wei1 * .5) + (wei2 * .05);
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << "Case "<< i+1 << ": "<< arr[i]<< endl;
    }
	return 0;
}
