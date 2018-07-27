#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;
#define msg2(a, b, c ) cout << a << " : " << b << " : " << c << endl;


/*
    colors

    blue    1
    red     2
    black   3
    green   4
    white   5


*/
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int findCost(char dir, int m1, int m2){
    int cost;
    if(m1 == 0 && m2 == 1){ // goint e
        if(dir == 'e'){
            cost = 0;
        }else if(dir == 'n'){
            cost = 1;
        }else if(dir == 's'){
            cost = 1;
        }else{
            cost = 2;
        }
        dir = 'e';
    }else if(m1 == 0 && m2 == -1){ // going w
        if(dir == 'n'){
            cost = 1;
        }else if(dir == 'e'){
            cost = 2;
        }else if(dir == 's'){
            cost = 1;
        }else{
            cost = 0;
        }
        dir = 'w';
    }else if(m1 == -1 && m2 == 0){ // going n
        if(dir == 'n'){
            cost = 0;
        }else if(dir == 'e'){
            cost = 1;
        }else if(dir == 's'){
            cost = 2;
        }else{
            cost = 1;
        }
        dir = 'n';
    }else if(m1 == 1 && m2 == 0){ // going s
        if(dir == 'n'){
            cost = 2;
        }else if(dir == 'e'){
            cost = 1;
        }else if(dir == 's'){
            cost = 0;
        }else{
            cost = 1;
        }
        dir = 's';
    }
    return cost;
}

char findDir(int m1, int m2){
    char dir;
    if(m1 == 0 && m2 == 1){ // goint e
        dir = 'e';
    }else if(m1 == 0 && m2 == -1){ // going w
        dir = 'w';
    }else if(m1 == -1 && m2 == 0){ // going n
        dir = 'n';
    }else if(m1 == 1 && m2 == 0){ // going s
        dir = 's';
    }
    return dir;
}
struct car{
    int x,y;
    char dir;
    int color;
    int cost;
    car(int a,int b, char c, int d, int f){
        x = a;
        y = b;
        dir = c;
        color = d;
        cost = f;
    }
};
int main(){


    while(1){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0){
            break;
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%c", &c);
                mat[i][j] = c;
                if(c == 'S'){
                    sx = i;
                    sy = j;
                }else if(c == 'T'){
                    tx = i;
                    ty = j;
                }
                visited[i][j] = 0;
            }
        }
        queue<car>q;
        car mycar(sx,sy, 'n', 1, 0);
        visited[sx][sy] = 1;
        while(!q.empty()){
            car u = q.top();
            q.pop();
            ux = u.x;
            uy = u.y;
            udir = u.dir;
            ucolor = u.color;
            ucost = u.cost;
            for(i=0;i<4;i++){
                vx = ux + dx[i];
                vy = uy + dy[i];
                if( !(vx < 0 || vx > n || vy <0 || vy >m)){
                    if(mat[vx][vy] != '#'){
                        car newcar(vx,vy,findDir(vx,vy), findColor(ucolor), findCost(udir, ux,uy)+1);
                        q.push(newcar);
                    }
                }

            }



        }


    }





    return 0;
}
