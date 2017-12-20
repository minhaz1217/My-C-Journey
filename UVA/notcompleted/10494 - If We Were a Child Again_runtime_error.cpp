#include<iostream>
using namespace std;
int main(){
    long long int a,b;
    char ch;
    for(;;){
        cin >> a >> ch >>b;
        if(cin.eof()){
            break;
        }
        switch(ch){
            case '/':
                cout << a/b << endl;
                break;
            case '%':
                cout << a%b << endl;
                break;
        }
    }
	return 0;
}
