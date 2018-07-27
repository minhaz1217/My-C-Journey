#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    string str;
    char c[] = "11";
    vector<int> vec;
    map<string, int>mp;
    map<int,string>mp2;
    int n,i,counter=1,mm;
    cin >> n >> str;
    for(i=1;str[i];i++){
        c[0] = str[i-1];
        c[1] = str[i];
        //cc(c)
        vec.push_back(0);
        if(!mp[c]){
            mp[c] = counter++;
            vec.push_back(1);
            mp2[counter-1] = c;
        }else{
            vec[mp[c]]++;
        }

    }

    mm = INT_MIN;
    for(i=1;i<=counter;i++){
        if(vec[i] > mm){
            mm = i;
        }
    }
    cout << mp2[mm] << endl;

    return 0;
}
