#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 1000
int visited[MX];
int p[MX];
int main(){
    int found, s,d,u,v,i,n,nodes,temp,tc = 1;
    string str1,str2;
    while(cin >> n){
        if(tc >1){
            cout << endl;
        }
        tc++;
        map<string, int> mp;
        vector<int>mat[MX];
        map<int, string>mp2;
        nodes = 1;
        for(i=1;i<=n;i++){
            cin >> str1 >> str2;
            if(!mp[str1]){
                mp[str1] = nodes;
                //mp[str1] = make_pair(nodes++, str1);
                mp2[nodes] = str1;
                nodes++;
            }
            if(!mp[str2]){
                mp[str2] = nodes;
                mp2[nodes] = str2;
                nodes++;
                //mp[str2] = make_pair(nodes++, str2);
            }


            mat[mp[str1]].push_back(mp[str2]);
            mat[mp[str2]].push_back(mp[str1]);
            //mat[mp[str1].first].push_back(mp[str2].first);
            //mat[mp[str2].first].push_back(mp[str1].first);
        }
        cin >> str1 >> str2;
        if(!mp[str1] || !mp[str2]){
            found = 0;
        }else{
            s = mp[str1];
            d = mp[str2];

            for(i=0;i<=nodes;i++){
                visited[i] = 0;
                p[i] = -1;
            }
            queue<int>q;
            q.push(s);
            visited[s] = 1;
            found = 0;
            while(!q.empty()){
                u = q.front();
                q.pop();
                if(u==d){
                    found = 1;
                    break;
                }
                for(i=0;i<mat[u].size();i++){
                    v = mat[u][i];
                    if(!visited[v]){
                        q.push(v);
                        p[v] = u;
                        visited[v] = 1;
                    }
                }
            }

        }

        if(found == 0){
            cout << "No route" << endl;
        }else{
            stack<int>st;
            temp = d;
            st.push(d);
            while(temp!=s){
                st.push(p[temp]);
                temp = p[temp];
            }
            string temp;
            //msg("HI", st.size())
            temp = mp2[st.top()];
            st.pop();
            while(!st.empty()){
                cout << temp << " " << mp2[st.top()] << endl;
                temp = mp2[st.top()];
                st.pop();
                /*
                cout << mp2[st.top()] << " ";
                st.pop();
                cout << mp2[st.top()] << endl;
                st.pop();*/
            }
        }

    }

    return 0;
}
