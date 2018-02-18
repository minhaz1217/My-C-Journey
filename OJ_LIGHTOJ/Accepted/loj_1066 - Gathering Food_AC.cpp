/*
Minhazul Hayat Khan
EWU
Problem Name:1066 - Gathering Food
Problem Link: http://lightoj.com/volume_showproblem.php?problem=1066
Date : 9 / February / 2018
Comment: kind of easy but has a twist.
*/

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
char mat[12][12];
bool visited[12][12];
int dir = 4;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


int main(){
    int tc,n,i,j,found,imp,caseCounter = 1, counter,aposx,aposy,u,v,uu,vv, currFind,w,tx,ty,maxNum,s,d;
    int arr['Z'+3];
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        found = 0;
        maxNum = 'A';
        for(i=0;i<n;i++){
            scanf("%s", &mat[i]);
            for(j=0;mat[i][j];j++){
                if(mat[i][j] >= 'A' && mat[i][j] <= 'Z'){
                    if(mat[i][j] == 'A'){
                        aposx = i;
                        aposy=j;
                    }
                    maxNum = max(maxNum, (int)mat[i][j]);

                }
            }
        }

        for(i='A';i<='Z';i++){
            arr[i] = 0;
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }

        s = 'A';
        d = 'B';
        imp = 0;
        //msg(maxNum, d)
        map<pair<int,int> , pair<int,int> >mp;
        counter = 0;
        while(d <= maxNum){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        //check((char)maxNum)
            //msg(aposx,aposy)
            queue< pair<int, pair<int,int> > >q;
            q.push(make_pair(aposx, make_pair(aposy, 0)));
            visited[aposx][aposy] = 1;
            mat[aposx][aposy] = '.';
            found = 0;
            while(!q.empty()){
                u = q.front().first;
                v = q.front().second.first;
                w = q.front().second.second;
                //msg2(u,v,w)
                q.pop();
                if(mat[u][v] == d){
                    counter += w;
                    aposx = u;
                    aposy = v;
                    mat[u][v] = '.';
                    found = 1;
                    s = d;
                    d++;
                    break;
                }
                for(i=0;i<dir;i++){
                    uu = u + dx[i];
                    vv = v + dy[i];
                    if(!(uu < 0 || uu >= n || vv < 0 || vv >=n)){
                        if(!visited[uu][vv] && (mat[uu][vv] == '.' || mat[uu][vv] == d)){
                            q.push(make_pair(uu,make_pair(vv,w+1)));
                            visited[uu][vv] = 1;
                            mp[make_pair(uu,vv)] = make_pair(u,v);
                        }
                    }
                }
            }
            if(found == 0){
                imp = 1;
                break;
            }


        }
        if(imp == 1){
            printf("Case %d: Impossible\n", caseCounter++);
        }else{
            printf("Case %d: %d\n", caseCounter++, counter);
        }



    }

    return 0;
}
