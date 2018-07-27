#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

bool checkPalin(string st){
    string rst = st;
    reverse(rst.begin(), rst.end());
    if(rst == st){
        return 1;
    }else{
        return 0;
    }
}
int k;
int checkSubStr(string str){
    //msg("REC", str)
    int i,sz = str.size(),j;
    string tempStr;
    if(checkPalin(str)){
        return 0;
    }
    for(i=k;i<sz;i++){
        for(j=0;j+i-1<sz;j++){
            tempStr = str.substr(j, i);
            //cc(tempStr)
            if(checkPalin(tempStr)){
                return 0;
            }else{
                return checkSubStr(tempStr);
            }
            //counter++;
        }
    }
    return 1;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){

        int i,j,sz,nonPalin=0,a;
        string str,tempStr,mTemp;
        int palin=0 , counter=0;
        cin >> k >> str;
        sz = str.size();

        if(checkPalin(str)){
            palin++;
        }else{
            nonPalin++;
        }
        for(i=2;i<sz;i++){
            for(j=0;j+i-1<sz;j++){
                tempStr = str.substr(j, i);
                a = checkSubStr(tempStr);
                counter+=a;
                //msg2(i, tempStr,a)
            }
        }
        //cout << counter+sz << endl;
        msg(counter, (sz*(sz+1)/2 ));
    }

    return 0;
}
