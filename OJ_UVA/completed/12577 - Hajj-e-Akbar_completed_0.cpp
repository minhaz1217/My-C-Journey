#include<iostream>
using namespace std;
int main(){
    int caseCounter = 1;
    string str;
    for(;;){
        cin >> str;
        if(str == "*"){
            break;
        }
        if(str == "Hajj"){
            cout << "Case " << caseCounter++ <<": Hajj-e-Akbar" << endl;
        }else{

            cout << "Case " << caseCounter++ <<": Hajj-e-Asghar" << endl;
        }
    }
	return 0;
}
