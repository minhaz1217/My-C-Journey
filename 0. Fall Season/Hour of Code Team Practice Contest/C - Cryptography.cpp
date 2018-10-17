#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define MX 130
#define INF 90000000000


long long int mat[MX][MX];


int main(){

    long long int u,v,c,n,sum,flag;
    char a,b;
    string str1,str2;
    cin >> str1 >> str2;
    cin >> n;

    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            mat[i][j] = INF;
        }
        mat[i][i] = 0;
    }

    while(n--){
        cin >> a >> b >> c;
        u = (int)a;
        v = (int)b;
        mat[u][v] = min(mat[u][v], c);
        //mat[v][u] = min(mat[v][u], c);
    }
    for(int k=0;k<MX;k++){
        for(int i=0;i<MX;i++){
            for(int j=0;j<MX;j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
    }
    sum =0;
    flag = 0;
    for(int i=0;str1[i];i++){
        c = mat[str1[i]][str2[i]];
        if(c >= INF){
            flag = 1;
            break;
        }else{
            sum += mat[str1[i]][str2[i]];
        }

    }
    if(flag){
        cout << -1 << endl;
    }else{
        cout << sum << endl;
    }
    //cout << sum << endl;



    return 0;
}
