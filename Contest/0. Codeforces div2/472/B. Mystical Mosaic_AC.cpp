#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    int i,j,n,m,k,flag = 1,u,v;

    cin >> n >> m;
    char mat[n+4][m+4];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }

    vector<int>rr,ccc;
    rr.assign(n+4,0);
    ccc.assign(m+4,0);


    set<int>row,col;
    set<int>:: iterator p,q;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j] == '#'){
                if(rr[i] == 0){
                    rr[i] = 1;
                    row.insert(i);
                }
                if(ccc[j] == 0){
                    ccc[j] = 1;
                    col.insert(j);
                }
                for(k=i;k<n;k++){
                    if(mat[k][j] == '#'){
                        if(rr[k] == 0){
                            rr[k] = 1;
                            row.insert(k);

                        }
                    }
                }
            }
        }
            //msg(row.size(), col.size())
            //cc("HI")
            for(p= row.begin();p!=row.end();p++){
                for(q = col.begin();q!=col.end();q++){
                    u = *p;
                    v = *q;
                    //msg(u,v)
                    if(mat[u][v] == '#'){
                        mat[u][v] = '.';
                    }else{
                        flag = 0;
                        //msg2(u,v,mat[u][v])
                        break;
                    }
                }
            }
            row.clear();
            col.clear();
    }
    for(i=0;i<n && flag;i++){
        for(j=0;j<m;j++){
            if(mat[i][j] == '#'){
                flag = 0;
                break;
            }
        }
    }
    if(flag == 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }


    return 0;
}
