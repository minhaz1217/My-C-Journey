#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string str;
    long long tc,counter = 0;
    cin >> tc;
    cin.ignore();
    while(tc--){

        getline(cin, str);
        //cin >> str;
        //cout << str << endl;

        for(int i =0;str[i];i++){
            if(str[i] == ' '){
                counter++;
            }
        }
        counter++;
        cout << counter << endl;
        counter = 0;

    }
	return 0;
}
