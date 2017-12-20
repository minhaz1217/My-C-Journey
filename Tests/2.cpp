#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string str,word;
    cin >> str;
    //str.erase(str.length()-1,str.length()-1);
    //cout << str;
    word  = str.substr(str.size() -2 , str.size());
    cout << word;
	return 0;
}
