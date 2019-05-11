/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 11 / March / 2019
Comment:
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
#define MX 504
int mata[MX][MX], matb[MX][MX],visited[MX][MX];
int n, m;
int matchT(int r, int c){
    int i = r, j = c,counter=0, counter1=0, counter2=0;
    counter = 0;
    for(i = r;i<n;i++){
        if(mata[i][j] == matb[j][i]){
            //visited[i][j] = 1;
            counter++;
        }else{
            break;
        }
    }
    j = c;
    i =r;
    counter1 = counter;
    counter2  = 0;
    for(j= c;j<min(c+counter, m) ;j++){
        if(mata[i][j] == matb[j][i]){
            counter2++;
        }else{
            break;
        }
    }
    counter = min(counter1, counter2);
    for(i=r;i<r+counter;i++){
        for(j = c;j<c+counter;j++){
            visited[i][j] = 1;
        }
    }

}
void matchS(int r, int c){
    int i=r, j=c, counter=0, counter1 = 0, counter2=0;
    for(i=r;i<n;i++){
        if(mata[i][j] == matb[i][j]){
            counter1++;
        }else{
            break;
        }
    }
    i =r;
    j = c;
    for(j = c;j<min(m, c+counter1);j++){
        if(mata[i][j] == matb[i][j]){
            counter2++;
        }else{
            break;
        }
    }
    counter = min(counter1, counter2);
    for(i=r;i<r+counter;i++){
        for(j = c;j<c+counter;j++){
            visited[i][j] = 1;
        }
    }
}
int main(){
    int a,currMax,r,c,flag;
    vector<pair<int,int> >vec;
    scanf("%d%d", &n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a);
            mata[i][j] = a;
            //cin >> a;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a);
            matb[i][j] = a;
            if(mata[i][j] == a){
                vec.push_back(make_pair(i,j));
            }
            visited[i][j] = 0;
        }
    }
    for(r =0;r<n;r++){
        for(c =0;c<m;c++){
        if(visited[r][c] == 0){
            matchT(r,c);
            matchS(r,c);
        }
    }
    }
    flag = 1;
    for(int i=0;i<n && flag;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] == 0){
               // msg(i,j)
                flag = 0;
                break;
            }
        }
    }
    if(flag == 0){
        printf("NO\n");
    }else{
        printf("YES\n");
    }


    return 0;
}
