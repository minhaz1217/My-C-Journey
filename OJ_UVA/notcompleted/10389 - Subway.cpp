#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 220
#define INF 500.00
double mat[MX][MX];
double weight[MX];


double calculate(double x1, double y1 , double x2, double y2){
        double ans = sqrt( ((x2 - x1)*(x2-x1)) + ((y2-y1)*(y2-y1))  );
        double x = x2-x1, y = y2-y1;
        ans = sqrt((x*x + y*y));
        //msg(x,y)
        //cc(y*y)
        //printf("from (%lf,%lf) to (%lf, %lf) is %lf\n", x1,y1,x2,y2, ans);


        return ans;
}

int main(){
    double tc, a,b,s1,s2,h1,h2,nodes,dist,walking = 10000/60,ww,w, train = 40000/60,last1,last2,u1,u2;
    string str;
    int ta=1,i,j,na,nb,home,school,u,v;
    pair<double,int>f;
    cin >> tc;
    while(tc--){
        vector<pair<int, int> >sub;
        vector<pair<int, int> > vec;
        map<pair<int,int> , int>mp;
        for(i=0;i<MX;i++){
            for(j=0;j<MX;j++){
                mat[i][j] = INF;
            }
            weight[i] = INF;
            mat[i][i] = 0;
        }
        nodes = 1;
        cin >> h1 >> h2 >> s1 >> s2;
//        point1 = make_pair(h1,h2);
        //point2 = make_pair(s1,s2);
        mp[make_pair(h1,h2)] = nodes++;
        mp[make_pair(s1,s2)] = nodes++;
        vec.push_back(make_pair(s1,s2));
        vec.push_back(make_pair(h1,h2));
        dist = calculate(s1,s2,h1,h2) / walking;
        //msg("DISTANCE WALK",dist)
        home = mp[make_pair(h1,h2)];
        school = mp[make_pair(s1,s2)];
        mat[home][school] = dist;
        mat[school][home] = dist;
        cin.ignore();
        while(1){
            getline(cin, str);
            if(str.size() <= 1){
                break;
            }
            //cc(str)
            stringstream ss(str);
            vector<pair<int,int> >sub;
            while(ss >> a >> b){

                if(a == -1 && b == -1){
                    //empty q and put them in vector
                    for(i=0;i<sub.size();i++){
                        //vec.push_back(sub[i]);
                    }
                    break;
                }
                if(!mp[make_pair(a,b)]){
                    mp[make_pair(a,b)] = nodes++;
                   // msg2(a,b, nodes-1)
                }
                if( !(last1 == -1 && last2 == -1) ){
                    na = mp[make_pair(a,b)];

                    for(i=0;i<vec.size();i++){
                        u1 = vec[i].first;
                        u2 = vec[i].second;
                        dist = calculate(u1,u2, a,b) / walking;
                        nb = mp[make_pair(u1,u2)];
                        //msg("DIST1: ", dist)
                        //msg2(na,nb, dist)
                        mat[na][nb] = min(mat[na][nb], dist);
                        mat[nb][na] = min(mat[nb][na], dist);
                     }

                     for(i=0;i<sub.size();i++){
                        u1 = sub[i].first;
                        u2 = sub[i].second;
                        dist = calculate(u1,u2, a,b) / train;
                        nb = mp[make_pair(u1,u2)];
                        //msg("DIST2: ", dist)
                        mat[na][nb] = min(mat[na][nb], dist);
                        mat[nb][na] = min(mat[nb][na], dist);
                     }
                    sub.push_back(make_pair(a,b));
                    //vec.push_back(make_pair(a,b));
                    //vec.push_back(m);
                }
            }
                //cc("HI2")
            //msg(a, b)
        }
        home = mp[make_pair(h1,h2)];
        school = mp[make_pair(s1,s2)];
       //msg("NODES", nodes)
       //msg(home, school)
/*
for(int pq=0;pq<nodes;pq++){
    for(int PQ=0;PQ<nodes;PQ++){
        printf("%3.2lf ", mat[pq][PQ]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}
*/

        priority_queue< pair<double,int>,  vector<pair<double,int> >, greater<pair<double,int> > >pq;
        //priority_queue<pair<double,int> >pq;
        pq.push(make_pair(0.00, home));
        weight[home] = 0.00;
        while(!pq.empty()){
            f = pq.top();
            w = f.first;
            u = f.second;
            //msg2("HI", w,u)
            pq.pop();
            for(i=1;i<nodes;i++){
                v = i;
                ww = mat[u][i];
                //msg2(u,v,ww)
                if(weight[v] > weight[u] + ww){
                    weight[v] = weight[u] + ww;
                    pq.push(make_pair(weight[v], v));
                }
            }
        }
        /*
for(int pq=0;pq<nodes;pq++){
    for(int PQ=0;PQ<nodes;PQ++){
        printf("%3.2lf ", mat[pq][PQ]);
        //cout << mat[i][j] << " ";
    }
    cout << endl;
}
*/
        if(ta>1){
            cout << endl;
        }
        ta++;
        //msg(weight[mp[make_pair(s1,s2)]], (int)weight[mp[make_pair(s1,s2)]])
        cout << round(weight[school]) << endl;

    }




    return 0;
}
