#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    int n;
    char ch;
    vector<int> a;
    int commas = 0,i;
    while(1){
        ss >> n >> ch;
        a.push_back(n);
        if(ss.eof()){
            break;
        }
    }
    /*
    for(i=0;str[i];i++){
        if(str[i] == ','){
            commas++;
         }
    }
    for(i=0;i<commas;i++){
        ss >> n >> ch;
        a.push_back(n);
    }
    ss >> n;
    a.push_back(n);
    */
    return a;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);


    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }


    return 0;
}
