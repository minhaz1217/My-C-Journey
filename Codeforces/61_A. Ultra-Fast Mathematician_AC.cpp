#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long i;
    string str1,str2;
    cin >> str1 >> str2;
    for(i=0;str1[i];i++){
        cout << ((str1[i] - '0') ^ (str2[i]-'0'));
    }
	return 0;
}
