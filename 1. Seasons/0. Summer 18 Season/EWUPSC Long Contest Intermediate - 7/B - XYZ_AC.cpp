#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;


vector<long long int>visited,mat[504],p;
int flag;
void dfs(int s){
    //msg("HI FLAG", flag)
    int v;
    if(flag == 1){
        flag = 1;
        return;
    }
    //msg2("GOT", s, mat[s].size())
    /*
    for(int i=0;i<5;i++){
        cout << visited[i] << " ";
    }
    cout << endl;
    */
    visited[s] = 1;
    for(int i=0;i<mat[s].size();i++){
        v = mat[s][i];
        //msg(s,v)
        if(visited[v] == 0){
            //msg2(s,v,visited[v])
            //msg2("SENDING", v, s)
            p[v] = s;
            dfs(v);
            //visited[v] = 1;
        }else if(visited[v] == 1 && p[s] != v){
            //msg("FOUND", v)
            flag = 1;
            return;
        }
    }
    visited[s] = 2;
}


int main(){
    long long int tc,nodes = 1,caseCounter = 1;
    cin >> tc;
    while(tc--){
        long long int n,m, a,b,u,v,xCrom, yCrom, iCrom,counter;
        map<long long int, long long int> mp;
        cin >> n >> m;
        vector<long long int>inout;
        inout.assign(n+4,0);
        for(int i=1;i<nodes;i++){
            mat[i].clear();
        }

        nodes = 1;
        for(int i=0;i<m;i++){
            cin >> a >> b;
            if(!mp[a]){
                mp[a] = nodes++;
            }
            if(!mp[b]){
                mp[b] = nodes++;
            }
            a = mp[a];
            b = mp[b];
            inout[a]++;
            inout[b]++;
            mat[a].push_back(b);
            mat[b].push_back(a);
        }
        /*
        for(int i=1;i<nodes;i++){
            cout << i << " -> ";
            for(int j=0;j<mat[i].size();j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        */


        xCrom = 0;
        yCrom = 0;
        iCrom = 0;
        counter = 0;
        for(int i=1;i<nodes;i++){
            if(inout[i] == 4){
                xCrom = i;
                counter++;
            }else if(inout[i] == 3){
                yCrom = i;
                counter++;
            }else if(inout[i] == 2){
                iCrom = i;
            }else if(inout[i] > 4 || inout[i] == 0){
                counter = 20;
            }
        }
        visited.assign(n+4,0);
        p.assign(n+4,-1);
        //visited[1] = 1;
        flag = 0;
        dfs(1);
        //msg("FLAG", flag)
        //msg3(xCrom, yCrom,iCrom, counter)
        //cc(flag)
        cout << "Case " << caseCounter++ << ": ";
        if(flag == 1 || counter > 1){
            cout << "NotValid" << endl;
        }else{
            if(xCrom > 0 && yCrom == 0){
                cout << "X" << endl;
            }else if(yCrom > 0 && xCrom == 0){
                cout << "Y" << endl;
            }else if(iCrom >0){
                cout << "I" << endl;
            }else{
                //cc("HI")
                cout << "NotValid" << endl;
            }
        }
    }

    return 0;
}
