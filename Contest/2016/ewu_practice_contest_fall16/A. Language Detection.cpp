#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int caseCounter = 1;
    string str;
    string lan[] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};

    while(1){
        cin >> str;
        if(str == "#"){
            break;
        }

        if(str == lan[0] ){
            cout << "Case " << caseCounter++ << ": ENGLISH" << endl;
        }else if(str == lan[1] ){
            cout << "Case " << caseCounter++ << ": SPANISH" << endl;
        }else if(str == lan[2] ){
            cout << "Case " << caseCounter++ << ": GERMAN" << endl;
        }else if(str == lan[3] ){
            cout << "Case " << caseCounter++ << ": FRENCH" << endl;
        }else if(str == lan[4] ){
            cout << "Case " << caseCounter++ << ": ITALIAN" << endl;
        }else if(str == lan[5] ){
            cout << "Case " << caseCounter++ << ": RUSSIAN" << endl;
        }else{
            cout << "Case " << caseCounter++ << ": UNKNOWN" << endl;
        }
    }

	return 0;
}
