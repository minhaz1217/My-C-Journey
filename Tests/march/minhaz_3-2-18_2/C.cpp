#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

class disjoint_set{
private:
    vector<int>p,rt;
public:
    disjoint_set(int n){
        p.assign(n,0);
        rt.assign(n,1);
        for(int i=0;i<n;i++){
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
    bool isSameSet(int x, int y){
        return findSet(x) == findSet(y);
    }
    void unionSet(int x,int y){
        if(!isSameSet(x,y)){
            int a,b;
            a = findSet(x);
            b = findSet(y);
            if(rt[a] > rt[b]){
                p[b] = a;
                rt[a]++;
                rt[b] = 0;
            }else{
                p[a] = b;
                rt[b]++;
                rt[a] = 0;
            }
        }
    }
    int findRt(int x){
        return rt[x];
    }
};


int main(){
    int n,p,u,v,i,sz,j,a,b,sum;
    vector<int>vec;
    set<int>st;
    cin >> n >> p;
    disjoint_set dj(n);
    while(p--){
        cin >> u >>v;
        if(!dj.isSameSet(u,v)){
            dj.unionSet(u,v);
        }
    }
    for(i=0;i<n;i++){
        st.insert(dj.findSet(i));
        //msg(dj.findSet(i), dj.findRt(dj.findSet(i)))
    }
    vector<int>vecc = vector<int>(st.begin(), st.end());
    sz = vecc.size();
    sum = 0;
    for(i=0;i<sz;i++){
        for(j=0;j<i;j++){
            a = dj.findRt(vecc[i]);
            //msg(a,i)
            b = dj.findRt(vecc[j]);
            //msg(b,j)
            sum = sum + a*b;
        }
    }
    cout << sum << endl;


    return 0;
}
