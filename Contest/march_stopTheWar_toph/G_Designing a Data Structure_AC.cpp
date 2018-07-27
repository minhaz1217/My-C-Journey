#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    deque<int> fl;
    deque<int>::iterator it;
    int a,n;
    string str1, str2;
    cin >> n;
    while(n--){
        cin >> str1 >> str2;
        if(str1 == "Insert"){
            cin >> a;
            if(str2 == "Front"){
                fl.push_front(a);
            }else{
                fl.push_back(a);
            }
        }else if(str1 == "Erase"){
            if(str2 == "Front"){
                fl.pop_front();
            }else{
                fl.pop_back();
            }
        }else{
            if(str2 == "Front"){
                cout << fl.front() << endl;
            }else if(str2 == "Back"){
                cout << fl.back() << endl;
            }else if(str2 == "Max"){
                it = max_element(fl.begin(), fl.end());
                cout << *it << endl;
            }else{
                it = min_element(fl.begin(), fl.end());
                cout << *it << endl;
            }
        }
    }
    return 0;
}
