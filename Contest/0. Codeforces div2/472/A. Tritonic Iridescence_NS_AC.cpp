#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int n;
map<string, int>mp;
void dfs(string str, int pos){
    //cc(str)
    int flag, found,i;
    string temp;
    flag =1;
    found = 0;
    //msg(pos, str)
    for(i=pos;i<n;i++){
        if(str[i] == str[i-1]){
            if(str[i] != '?'){
                flag = 0;
                break;
            }

            //flag = 0;
            //break;
        }else if(str[i] == '?' || str[i-1] == '?'){
            found = 1;
        }
    }
    //cc(flag)
    //msg(flag, found)
    int cccc= 0;
    string arr[5];
    if(flag == 1 && found == 1){
        for(i=pos;i<n;i++){
            if(str[i] == '?'){
                temp = str;
                temp[i] = 'C';
                dfs(temp, i);
                temp[i] = 'M';
                dfs(temp,i);
                temp[i] = 'Y';
                dfs(temp,i);
            }
        }
    }else if(flag == 1 && found == 0){
        if(!mp[str] && str.size() >=1){
            flag = 1;
            for(i=1;i<n;i++){
                if(str[i]==str[i-1] || str[i] == '?'){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                mp[str] = 209;
                if(mp.size()>=2){
                    cout << "Yes" << endl;
                    exit(0);
                }
            }
        }
    }
}


int main(){
    string str;
    mp.clear();
    int possible,i,flag,subFound;
    cin >> n;
    cin >> str;
    possible = 1;

    if(n == 1 && str == "?"){
        cout << "Yes"<< endl;
        exit(0);
    }else if(n==1){
        cout << "No"<< endl;
        exit(0);
    }
    subFound = 0;
    for(i=1;i<n;i++){
        if(str[i] == str[i-1]){
            if(str[i] != '?'){
                possible = 0;
                break;
            }else{
                subFound =1;
            }
        }
    }

    if(possible == 1){
        if(subFound == 1){
            //cc("HELLO")
            //cc("1")
            cout << "Yes" << endl;
        }else{
            flag = 1;
            dfs(str,0);
            cout << "No"<<endl;
        }
    }else{
        flag= 0;
        cout << "No" << endl;
    }

    return 0;
}
