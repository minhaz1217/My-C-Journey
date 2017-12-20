#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {

    string str;
    long long int i,tc,temp,flag;
    map<string, long long int> myMap;
    //map<string, long int>::iterator it;
    cin >> tc;
    for(i=0;i<tc;i++){
        cin >> str >> temp;
        myMap[str] = temp;
    }


    for(;;){
        cin >> str;
        //cout << myMap[str] << endl;
        if(myMap[str]){
           cout << str << "=" << myMap[str] << endl;
        }else{
            cout << "Not found" << endl;

        }
        if(cin.eof()){
            break;
        }
        /*
        for(it = myMap.begin();it!=myMap.end();it++){
            if(it->first == str){
                cout << it ->first << "=" << it->second << endl;
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            cout << "Not found" << endl;
        }
        */

    }



    return 0;
}
