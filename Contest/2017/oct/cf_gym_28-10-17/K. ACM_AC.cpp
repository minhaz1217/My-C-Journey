#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    string str;
    int k;
    cin >> str;
    k = str.find("ACM");
    if(k>=0 && k< str.length()){
        cout << "Fun!" << endl;
    }else{
        cout << "boring..." << endl;
    }

    return 0;
}
