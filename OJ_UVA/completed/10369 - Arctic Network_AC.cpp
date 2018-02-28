#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;



struct pt{
    double a,b;
    pt(double aa, double bb){
        a = aa;
        b = bb;
    }
};
double calculate(pt b, pt a){
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

int main(){
    double tc,n,m,a,b,cost,sz,i,j,d,u,v,w,counter;
    scanf("%lf", &tc);
    while(tc--){
        scanf("%lf%lf", &n, &m);

        disjoint_set dj(m);
        vector<pt>point;
        vector<pair<double, pair<double, double> > > edges;
        for(i=0;i<m;i++){
            scanf("%lf%lf", &a, &b);
            point.push_back(pt(a,b));
            for(j=0;j<i;j++){
                d = calculate(point[i], point[j]);
                edges.push_back(make_pair(d, make_pair(i,j)));
            }
        }
        sort(edges.begin(),edges.end());
        sz = edges.size();
        cost = 0.00;
        counter = 0;
        cost = INT_MIN;
        for(i=0;i<sz;i++){
            u = edges[i].second.first;
            v = edges[i].second.second;
            w = edges[i].first;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
                cost = max(cost, w);
                counter++;
               // msg2(u,v,w)
            }
            if(counter == m-n){
                break;
            }
        }
        printf("%.2lf\n",cost);
    }

    return 0;
}
