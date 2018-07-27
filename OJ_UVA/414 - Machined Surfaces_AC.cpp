#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,i,currMin, ans, right, left;
    string str;
    while(1){
        cin >> n;
        if(n==0){
            break;
        }
        vector<int>vec;
        currMin = INT_MAX;
        cin.ignore();
        while(n--){
            getline(cin, str);
            //cin >> str;
            for(i=0;str[i];i++){

                if(str[i] == 'X'){
                    left = i;
                }else{
                    break;
                }
            }
            for(i=str.size()-1;i>=0;i--){
                if(str[i] == 'X'){
                    right = i;
                }else{
                    break;
                }
            }
            ans = right - left;
            ans--;
            if(ans < 0){
                ans = 0;
            }

            vec.push_back(ans);
            currMin = min(currMin, ans);
            //msg(ans, currMin)
            //msg2(ans, right, left)
        }
        ans = 0;
        //cc(currMin)
        if(currMin <= 0 && vec.size() > 1){
            for(i=0;i<vec.size();i++){
                //cc(vec[i])
                ans += vec[i];
            }
        }else{
            for(i=0;i<vec.size();i++){
                    //cc(vec[i])
                ans = ans + (vec[i] - currMin);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
