#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    vector<int>vec;
    int a,b,n,i,temp,sz,ans,counter;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a==1){
            vec.push_back(b);
        }else if(a == 2){
            temp = b;
            vector<int>::iterator it;
            sz = vec.size();
            it = find(vec.begin(), vec.end(), b);
            if(it == vec.end()){
                cout << "Sorry" << endl;
            }else{
                counter = 0;
                for(i=sz;i>=0;i--){
                    if(vec[i] == b){
                        vec[i] =0;
                        counter++;
                        break;
                    }else if(vec[i]!=0){
                        vec[i] = 0;
                        counter++;
                    }

                }
                ans = counter;
                cout << ans << endl;
            }
        }
    }


    return 0;
}
