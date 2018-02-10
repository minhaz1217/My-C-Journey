#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


#define MX 2000
int v[MX];
vector<int> p;
vector<int> dv[MX+4];
int sieve(){
    int i,j;
    for(i=0;i<MX;i++){
        v[i] = 0;
    }
    int sq = sqrt(MX) + 1;
    for(i=2;i< sq;i++){
        if(v[i] == 0){
            for(j=i;i*j<MX;j++){
                v[i*j] = 1;
            }
        }
    }
    for(i=2;i<MX;i++){
        if(v[i] == 0){
            p.push_back(i);
            //check(i)
        }
    }
}
int generateDiv(){
    int i,j;
    for(i= 1;i<MX;i++){
        for(j=0;p[j]<i && j<p.size();j++){
            //msg(i, p[j])
            if(i%p[j] == 0){
                //msg(i,p[j])
                dv[i].push_back(p[j]);
            }
        }
    }
}

int main(){
    sieve();
    generateDiv();
    int visited[MX],tc,u,w,target, s,i,t,k, caseCounter = 1;

    cin >> tc;

    while(tc--){

        queue<pair<int, int> >q;
        cin >> s >> t;

        for(i=s;i<=t+10;i++){
            visited[i] = 0;
        }
        q.push(make_pair(s,0));
        visited[s] = 1;
        target = INT_MAX;
        while(!q.empty()){
            u = q.front().first;
            w = q.front().second;
            q.pop();
            if(u == t){
                target = min(w,target);
                //break;
            }

            for(i=0;i<dv[u].size();i++){
                k = u + dv[u][i];
                if(k <= t && visited[k] == 0){
                   // msg(u,k)
                    q.push(make_pair(k, w+1));
                    visited[k] = 1;
                }
            }
        }
        //check(target)

        if(target == INT_MAX){
            target = -1;
        }
        cout << "Case "<< caseCounter++ << ": " << target << endl;


    }





    return 0;
}
