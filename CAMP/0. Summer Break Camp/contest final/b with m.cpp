#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;

int checkPalin(string str){
    int i,j;
        for(i=0, j= str.length()-1;str[i];i++,j--){
            if(str[i] != str[j]){
                return 0;
                break;
            }
        }
        return 1;
}

int main(){
    int tc,flag, i;
    map<string, int> bl;
    string str,str2,str3;
    cin >> tc;
    while(tc--){
        cin >> str;
        flag =0;
        for(i=0;str[i];i++){
            str3 = str;
            str2 = str3.erase(i, 1);
            if(bl[str2] == NULL){
                bl[str2] = checkPalin(str2);
            }
            if(bl[str2] == 1){
                flag = 1;
                break;
            }

            /*
            if(checkPalin(str2) == 1){
                flag = 1;
                break;
                //palin found
            }
            */
        }
        if(flag == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }

    return 0;
}
