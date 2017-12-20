#include<iostream>
using namespace std;
int main(){
    string str;
    for(;;){
    	getline(cin,str);
        if(cin.eof()){
            break;
        }
        cout << str << endl;
    }
	return 0;
}
