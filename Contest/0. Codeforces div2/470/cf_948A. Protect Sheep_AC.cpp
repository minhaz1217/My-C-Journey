#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 501

char mat[MX][MX];
int dir = 4;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main(){
    int r,c,i,j,k,possible,xx,yy;
    cin >> r >> c;
    //scanf("%d%d", &r, &c);
    //msg(r,c)
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> mat[i][j];
            //scanf("%c", &mat[i][j]);
        }
    }
    possible = 1;
    for(i=0;i<r && possible;i++){
        for(j=0;j<c && possible;j++){
            if(mat[i][j] == 'S'){
                for(k = 0;k<dir && possible;k++){
                    xx = i + dx[k];
                    yy = j + dy[k];

                    if( !(xx <0 || xx>=r || yy <0 || yy >=c) ){
                        if(mat[xx][yy] == 'W'){
                            possible = 0;
                            //cc("HI")
                            break;
                        }
                    }
                }
            }
        }
    }
    if(possible == 1){
    cout << "Yes" << endl;
    for(i=0;i<r && possible;i++){
        for(j=0;j<c && possible;j++){
            if(mat[i][j] == 'W'){
                for(k = 0;k<dir && possible;k++){
                    xx = i + dx[k];
                    yy = j + dy[k];
                    if( !(xx <0 || xx>=r || yy <0 || yy >=c) ){
                        //msg(xx,yy)
                        if(mat[xx][yy] == '.'){
                            //msg(mat[xx][yy],"HI")
                            mat[xx][yy] = 'D';
                            //cc(mat[xx][yy])
                        }
                    }
                }
            }
        }
    }

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<< mat[i][j];
        }
        cout << endl;
    }

    }else{
        cout << "No" << endl;
    }


    return 0;
}
