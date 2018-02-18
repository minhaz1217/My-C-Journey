#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    int n,m,s, counter,i,j,x,y;
    char c,curr;
    while(1){
        cin >> n >> m >> s;
        if(n == 0 && m == 0 && s == 0){
            break;
        }
        char arr[n][m];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){

                cin >> c;
                arr[i][j] = c;
                if(c == 'N' || c == 'S' || c == 'L' || c == 'O'){
                    //curr = c;
                    if(c == 'L'){
                        curr = 'E';
                    }else if(c == 'O'){
                        curr = 'W';
                    }else{
                        curr = c;
                    }
                    x = i;
                    y = j;
                    //msg(x,y)
                }
            }
        }
        counter = 0;
        while(s--){
            cin >> c;
            //msg(curr, c)
            if(c == 'D'){
                if(curr == 'N'){
                    curr = 'E';
                }else if(curr == 'E'){
                    curr = 'S';
                }else if(curr == 'S'){
                    curr = 'W';
                }else if(curr == 'W'){
                    curr = 'N';
                }
            }else if(c == 'E'){
                if(curr == 'N'){
                    curr = 'W';
                }else if(curr == 'E'){
                    curr = 'N';
                }else if(curr == 'S'){
                    curr = 'E';
                }else if(curr == 'W'){
                    curr = 'S';
                }
            }else if(c == 'F'){
                if(curr == 'N'){
                    if(x -1 >= 0 && arr[x-1][y] != '#' ){
                        x = x-1;
                    }
                }else if(curr == 'S'){
                    if(x+1 < n && arr[x+1][y] != '#' ){
                        x++;
                    }
                }else if(curr == 'E'){
                    if(y +1 < m && arr[x][y+1] != '#' ){
                        y++;
                    }
                }else if(curr == 'W'){
                    if(y-1 >= 0 && arr[x][y-1] != '#' ){
                        y--;
                    }
                }
                if(arr[x][y] == '*'){
                    counter++;
                    arr[x][y] = '.';
                }
            }

        }
        cout << counter << endl;
    }



    return 0;
}
