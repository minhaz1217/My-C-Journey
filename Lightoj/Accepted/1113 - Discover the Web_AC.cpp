#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    string str1,str2, ss,current;
    int caseCounter = 1;
    int tc;

    cin >> tc;
    while(tc--){
        stack<string> ft;
        stack<string> bc;
        current = "http://www.lightoj.com/";
        //bc.push("http://www.lightoj.com/");
        cout << "Case "<< caseCounter++ << ":" << endl;

        while(1){
        cin >> str1;
        if(str1== "QUIT"){
            break;
        }else if(str1 == "VISIT"){
            cin >> str2;
            while(!ft.empty()){
                ft.pop();
            }
            bc.push(current);
            current = str2;
            cout << current << endl;
        }else if(str1 == "BACK"){

            if(bc.empty()){
                cout << "Ignored" << endl;
            }else{
                ft.push(current);
                current = bc.top();
                bc.pop();
                cout << current << endl;

            }
        }else if(str1 == "FORWARD"){
            if(ft.empty()){
                cout << "Ignored" << endl;
            }else{
                bc.push(current);
                current = ft.top();
                ft.pop();
                cout << current << endl;
            }
        }
        }

    }



    return 0;
}
