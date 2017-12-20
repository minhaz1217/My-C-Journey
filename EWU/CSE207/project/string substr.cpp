#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    string str = "Hello my name is minhaz;";
    cout << str.substr(str.find("my")+2);
    cout << str[str.length()-1];


    return 0;
}
