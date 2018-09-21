#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,m,foundBlack = 0,blackX, blackX2, blackY, blackY2;
    cin >> n >> m;
    char mat[n+4][m+4];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            if(foundBlack == 0 && mat[i][j] =='B'){
                foundBlack = 1;
                blackX = i;
                blackY = j;
            }
        }
    }
    blackY2 = blackY;
    for(int i= blackY ;i<m;i++){
        if(mat[blackX][i] != 'B'){
            blackY2 = i-1;
            break;
        }
    }
    int increment = blackY - blackY2;
    /*
    blackX2 = blackX;
    for(int i=blackX;i<n;i++){
        if(mat[i][blackY] != 'B'){
            blackX2 = i-1;
        }
    }*/
    blackX2 = blackX + increment;
    int a,b;

    a = ceil( (blackX+blackX2) / 2)+1;
    b = ceil( (blackY+blackY2) / 2)+1;
    //msg(a,b)
    msg3(blackX, blackX2, blackY, blackY2)
    cout << a << " " << b << endl;




    return 0;
}
