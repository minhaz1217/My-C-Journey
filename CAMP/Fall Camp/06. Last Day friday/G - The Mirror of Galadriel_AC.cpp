#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

string stringRev(string str){
    string st = str;
    int counter = 0;
    for(int i=str.length()-1;i>=0;i--){
        st[counter++] = str[i];
    }
    return st;
}

int main(){
    int i,tc,j,k,l,counter,flag;
    string str;

    map<string, bool> mp;
    vector<string> v;
    cin >> tc;
    //tc = 1;
    while(tc--){
        mp.clear();
        v.clear();
        cin >> str;
        //str = "aba";
        for(i=1;i<=str.length();i++){
            for(j=0;str[j];j++){
                string str2(str, j,i);
                if(!mp[str2]){
                    mp[str2] = 1;
                    v.push_back(str2);
                    //cout << str2 << endl;
                }
            }
        }
        //for(i=0;i<v.size();i++){c(v[i])}
        for(i=0;i<v.size();i++){

            flag = 1;
            string str3 = stringRev(v[i]);
            if(!mp[str3]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }




    return 0;
}
