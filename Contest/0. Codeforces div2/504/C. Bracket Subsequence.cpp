#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,k,counter, i,nextCounter;
    string str;
    char c[20005],tempc[20005];
    cin >> n >> k;
    cin >> str;
    stack<pair<char, int> > st;
    pair<char, int>f;
    counter = 0;
    for(i=0;str[i];i++){
        c[counter++] = str[i];
    }
    c[counter] = '\0';
    while(n!= k){
        //msg(n,k)
        nextCounter = counter;
        counter = 0;
        strcpy(tempc,c);
        for(i=0;i<nextCounter;i++){
            if(tempc[i] != '0'){
                c[counter++] = tempc[i];
            }
        }
        c[counter] = '\0';
        //msg(tempc, c)
        for(long long int i=0;i<counter;i++){
            if(c[i] == '('){
                st.push(make_pair(c[i],i));
                //vec[i] = i;
            }else{

                f= st.top();
                st.pop();
                if(n>k){
                    if(f.second+1 == i){
                        c[i] = '0';
                        c[f.second] = '0';
                        n-=2;
                        if(n ==k){
                            break;
                        }
                    }
                }
            }
        }
    }
        nextCounter = counter;
        counter = 0;
        strcpy(tempc,c);
        for(i=0;i<nextCounter;i++){
            if(tempc[i] != '0'){
                c[counter++] = tempc[i];
            }
        }
        c[counter] = '\0';
    cout << c << endl;
    cout << endl;

    return 0;
}
