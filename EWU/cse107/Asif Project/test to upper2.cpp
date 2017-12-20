#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string name = "john doe"; //or just get string from user...
for(int i = 0; i < name.size(); i++) {
    name.at(i) = toupper(name.at(i));
}
	return 0;
}
