#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    long long int foundClose, tc,i,j,counter;
    string str;
    char c;
    cin >> tc;
    while(tc--){
        cin >> str;
        counter = 0;
        foundClose = 0;
        stack<char>st;
        cout << str << endl;
        for(i=0;str[i];i++){
            c = str[i];
            if(c== '>' && foundClose == 0){
                break;
            }
            if(c == '<'){
                if(foundClose == 1){
                    break;
                }
                st.push(c);
            }else if(c=='>'){
                foundClose = 1;
                if(st.top() == '<'){
                    st.pop();
                    counter++;
                    if(st.empty()){
                        foundClose = 0;
                    }
                }else{
                    break;
                }
            }
        }
        msg(counter, i)
        cout << (counter*2) << endl;
    }

    return 0;
}
