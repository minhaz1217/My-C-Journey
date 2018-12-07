#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 200
int visited[MX];
int main(){
    string str,str1,str2,u,temp;
    int counter = 1,tCounter = 0;
    int tc,i,pairs,cost,w,takingPairs = 0;
    char c;
    cin >> tc;
    str = "hihello";
    cin.ignore();
    tc++;
    while(tc--){
        map<string, int>mp;
        counter = 0;
        takingPairs = 0;
        if(str != "hihello"){
            mp[str] = counter++;
        }

        if(tCounter > 1){
            cout << endl;
        }
        while(1){
            getline(cin, str);
            if(str.length() <=0){
                //cc("HI")
                tCounter++;
                break;
            }
            //msg(str.length(), str)
            if(str == "*"){
                takingPairs = 1;
                continue;
            }
            pairs = 0;
            for(i=0;str[i];i++){
                if(str[i] == ' '){
                    pairs = 1;
                }
            }
            if(takingPairs == 1 && pairs == 0){
                takingPairs = 0;
            }else if(pairs == 1){
                stringstream ss(str);
                ss >> str1 >> str2;
                //msg(str1, str2)
                //msg("SI", mp.size())
                for(i=1;i<=counter;i++){
                    visited[i] = 0;
                }
                queue<pair< string, int > >q;
                q.push(make_pair(str1, 0));
                visited[mp[str1]] = 1;
                while(!q.empty()){
                    u = q.front().first;
                    w = q.front().second;
                    //msg2("HI",u,w)
                    if(u == str2){
                        cost = w;
                        break;
                    }
                    q.pop();
                    temp = u;
                    for(i=0;u[i];i++){
                        temp = u;
                        for(c = 'a';c<='z';c++){
                            temp[i] = c;
                            //msg2("CHECKING", temp, mp[temp])
                            if(mp[temp] && !visited[mp[temp]] ){
                                q.push(make_pair(temp, w+1));
                                visited[mp[temp]] = 1;
                                break;
                            }
                        }
                    }
                }
                cout << str1 << " " << str2 << " " << cost << endl;
            }else{
                if(!mp[str]){
                    //msg2("INSERTED", str, mp[str])
                    mp[str] = counter++;
                }
            }
        }
    }

    return 0;
}
