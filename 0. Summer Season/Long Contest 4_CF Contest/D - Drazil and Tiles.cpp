#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    int index,i,j,n,m;
    map<pair<int,int> , char>mp;
    vector<pair<int,int> >vec;



    index = 1;
    cin >> n >> m;
    char mat[n][m];
    vec.push_back(make_pair(-1,-1));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> mat[i][j];
            if(mat[i][j] == '.'){
                mp[make_pair(i,j)] = index++;
                vec.push_back(make_pair(i,j));
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(mat[i][j] == '.')
        }
    }





    return 0;
}
