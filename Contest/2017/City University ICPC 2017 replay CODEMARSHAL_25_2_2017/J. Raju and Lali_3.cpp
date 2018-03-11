#include<iostream>
#include<stdio.h>
#include<sstream>

using namespace std;
int isVowel(char ch){
    int flag=0,i;
    char a[12]={'a','e','i','o','u','A','E','I','O','U','Y','y'};
    for(i=0;i<12;i++){
        if(ch == a[i]){
            flag = 1;
            break;
        }
    }
    return flag;
}

void outputWord(string str){
        long long i,posStart=0,posEnd = str.length()-1;
        for(i=0;str[i];i++){
            if(!isVowel(str[i])){
                break;
            }
        }
        posStart = i;
        for(i=str.length()-1;i>=0;i--){
            if(!isVowel(str[i])){
                break;
            }
        }
        posEnd = i;
        if(posStart > 0){
            for(i=0;i<posStart;i++){
                cout << str[i];
            }

        }
        for(i=posStart;i<=posEnd;i++){
            if(!isVowel(str[i])){
                cout << str[i];
            }
        }
        if(posEnd > posStart){
            for(i=posEnd+1;i<str.length();i++){
                cout << str[i];
            }
        }
}
int main(){
    int  tc,flag,posStart, posEnd,i,j;
    string str1,str2;
    cin >> tc;
    cin.ignore();
    while(tc--){
        getline(cin , str1);
        stringstream ss(str1);
        while(1){
            ss >> str2;
            outputWord(str2);
            if(ss.eof()){
                break;
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
