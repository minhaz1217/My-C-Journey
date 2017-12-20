#include<iostream>
using namespace std;
int main(){
    int sum = 0,j,num, sum2 =0,cpyCounter = 0,a;
    string str,cpy;
    cin >> a;
    int arr[a],arrCounter = 0;
    cin.ignore();
    while(a!=0){
        sum = 0;
        sum2 = 0;
        cpyCounter=0;
        getline(cin, str);
        cpy = str;
        for(j=0;str[j];j++){
            if(str[j] != ' '){
                cpy[cpyCounter] = str[j];
                cpyCounter++;
            }
        }
        cpy[cpyCounter] = '\0';
        str = cpy;
        for(j=0;str[j];j++){
            if(str[j] != ' '){
                num = (str[j] - 48) * 2;
                if(j%2==0){
                    if(num>=10){
                        sum += num / 10;
                        sum += num %10;
                    }else{
                        sum += num;
                    }
                }else{
                    sum2 += str[j] - 48;
                }
            }
        }
        if((sum + sum2) % 10 == 0){
            arr[arrCounter] = 1;
        }else{
            arr[arrCounter] = 0;
        }
        arrCounter++;
        a--;
    }
    for(j=0;j<arrCounter;j++){
        if(arr[j] == 0){
            cout << "Invalid" << endl;
        }else{
            cout << "Valid" << endl;
        }
    }




	return 0;
	// 0 = 48
	// 9 = 57
}
