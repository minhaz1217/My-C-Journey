#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 1000

typedef int ttt;
ttt p[MX];

ttt unionFind(ttt x){
    //cout << "HI" << endl;
    if(p[x] == x){
        return x;
    }
    return p[x] = unionFind(p[x]);

}

ttt unionSet(ttt u, ttt v){
    p[unionFind(v)] = unionFind(u);
    /*
    if(unionFind(u) == unionFind(v)){
        cout << "They are already same" << endl;
    }else{
        cout << "Made " << u << " parent of " << v << endl;
        p[v] = u;
    }
    */
}
int main(){
    cout << "HI" << endl;
    ttt i;
    for(i=0;i<MX;i++){
        p[i] = -1;
    }

    unionSet(3,1);
    unionSet(5,4);
    unionSet(5,6);
    /*
    p[2] = 3;
    p[1] = 3;
    p[4] = 5;
    p[6] = 5;
    */
    check(unionFind(2))
    /*
    unionSet(3,1);
    unionSet(5,4);
    unionSet(5,6);
    */
    for(i=0;i<10;i++){
        cout << p[i] << " ";
    }
    cout << endl;


    return 0;
}
