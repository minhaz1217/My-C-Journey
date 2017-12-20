#include<iostream>
#include<stdio.h>

#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
using namespace std;

int main(){
    int  tc,flag,posStart, posEnd,i,j;
    string str;
    char a[12]={'a','e','i','o','u','y','A','E','I','O','U','Y'};

    cin >> tc;

    while(tc--){
        cin >> str;

        for(i=0;str[i];i++){
            flag = 0;
            for(j =0;j < 12; j++){
                if(str[i] == a[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag != 1){
                posStart = i;
                break;
            }
        }
        for(i=str.length()-1;i>=0;i--){
            flag = 0;
            for(j =0 ; j < 12; j++){
                if(str[i] == a[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag != 1){
                posEnd = i;
                break;
            }
        }


        for(i=0;i<=posStart;i++){
            cout << str[i];
        }
        for(i=posStart+1;i<=posEnd;i++){
            flag = 0;
            for(j =0 ; j < 12; j++){
                if(str[i] == a[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag != 1){
                cout << str[i];
            }

        }
        for(i=posEnd+1;str[i];i++){
            cout << str[i];
        }
        cout << endl;
    }

    return 0;
}
