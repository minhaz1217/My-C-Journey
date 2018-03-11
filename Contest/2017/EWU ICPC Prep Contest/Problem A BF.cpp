#include<iostream>
#include<math.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string str;
    char test[] = "HELLO";
    char ch[5];
    int cancelPoint,temp,a,j,len,i,invalidCheck = 0,totalCounter = 0;
    while(1){
        //cin >> str;
        if(cin.eof()){
            break;
        }
        len = str.length();
        //cout << len << endl;
        invalidCheck =0;
        for(i=1;str[i];i++){
            if(str[i-1] > str[i]){
                invalidCheck = 1;
                break;
            }
        }
        if(invalidCheck == 1){
            cout << "Invalid" << endl;
        }
        totalCounter += str[len-1]-96;
        cout << "Total Value is " << totalCounter << endl;
        //for(i=1;i<pow(26,len+1);i++){//infinite loop

        cancelPoint = 0;
        for(i=1;i<=27;i++){// ae
            temp = i;
            //test = i + 96;
            if(i >26){
                if((temp/26) >= (temp % 26)){
                    cancelPoint++;
                }else{
                    temp = i + cancelPoint;
                    test[0] = (temp / 26) + 96;
                    temp =  (temp % 26);
                    test[1] = (temp % 26) + 96;
                    test[2] = NULL;
                }
            }
            //cout << test << endl;
            totalCounter = i;
        }
        cout << "Invalid: " << cancelPoint << endl;
        cout << "Final " << test << endl;


    }

	return 0;
}
