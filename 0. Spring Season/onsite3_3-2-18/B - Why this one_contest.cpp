#include<iostream>
#include<cstdio>
using namespace std;
#define msg(a,b) cout << a << " : " << b << endl;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};


int main(){
    string str;
    int n,m,dir,i,k,x,y,flag;
    dir = 0;
    x= 0,y=0,dir = 0;
    while(scanf("%d %d", &m , &n) == 2){
        flag = 1;
        x = 0, y=0,dir = 0;
        while(n--){
        //msg(x,y)
        cin>>str >> k;
        if(str == "MOVE"){
            for(i=1;i<=k;i++){
                x = x + dx[dir];
                y = y + dy[dir];
            }
        }else{
            if(k == 0){
                dir = dir -1;
                if(dir < 0 ){
                    dir = 3;
                }
            }else{
                dir = dir+1;
                if(dir > 3){
                    dir = 0;
                }
            }
        }

        if(x > m || y > m || x <0 || y < 0){
            flag = 0;
        }
        }
        if(flag == 0){
            cout << -1 << endl;
        }else{
            cout << x << " " << y << endl;
        }
    }
    return 0;
}
