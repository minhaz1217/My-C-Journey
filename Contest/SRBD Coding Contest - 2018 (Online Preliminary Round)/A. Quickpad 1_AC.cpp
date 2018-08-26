//https://www.hackerrank.com/contests/srbd-coding-contest-2018-online-preliminary-round/challenges/quickpad-1/problem
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
bool isChar(char myChar){
    if( myChar >= 0 && myChar<='9'){
        return 0;
    }
    return 1;
}
int main(){
    long long int n,q,a,cursor;
    string c;
    string str;
    cin >> n >> str;
    vector<char>vec;
    for(int i=0;str[i];i++){
        vec.push_back(str[i]);
    }
    //msg(a,str)
    cursor = vec.size();
    for(int i=0;i<n;i++){
        cin >> q;
        if(q == 1){
            cin >> c;
            if(c.size() == 2 && c[1] == 'b'){
                if(cursor>0){
                    vec.erase(vec.begin()+cursor-1, vec.begin()+cursor);
                    cursor--;
                }
            }else{
                //msg2("INSERT",c, cursor)

                vec.insert(vec.begin()+cursor, c[0]);
                cursor++;
            }
        }else{
            cin >> a;
            cursor = a;
        }
    }
    for(int i= 0;i<vec.size();i++){
        cout << vec[i];
    }
    cout << endl;

    return 0;
}
