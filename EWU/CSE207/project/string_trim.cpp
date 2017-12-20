#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
void trim(string &st){
    int counter = 0,i;
    for(i=0;st[i];i++){
        if(st[i]!=' '){
            break;
        }else{
            counter++;
        }
    }
    st.erase(0,counter);
    counter = 0;
    for(i=st.length();st[i] != ' ';i--){
        counter++;
    }
    st.erase(counter+1, counter);
}
int main(){
    string str = "       HI       ";
    cout << str << endl;
    trim(str);
    cout << str << endl;;

    return 0;
}
