#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 2004;
int main(){
    int e,i,b,s,qq,maxCount, currCount, maxDay,a,u,w,v,currDay;
    cin >> e;
    vector<int>mat[e];
    for(i=0;i<e;i++){
        cin >> a;
        //cc(a);
        while(a--){
            cin >> b;
            //cc(b);
            mat[i].push_back(b);
            //mat[b].push_back(i);
            //msg(i,b)
            //mat[i][b] = 1;
            //mat[b][i] = 1;
        }
    }
        cin >> qq;
        //msg("Q", qq)
        while(qq--){
            cin >> s;
            int visited[e] = {0};
            queue<pair<int , int> >q;
            for(i=0;i<e;i++){
                visited[i] = 0;
            }
            q.push(make_pair(s,0));
            visited[s] = 1;
            maxCount = INT_MIN;
            currCount = 0;
            currDay = 0;
            while(!q.empty()){
                u = q.front().first;
                w = q.front().second;
                if(w== currDay){
                    //msg2("FOUND", u,w)
                    currCount++;
                }else{
                //msg2("RESET", currCount, currDay)

                    currCount = 1;
                    currDay++;
                }
                    if(u != s && currCount > maxCount){
                        maxCount = currCount;
                        maxDay = currDay;
                    }




                q.pop();
                //currCount = 0;
                for(i=0;i<mat[u].size();i++){
                    v= mat[u][i];
                    //msg("I", v)
                    if(!visited[v]){
                        q.push(make_pair(v,w+1));
                        //msg2(w, v, u)
                        visited[v] = 1;
                    }
                }
            }
            //msg2("RES", maxCount, maxDay)
            if(maxCount == INT_MIN){
                cout << 0 << endl;
            }else{
                cout << maxCount << " " << maxDay << endl;
            }
        }


    return 0;
}
