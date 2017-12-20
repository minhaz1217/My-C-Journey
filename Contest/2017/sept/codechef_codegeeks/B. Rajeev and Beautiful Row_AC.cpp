#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,left, right,i;
    char prev;
    string str;


    cin >> tc;
    while(tc--){
        cin >> str;
        prev = str[0];
        left = 0;
        right = 0;
        //check(prev)
        if(prev == 'L'){
            left++;
        }else{
            right++;
        }
        //msg(left, right)
        for(i=0;str[i];i++){
            if(str[i] != prev){
                if(prev == 'L'){
                    right++;
                }else{
                    left++;
                }
                //check(i)
                prev = str[i];
            }
        }
        //msg(left, right)
        cout << min(left, right) << endl;
    }

    return 0;
}
