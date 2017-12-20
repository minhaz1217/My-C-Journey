#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int tc, i;
    string str;
    cin >> tc;
    cin.ignore();
    while(tc--){
        getline(cin, str);
        for(i=0;str[i];i++){
            if(i%2 == 0){
                cout << str[i];
            }
        }
        cout << " ";
        for(i=1;str[i];i++){
            if(i%2 != 0){
                cout << str[i];
            }

        }
        cout << endl;
    }
    return 0;
}
