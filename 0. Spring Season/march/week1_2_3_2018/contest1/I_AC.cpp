
//https://www.codechef.com/problems/COMPILER
/*
critical cases
<<<<>>>><<
// output 8
<<>><<
//output 4
<<>><<>
// output 4
*/

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int tc,i,counter,flag;
    string str;
    char c;
    cin >> tc;
    while(tc--){
        stack<char>st;
        cin >> str;
        counter = 0;
        for(i=0;str[i];i++){
            c = str[i];
            if(c == '<'){
                st.push(c);
            }else if(c=='>'){
                //calc--;
                if(st.empty()){
                    //counter = 0;
                    break;
                }else if(st.size() == 1){
                    counter = i+1;
                    st.pop();
                }else{
                    st.pop();
                }
            }
        }
        if(i==str.size() && !st.empty()){
            //counter = 0;
        }
        //if(st.empty()){
            cout << counter << endl;
        //}else{
        //    cout << 0 << endl;
        //}
    }
    return 0;
}
