#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 104
#define INF 1000000.00
double mat[MX][MX];


class UnionFind{
private:
    int i,a,b;
    vector<int>p,ranks;
public:
    UnionFind(int n){
        ranks.assign(n,0);
        p.assign(n,0);
        for(i=0;i<n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        //cc(x)
        int ans = (p[x] == x? x : p[x] = findSet(p[x]));
        //cc(ans)
        return ans;
    }
    int isSameSet(int x,int y){
        return findSet(x) == findSet(y);
    }
    int unionSet(int x,int y){
        if(!isSameSet(x,y)){
            a = findSet(x);
            b = findSet(y);
            if(ranks[b] > ranks[a]){
                p[a] = b;
            }else{
                p[b] = a;
                if(ranks[a] == ranks[b]){
                    ranks[a]++;
                }
            }
        }
    }
};

double calculate(double x1, double y1, double x2, double y2){
    return ( sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))  );

}


int main(){
    double x,y,w,ux,uy,vx,vy,mm;
    int ta = 1,i,j,k,n,tc,u,v;

    cin >> tc;
    while(tc--){
        vector<pair<double,double> >vec;
        vector<pair<double, pair<int,int> > >mat;
        cin >> n;
        for(i=0;i<n;i++){
            cin >> x >> y;
            //mp[make_pair(x,y)] = nodes++;
            vec.push_back(make_pair(x,y));
        }
        /*
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                mat[i][j] = INF;
            }
            mat[i][i] = 0;
        }
        */
        for(i=0;i<n;i++){
            ux = vec[i].first;
            uy = vec[i].second;
            for(j=0;j<vec.size();j++){
              vx = vec[j].first;
              vy = vec[j].second;
              w = calculate(ux,uy,vx,vy);
              mat.push_back(make_pair(w, make_pair(i,j)));
            }
        }
        sort(mat.begin(), mat.end());

        double mst_cost = 0;
        UnionFind uf(n);
        int e = mat.size();
        //msg(e,mat[0].first)
        for(i=0;i<e;i++){
            pair<double, pair<int,int> >f = mat[i];
            u = f.second.first;
            v = f.second.second;
            w = f.first;
           // msg2(u,v,w)
            if(!uf.isSameSet(u,v)){
                mst_cost += w;
                //cc("HO")
                uf.unionSet(u,v);
            }
        }

        if(ta>1){
            cout << endl;
        }
        ta++;
        printf("%.2lf\n", mst_cost);

    }
    return 0;
}
