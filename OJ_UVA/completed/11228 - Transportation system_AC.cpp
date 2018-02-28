#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 1004
int mat[MX][MX];


struct city{
    int a,b;
    city(int aa, int bb){
        a = aa;
        b = bb;
    }
};
double calculate(city b, city a){
    return sqrt((a.a-b.a)*(a.a-b.a) + (a.b-b.b)*(a.b-b.b));
}


class disjoint_set{
private:
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n, 0);
        rt.assign(n, 0);
        for(int i=0;i<n;i++){
            p[i] = i ;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            return p[x] = findSet(p[x]);
        }
    }
    bool isSameSet(int x,int y){
        return findSet(x) == findSet(y);
    }
    void unionSet(int x, int y){
        if(!isSameSet(x,y)){
            int a,b;
            a = findSet(x);
            b = findSet(y);
            if(rt[a] > rt[b]){
                p[b] = a;
            }else{
                p[a] = b;
                if(rt[a] == rt[b]){
                    rt[b]++;
                }
            }
        }
    }
};
bool operator<(city a, city b){
    return a.a<b.a;
}
pair<double, pair<int , int> >mpp(int u, int v, double w){
    return (make_pair(w, make_pair(u,v)));
}
int main(){
    int caseCounter = 1,tc,n,r,a,b,i,j,states,x,k,u,v,sz,mapKey = 1,l,sz1, sz2,kk;
    double cityCost, regionCost,w,d;
    scanf("%d", &tc);
    while(tc--){
        vector<city>cities;
        map<city, int>mp;
        vector<int>myState;
        cities.push_back(city(0,0));
        mapKey = 1;
        scanf("%d%d", &n, &r);
        vector<city>st[n+1];
        disjoint_set state(n+1);
        for(i=1;i<=n;i++){
            scanf("%d%d", &a, &b);
            mp[city(a,b)] = mapKey++;
            cities.push_back(city(a,b));
            for(j=1;j<=i;j++){
                d = calculate(cities[i], cities[j]);
                if(d <= r && d!=0){

                    state.unionSet(i,j);
                }
            }
        }
        states = 0;
        for(i=1;i<=n;i++){
            x = state.findSet(i);
            //msg(i,x)
            st[x].push_back(cities[i]);
            if(x == i){
                myState.push_back(x);
                states++;
            }
        }
        //msg("STATES", states)
        cityCost = 0;
        vector<pair<double, pair<int , int> > > edRegion;
        for(k=0;k<=n;k++){
            //k = myState[kk];
            vector<pair<double, pair<int , int> > > ed;
            sz = st[k].size();
            disjoint_set dj(sz);
            for(i=0;i<sz;i++){
                for(j=0;j<i;j++){
                    u = i;
                    v = j;
                    w = calculate(st[k][i], st[k][j]);
                    ed.push_back(mpp(u,v,w));
                }
            }
            sort(ed.begin(), ed.end());
            for(i=0;i<ed.size();i++){
                u = ed[i].second.first;
                v = ed[i].second.second;
                w = ed[i].first;
                if(!dj.isSameSet(u,v)){
                    dj.unionSet(u,v);
                    cityCost += w;
                }
            }
            for(l=0;l<k;l++){
                if(l!=k){
                    sz1 = st[k].size();
                    sz2 = st[l].size();
                    for(i=0;i<sz1;i++){
                        for(j=0;j<sz2;j++){
                            u = k;
                            v = l;
                            w = calculate(st[k][i], st[l][j]);
                            //msg2(u,v,w)
                            edRegion.push_back(mpp(u,v,w));
                        }
                    }
                }
            }
        }
       // msg("CITY COST", cityCost)
        disjoint_set djj(n+1);
        regionCost = 0;
        //cc(edRegion.size())
        sort(edRegion.begin(), edRegion.end());
        for(i=0;i<edRegion.size();i++){
            u = edRegion[i].second.first;
            v = edRegion[i].second.second;
            w = edRegion[i].first;
            if(!djj.isSameSet(u,v)){
                djj.unionSet(u,v);
                //msg2(u,v,w)
                regionCost += w;

            }
        }
        //msg("Reg cost", regionCost)

        printf("Case #%d: %d %d %d\n", caseCounter++, states, (int)round(cityCost), (int)round(regionCost));
    }

    return 0;
}
