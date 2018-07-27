#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b  << " : " << c << endl;

int main(){
    long long int a, p,q,curr,i,round;
    char c;
    map<long long int, int>mp;
    cin >> p >> q;
    curr = 1;
    for(i=1;i<=q;i++){
        cin >> c;
        if(curr > p){
            curr = 1;
            round++;

        }
        if(c == 'N'){
            if(!mp[curr]){
                cout << curr << endl;
                mp[curr] = round;
        curr++;
            }else{
                if(mp[curr] <round){
                    cout << curr << endl;
                    mp[curr] = round;
        curr++;
                }else{
                    while(1){
                        curr++;
                        if(!mp[curr]){
                            cout << curr << endl;
                            mp[curr] = round;
        curr++;
                            break;
                        }else{
                            if(mp[curr] == round){
                                continue;
                            }else{
                                cout << curr << endl;
        curr++;
                                mp[curr] = round;
                                break;
                            }
                        }
                    }
                }
            }
        }else{
            cin >> a;
            cout << a << endl;
            mp[a] = round;
        }
    }

    return 0;
}
