#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int flag,n;
    string str, mainStr1, mainStr2,strCmp1, strCmp2,pref,suf;

    cin >> n;
    vector<pair<string ,int > >vec[n];
    char arr1[300], arr2[300];
    for(int i=0;i<(2*n-2);i++){
        cin >> str;
        vec[str.size()].push_back(make_pair(str,i));
    }
    for(int i=0;i<300;i++){
        arr1[i] = 'I';
        arr2[i] = 'I';
    }
    // pref suf
    mainStr1 = vec[n-1][0].first + vec[n-1][1].first[n-2];
    arr1[vec[n-1][0].second] = 'P';
    arr1[vec[n-1][1].second] = 'S';
    mainStr2 = vec[n-1][1].first + vec[n-1][0].first[n-2];
    arr2[vec[n-1][1].second] = 'P';
    arr2[vec[n-1][0].second] = 'S';
    //msg(mainStr1, mainStr2);
    for(int i=n-2;i>=1;i--){
        strCmp1 = vec[i][0].first;
        strCmp2 = vec[i][1].first;
        //msg2(i, mainStr1.substr(0,i), mainStr1.substr(n-i,i))
        pref  = mainStr1.substr(0,i);
        suf  = mainStr1.substr(n-i,i);
        if( strCmp1 == pref && strCmp2 == suf){
            arr1[ vec[i][0].second ] = 'P';
            arr1[ vec[i][1].second ] = 'S';
        }else if(strCmp1 == suf && strCmp2 == pref){
            arr1[ vec[i][0].second ] = 'S';
            arr1[ vec[i][1].second ] = 'P';

        }

        pref  = mainStr2.substr(0,i);
        suf  = mainStr2.substr(n-i,i);
        if( strCmp1 == pref && strCmp2 == suf){
            arr2[ vec[i][0].second ] = 'P';
            arr2[ vec[i][1].second ] = 'S';
        }else if(strCmp1 == suf && strCmp2 == pref){
            arr2[ vec[i][0].second ] = 'S';
            arr2[ vec[i][1].second ] = 'P';
        }
    }
    flag = 1;
    for(int i=0;i<(2*n-2);i++){
        if(arr1[i] == 'I'){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        for(int i=0;i<(2*n-2);i++){
            cout << arr1[i];
        }
    }else{
        for(int i=0;i<(2*n-2);i++){
            cout << arr2[i];
        }
    }
    cout << endl;
    return 0;
}
