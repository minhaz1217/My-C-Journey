#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    string str;
    cin>> str;

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "Lower cased: " << str << endl;
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    cout << "Upper cased: " << str << endl;

    return 0;
}
