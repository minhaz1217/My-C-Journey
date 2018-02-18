#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 24
int mat[MX][MX];
int visited[MX];
int main(){
    int i,j,a,b,u,w,qq,d,cost,n = 20,s, ll,caseCounter = 1;
    int myCounter = 0;
    while(cin >> ll){
        if(myCounter >=1){
            printf("\n");
        }
        myCounter++;
        printf("Test Set #%d\n", caseCounter++);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                mat[i][j] = 0;
            }
            visited[i] = 0;
        }
        for(i=1;i<=ll;i++){
            cin >> b;
            mat[1][b] = 1;
            mat[b][1] = 1;
        }

        for(i=2;i<=19;i++){
            cin >> a;
            while(a--){
                cin >> b;
                mat[i][b] = 1;
                mat[b][i] = 1;
            }
        }
/*
    cc("INTPUT ENDED")

    for(int pq=0;pq<21;pq++){
    for(int PQ=0;PQ<21;PQ++){
        printf("%2d ", mat[pq][PQ]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}
*/


        cin >> qq;
        while(qq--){
            cin >> s  >> d;
        queue<pair<int, int> >q;
            for(i=1;i<=n;i++){
                visited[i] = 0;
            }

            //swap(s,d);
            q.push(make_pair(s, 0));
            visited[s] = 1;
            while(!q.empty()){
                u = q.front().first;
                w = q.front().second;
                //msg(u,w)
                q.pop();
                if(u == d){
                    cost = w;
                    break;
                }


                for(i=1;i<=n;i++){
                    if(!visited[i] && mat[u][i]){
                        //msg2("Pushed ", i , u)
                       // msg2(u,i,w+1)
                        q.push(make_pair(i, w+1));
                        visited[i] = 1;
                    }
                }
            }
            printf("%2d to %2d: %d\n", s, d, cost);
        //cout << cost << endl;
        }
    }
    cout << endl;

    return 0;
}
