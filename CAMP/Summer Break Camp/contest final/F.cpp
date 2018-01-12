#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;
int main(){
    int r,c,i,j,flag,counter = 0;
    char ch;
    cin >> r >> c;
    int arr[r][c];
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> ch;
            if(ch == 'S'){
                arr[i][j] = -1;
            }else{
                arr[i][j] = 1;
            }
        }
    }
    /*
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }*/
    for(i=0;i<r;i++){
        flag = 1;
        for(j=0;j<c;j++){
            if(arr[i][j] == -1){
                flag = 0;
                //msg(i,j)
                break;
            }
        }
        if(flag == 1){
            for(j=0;j<c;j++){
                if(arr[i][j] == 1){
                    arr[i][j] = 0;
                    counter++;
                }
            }
        }
    }

    //msg("COu", counter )
    for(i=0;i<c;i++){
        flag = 1;
        for(j=0;j<r;j++){
            if(arr[j][i] == -1){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            for(j=0;j<r;j++){
                if(arr[j][i] == 1){
                    arr[j][i] = 0;
                    counter++;
                }
            }
        }
    }
    cout << counter << endl;

    return 0;
}
