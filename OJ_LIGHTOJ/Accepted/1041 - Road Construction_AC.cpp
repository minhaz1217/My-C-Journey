#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


class disjoint_set{
private:
    vector<int>p, rt;
public:
    disjoint_set(int n){
        //cc(n)
        n++;
        p.assign(n+1,0);
        rt.assign(n+1,0);
        for(int i=0;i<=n;i++){
            p[i] = i;
        }
    }
    int findSet(int x){
        if(p[x] == x){
            return x;
        }else{
            p[x] = findSet(p[x]);
            return p[x];
        }
    }
    int isSameSet(int x, int y){
        return (findSet(x) == findSet(y));
    }
    int unionSet(int x,int y){
        int a,b;
        if(!isSameSet(x,y)){
            a = findSet(x);
            b = findSet(y);
            if(rt[a] > rt[b]){
                p[b] = a;
            }else{
                p[a] = b;
                if(rt[b] == rt[a]){
                    rt[b]++;
                }
            }
        }
    }


};

int main(){
    int a,tc,w,counter,u,v,i,cost,caseCounter =1;
    string str1,str2;
    pair<int, pair<int,int> >f;
    cin >> tc;
    while(tc--){
        cin >> a;
        vector< pair<int, pair<int,int> > >edges;
        map<string , int> mp;
        counter = 1;
        while(a--){
            cin >> str1 >> str2 >> w;
            //if(w){
            if(!mp[str1]){
                mp[str1] = counter++;
            }
            if(!mp[str2]){
                mp[str2] = counter++;
            }
            edges.push_back(make_pair(w, make_pair(mp[str1], mp[str2])));

            //}
        }
        //msg("SIZE", mp.size())
        sort(edges.begin(), edges.end());
        for(i=0;i<edges.size();i++){

            f = edges[i];
            u = f.second.first;
            v = f.second.second;
            w = f.first;
           // msg2(u,v,w)
        }
        cost = 0;
        disjoint_set dj(mp.size());
        for(i=0;i<edges.size();i++){
            f = edges[i];
            u = f.second.first;
            v = f.second.second;
            w = f.first;
            if(!dj.isSameSet(u,v)){
                dj.unionSet(u,v);
                cost += w;
            //msg2(u,v,w)
            }
        }
        counter = 0;
        for(i=1;i<=mp.size();i++){
            if(dj.findSet(i) == i){
                counter++;
            }
        }
        if(counter > 1){
        cout << "Case "<< caseCounter++ << ": Impossible" << endl;
        }else{
            cout << "Case "<< caseCounter++ << ": " << cost << endl;

        }




    }
    return 0;
}
