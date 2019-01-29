#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    int counter= 0,found = 0;
    string str="";
    stack<char>st;
    cin >> str;
    st.push(str[0]);
    for(int i=1;str[i];i++){
        //msg2(str[i], st.top(), st.size())
        if(!st.empty()){
            if(st.top() == str[i]){
                st.pop();
                counter++;
            }else{
                st.push(str[i]);
            }
        }else{
            st.push(str[i]);
        }

    }
    //cc(counter)
    if(counter %2 == 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}
