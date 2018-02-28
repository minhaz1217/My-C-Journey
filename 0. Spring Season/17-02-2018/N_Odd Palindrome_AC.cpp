#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int checkPalin(string str){
    int i,j,flag;
    i = 0;
    j = str.size()-1;
    flag =1;
    while(i<=j){
        if(str[i] != str[j]){
            return -1;
            break;
        }
        i++,j--;
    }
    return str.size();
}


int main(){
    int i,ssize,j,oddFlag,k;
    string str,str1,mark,str2;
    cin >> str;
    mark = str;
    char temp;
    //cout << str1 << endl;
    oddFlag = 1;
    for(i=0;str[i] && oddFlag;i++){

        if(mark[i] == '0'){
            continue;
        }

        str1 = str;
        //str1.push_back(str[i]);
        //mark[j] = '0';
        temp = str[i];

        ssize = str.size();
        for(j=i+1;j<ssize;j++){
            //str1.push_back(str[j]);
            if(str[j] == temp && mark[j] != '0'){
                mark[j] = '0';
                //cc(str1)
                str1 = str.substr(i,j);
                k = checkPalin(str1);
                if(k > 0 && k%2 == 0){
                    oddFlag = 0;
                    break;
                }
            }
            //cout << str1 << endl;
        }
    }

    if(oddFlag == 1){
        cout << "Odd." << endl;
    }else{
        cout << "Or not." << endl;
    }


    return 0;
}
