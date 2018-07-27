#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,m,i,j,currVal, flag,s;
    char c;
    scanf("%d%d", &n, &m);
    //cin >> n >> m;
    int mat[n][m],lamp[m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%c", &c);
            //cin >> c;
            if(c == '1'){
                mat[i][j] = 1;
            }else{
                mat[i][j] = 0;
            }
        }
    }
    currVal = 0;
    for(i=0;i<m;i++){
        lamp[i] = currVal;
    }
    for(s = 0;s<n;s++){
        currVal++;
        for(i=0;i<n;i++){
            if(i == s){
                continue;
            }
            for(j=0;j<m;j++){
                if(mat[i][j] == 1){
                    lamp[j] = currVal;
                }
            }
        }
        flag = 1;
        for(i=0;i<m;i++){
            if(lamp[i] != currVal){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    if(flag == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}
