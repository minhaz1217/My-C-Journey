#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 504
#define INF 500000
int weight[MX], mainWeight[MX], temp[MX];


int main(){
    int tc,fnodes,ta=1, nodes,i,a,currNode, currWeight,k,j,u,v,w,ww,s, sum = 0,currSum = 0;
    string str;
    cin >> tc;
    while(tc--){
        cin>> fnodes >> nodes;
        vector< pair<int,int> >mat[nodes+4];
        int fire[fnodes];
        for(i=0;i<fnodes;i++){
            cin >> a;
            fire[i] = a;
        }
        cin.ignore();
        while(1){
            getline(cin, str);
            if(str.length() <= 1){
                break;
            }
            stringstream ss(str);
            while(ss >> u >> v >> w){
                mat[u].push_back(make_pair(v,w));
                mat[v].push_back(make_pair(u,w));
            }

        }

            currSum = INT_MAX;
for(i=1;i<=nodes;i++){
    weight[i] = INF;
}
            priority_queue<pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > >pq;
            for(k = 0;k<fnodes;k++){
                s = fire[k];
                pq.push(make_pair(0, s));
                weight[s] = 0;
            }
            while(!pq.empty()){
                u = pq.top().second;
                w = pq.top().first;
                pq.pop();
                if(weight[u] < w){
                    continue;
                }
                for(i=0;i<mat[u].size();i++){
                    v = mat[u][i].first;
                    ww = mat[u][i].second;
                    if(weight[v] > weight[u] + ww){
                        weight[v] = weight[u] + ww;
                        pq.push(make_pair(weight[v], v));
                    }
                }
            }
            cc("HI")

                    sum = 0;
                    for(j=1;j<=nodes;j++){
                        sum += weight[j];
                    }
                    msg("KK", sum)
            for(k=1;k<=nodes;k++){
                if(weight[k] == 0){
                    msg("HI", k)
                    continue;
                }else{
                    //cc("HELLO")
                    for(j=1;j<=nodes;j++){
                        temp[j] = weight[j];
                    }
                    s = k;
                    //priority_queue<pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > >pq;
                    pq.push(make_pair(0, s));
                    temp[s] = 0;
                    while(!pq.empty()){
                        u = pq.top().second;
                        w = pq.top().first;
                        pq.pop();
                        if(temp[u] < w){
                            continue;
                        }
                        for(i=0;i<mat[u].size();i++){
                            v = mat[u][i].first;
                            ww = mat[u][i].second;
                            if(temp[v] > temp[u] + ww){
                                temp[v] = temp[u] + ww;
                                pq.push(make_pair(temp[v], v));
                            }
                        }
                    }
                    sum = 0;
                    for(j=1;j<=nodes;j++){
                        sum += temp[j];
                    }
                    msg(k, sum)
                    if(sum < currSum){
                        currNode = k;
                        currSum = sum;
                    }
                }
            }
            msg(currNode, currSum)
            if(ta>1){
                cout << endl;
            }
            ta++;
            cout << currNode << endl;


    }


    return 0;
}
