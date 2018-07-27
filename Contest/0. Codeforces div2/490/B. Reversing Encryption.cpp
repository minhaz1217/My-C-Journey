#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,i;
    string str,str1,str2;
    vector<int>vec;
    cin >> n >> str;

    for(i=n;i>1;i--){
        if(n%i == 0){
            vec.push_back(i);
        }
    }
    sort(vec.begin(), vec.end());

    for(i=0;i<vec.size();i++){
        str1 = str.substr(0,vec[i]);
        str2 = str.substr(vec[i], n-1);
        //msg(str1,str2)
        reverse(str1.begin(), str1.end());
        str = str1+str2;
        //cout << str1 + str2 << endl;
        //str.substr(0, vec[i]);
        //cc(str.substr(0, vec[i]))
    }
    cout << str << endl;


    return 0;
}
