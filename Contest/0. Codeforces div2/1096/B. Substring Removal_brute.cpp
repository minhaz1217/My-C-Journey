#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int n,counter;
    string str;
    cin >> n >> str;
    map<char, int>mp;
    counter = 0;
    for(int i=0;str[i];i++){
        for(int j=i;str[j];j++){
            mp.clear();
            for(int k=0;str[k];k++){
                if( !(k>=i &&k<=j) ){
                    if(!mp[str[k]]){
                        mp[str[k]] = 1;
                    }
                }
            }
            if(mp.size() == 1){
                //msg(i,j)
                counter++;
            }
        }
    }
    msg("C", counter+1)
    return 0;
}
