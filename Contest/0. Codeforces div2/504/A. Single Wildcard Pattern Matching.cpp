#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int i,a,b,flag, match,starPos;
    string str1, str2;
    cin >> a >> b;
    cin >> str1 >> str2;

    flag = 0;
    for(int i=0;str1[i];i++){
        if(str1[i] == '*'){
            starPos = i;
            flag = 1;
            break;
        }
    }
    match = 1;
    if(flag == 0){
        //cc("HI")
        if(str1 == str2){
            match = 1;
        }else{
            match = 0;
        }
    }else{
        string tStr1, tStr2,t2Str1,t2Str2;
        tStr1 = str1.substr(0, starPos);
        tStr2 = str2.substr(0,starPos);

        t2Str1 = str1.substr(starPos+1,str1.size()-starPos-1 );
        t2Str2 = str2.substr(tStr2.size(), str2.size() - tStr2.size());
        if(t2Str2.size() < t2Str1.size()){
            match = 0;
        }else{
            t2Str2 = t2Str2.substr(t2Str2.size() - t2Str1.size(), t2Str1.size());
            if(tStr1 == tStr2 && t2Str1 == t2Str2){
                match = 1;
            }else{
                match = 0;
            }
        }

        //msg(t2Str1, t2Str2)

            /*
            int i,j;
            for(i=t2Str1.size()-1, j=t2Str2.size()-1 ;i>=0&&j>=0;i--,j--){
                if(t2Str1[i] != t2Str2[j]){
                    cc("HI")
                    match = 0;
                    break;
                }
            }
            if(i!=-1){
                //cc(i)
                match = 0;
            }
            */

    }
    if(match == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
