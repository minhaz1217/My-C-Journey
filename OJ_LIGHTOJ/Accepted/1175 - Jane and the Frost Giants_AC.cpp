#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 203
int dir = 4;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1, 0, 0};
char mat[MX][MX];
char visited[MX][MX];
int main(){
    int tc,r,c,uu,vv,u,v,fu,fv, fx,fy, mylastx, mylasty, jaynex,jayney,i,j,curr, cnt, w,fw,caseCounter = 1,fcount, mround,currf,scount,jreached;
    char cc;

    cin >> tc;
    while(tc--){
        queue<pair<int, pair<int,int> > >q;
        queue<pair<int, pair<int, int > > > fire;
        cin >> r >> c;
        scount = 0;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cin >> cc;
                visited[i][j] = 0;
                mat[i][j] = cc;
                if(cc == 'F'){
                    fire.push(make_pair(i,make_pair(j,0)));
                    mylastx = i;
                    mylasty = j;
                }else if(cc == 'J'){
                    jaynex = i;
                    jayney = j;
                }else if(cc == '#'){
                    scount++;
                }
            }
        }
        scount = r*c - scount;
        mround = 0;
        currf = fire.size();
        //msg2(currf, scount, mround)
        jreached = 0;
        cnt = INT_MAX;
        q.push(make_pair(jaynex, make_pair(jayney, 0)));
        visited[jaynex][jayney] = 1;
        while(currf < scount && !jreached && !q.empty()){
        //msg2(currf, scount, mround)
        while(!q.empty()){
            u = q.front().first;
            v = q.front().second.first;
            w = q.front().second.second;
            if(w > mround){
                break;
            }
            q.pop();
            if(mat[u][v] == 'F'){
                continue;
            }else if(u ==0 || v == 0 || u == r-1 || v == c-1){
                cnt = min(cnt, w);
                jreached = 1;
                break;
            }

            for(i=0;i<dir;i++){
                uu = u + dx[i];
                vv = v + dy[i];
                if(!(uu<0 || uu >= r || vv < 0 || vv>=c)){
                    if(mat[uu][vv] != 'F' && mat[uu][vv] != '#' && !visited[uu][vv]){
                        q.push(make_pair(uu, make_pair(vv, w+1)));
                        mat[uu][vv] = 'J';
                        visited[uu][vv] = 1;
                    }
                }

            }
        }
        while(!fire.empty()){
            fu = fire.front().first;
            fv = fire.front().second.first;
            fw = fire.front().second.second;
            if(fw > mround){
                break;
            }
            fire.pop();
            for(j=0;j<dir;j++){
                uu = fu + dx[j];
                vv = fv + dy[j];
                if(!(uu <0 || uu >= r || vv <0 || vv >=c )){
                    if(mat[uu][vv] != 'F' && mat[uu][vv] != '#'){
                        mat[uu][vv] = 'F';
                        fire.push(make_pair(uu,make_pair(vv,fw+1)));
                        currf++;
                    }
                }
            }
        }
        mround++;
        //currf += fire.size();
        }
        if(cnt == INT_MAX){
            cout << "Case "<< caseCounter++ << ": IMPOSSIBLE" << endl;

        }else{
            cout << "Case "<< caseCounter++ << ": "<< cnt+1 << endl;
        }
    }


    return 0;
}
