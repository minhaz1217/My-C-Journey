/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10010
Date : 23 / February / 2019
Comment: The word can be match only by going in a single direction of the 8 directions., somewhat easy problem
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string mat[55];

int dir = 8;
int dx[] = {0,0,-1,1, 1, -1, 1, -1};
int dy[] = {1,-1,0,0, 1,-1, -1, 1};
int main(){

    int tc,n,m,mark,u,v,pos,ansx,counter= 1, ansy,ux,uy,qq,found,inFound,vx,vy,pr,pc;
    string str;
    mark=1;
    cin >> tc;
    while(tc--){
        if(counter>1){
            cout << endl;
        }
        counter++;
        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> mat[i];
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] >='A' && mat[i][j] <='Z'){
                    mat[i][j] = mat[i][j] -'A' + 'a';
                }
            }
        }
        cin >> qq;
        while(qq--){
            cin >> str;
            for(int i=0;i<str.size();i++){
                if(str[i] >='A' && str[i] <='Z'){
                    str[i] = str[i] -'A' + 'a';
                }
            }
            //msg("STRING", str)
            found = 0;
            for(int r=0;r<n &&!found;r++){
                for(int c= 0;c<m && !found ;c++){
                    if(mat[r][c] == str[0]){
                        for(int l=0;l<8 && !found ;l++){
                            pr = r;
                            pc = c;
                            inFound = 1;
                            for(int i=1;i<str.size();i++){
                                vx = pr+dx[l];
                                vy = pc + dy[l];
                                if( !(vx< 0 || vy<0 || vx>=n || vy>=m) ){
                                    if(mat[vx][vy] == str[i]){
                                        pr = vx;
                                        pc = vy;
                                    }else{
                                        inFound = 0;
                                        break;
                                    }
                                }else{
                                    inFound = 0;
                                    break;
                                }
                            }
                            if(inFound == 1){
                                cout << r+1<< " "<< c+1 << endl;
                                found = 1;
                            }
                        }

                    }
                }
            }
        }
    }
    return 0;
}
