#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 504
#define INF 500000
int weight[MX], mainWeight[MX];
int mat[MX][MX];

int main(){
    int tc,fnodes,ta=1, nodes,i,a,currNode, currWeight,k,j,u,v,w,ww,s,sum;
    string str;
    cin >> tc;
    while(tc--){
        cin>> fnodes >> nodes;
        //vector< pair<int,int> >mat[nodes+4];
        int fire[fnodes];
        for(i=0;i<fnodes;i++){
            cin >> a;
            fire[i] = a;
        }
        cin.ignore();

        for(i=1;i<=nodes;i++){
            for(j=1;j<=nodes;j++){
                mat[i][j] = INF;
            }
            mat[i][i] = 0;
        }
        while(1){
            getline(cin, str);
            if(str.length() <= 1){
                break;
            }
            stringstream ss(str);
            while(ss >> u >> v >> w){
                mat[u][v] = w;
                mat[v][u] = w;
                //mat[u].push_back(make_pair(v,w));
                //mat[v].push_back(make_pair(u,w));
            }

        }

        for(k=1;k<=nodes;k++){
            for(i=1;i<=nodes;i++){
                for(j=1;j<=nodes;j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        for(i=1;i<=nodes;i++){
            sum =0;
            for(j=1;j<=nodes;j++){
                sum += mat[i][j];
            }
            msg(i,sum)
        }







            msg(currNode, currWeight)
            if(ta>1){
                cout << endl;
            }
            ta++;
            cout << currNode << endl;


    }


    return 0;
}
