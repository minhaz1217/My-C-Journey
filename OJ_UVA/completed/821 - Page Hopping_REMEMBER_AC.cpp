//https://vjudge.net/user/yongwhan_google
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 110
#define INF 5000000
int cost[MX][MX];
int main(){
    vector<pair<int,int> >vec;
    set<int>st;
    int a,b,u,v,i,j,k,n,caseCounter=1;
    double sum=0,counter = 0;
    while(scanf("%d %d", &u, &v)){
            counter = 0;
        //msg(u,v)
        if(!u&&!v){
            if(vec.empty()){
                return 0;
            }
            map<int,int>mp;
           // msg("ST size", st.size())
            //msg("Vec size", vec.size())
            vector<int>mat(st.begin(),st.end());
            n = st.size();
            for(i=0;i<n;i++){
                mp[mat[i]] = i;
                //msg(mat[i], i)
            }
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    cost[i][j] = INF;
                }
                cost[i][i] = 0;
            }
            for(i=0;i<vec.size();i++){
                u = mp[vec[i].first];
                v = mp[vec[i].second];
                cost[u][v] = 1;
                //cost[v][u] = 1;
            }


            for(k=0;k<n;k++){
                for(i=0;i<n;i++){
                    for(j=0;j<n;j++){
                        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                    }
                }
            }
            sum = 0;
            counter = 0;
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(i!=j){
                        sum+= cost[i][j];
                        counter++;
                    }
                }
            }
            printf("Case %d: average length between pages = %.3lf clicks\n", caseCounter++, sum/counter);
            st.clear();
            vec.clear();
            n = 0;
            //cout << sum << endl;





        }else{
            vec.push_back({u-1,v-1});
            st.insert(u-1);
            st.insert(v-1);
        }
    }

    return 0;
}
