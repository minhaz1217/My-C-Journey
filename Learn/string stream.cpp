#include<iostream>
#include<sstream>
using namespace std;
int main(){

    string str= "Hello My Name is minhaz.";
    int a = 500;
    string temp;
    stringstream ss(str);

    while(1){
        ss >> temp;
        cout << temp << endl;
        if(ss.eof()){
            break;
        }

    }
    stringstream ss1;
    ss1 << a;
    ss1 >> temp ;
    cout << ss1 << endl;
    cout << temp<< endl;
    //cout << a << endl;




    return 0;
}
