/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 19 / January / 2020
Comment:
*/
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MX 510
int LCS[MX][MX], p1[MX], p2[MX][MX];

int arr1[MX], arr2[MX],n,m;
void printLCS(){
    int i=n,j=m,idx=0;
    cout << i << " " << j << endl;
    while(i>0 && j>0){
        if(arr1[i-1] == arr2[j-1]){

            cout << arr1[i-1] << " ";
            i--,j--;
        }else if(LCS[i-1][j]> LCS[i][j-1]){
            i--;
        }else{
            j--;
        }
    }


}
int calculateLCS(){

    int L[n+4][m+4];
    cout << "PRint X" << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "PRint Y" << endl;

    for(int i=0; i<m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << n << " " << m << endl;


    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i ==0 || j == 0){
                LCS[i][j] = 0;
            }else if( arr1[i-1] == arr2[j-1] ){
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }else{
                int c1 = LCS[i][j-1];
                int c2 = LCS[i-1][j];
//                if(c1 >=c2){
//                    p1[i] = i;
//                }else{
//                    p1[i] = i-1;
//                }
                LCS[i][j] = max(c1, c2);
            }
        }
    }

    return LCS[n][m];

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr1[i];
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> arr2[i];
    }
    for(int i=0;i<=n;i++){
        p1[i] = -1;
    }
    cout << "RESULT: " << calculateLCS() <<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << LCS[i][j] << " ";
        }
        cout << endl;
    }
    printLCS();
    return 0;
}
