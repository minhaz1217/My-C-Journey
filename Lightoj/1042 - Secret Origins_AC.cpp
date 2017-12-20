#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long tc,i,j,a,currNew,caseCounter=1;
    string str1, str2;
    cin >> tc;
    while(tc--){
        cin >> a;
        bitset<32> b(a);
        currNew = 10000000000;
        str1 = b.to_string();
        for(i=str1.length()-1;i>=0;i--){
            if(str1[i] == '1'){
                str1[i] = '0';
                for(j=str1.length()-1;j>=0;j--){
                    if(str1[j] == '0'){
                        str1[j] = '1';
                        //cout << str1 << endl;
                        bitset<32>c(str1);
                        //cout << c.to_ulong() << endl;
                        if(c.to_ulong() >a){
                            currNew = currNew < c.to_ulong()? currNew : c.to_ulong();
                            break;
                        }
                        str1[j] = '0';
                    }
                }
            }
        }
        cout << "Case "<< caseCounter++ << ": " << currNew << endl;

        //cout << currNew << endl;


    }

    return 0;
}
