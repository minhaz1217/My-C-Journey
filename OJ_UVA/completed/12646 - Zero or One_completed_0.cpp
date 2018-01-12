#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    for(;;){
        cin >> a >> b >> c;
        if(cin.eof()){
            break;
        }
        if(a==b && b==c){
            cout << "*" << endl;
        }else if(a!=b && a!= c){
            cout << "A" << endl;
        }else if(b!=a && b!=c){
            cout << "B" << endl;
        }else if(c!=a && c!=b){
            cout << "C" << endl;
        }

    }

	return 0;
}
