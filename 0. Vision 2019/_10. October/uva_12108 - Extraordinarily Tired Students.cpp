/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://onlinejudge.org/external/121/12108.pdf
Date : 25 / October / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int status[11], currCounter[11];
int main(){
    int n,a,b,c,counter,currStatus,tempCounter,ans,caseCounter = 1;
    while(1){
        vector<pair<int, int> > vec;
        vector<int>arr[100];
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i=0;i<n;i++){
            cin >> a >> b >> c;
            currStatus = 1;
            counter = a;
            for(int j=1;j<c;j++){
                if(j>a){
                    currStatus = 2;
                    counter = b;
                }
                counter--;
            }
            status[i] = currStatus;
            currCounter[i] = counter;
            vec.push_back({a,b});
            if(currCounter[i] == 0){
                if(status[i] == 1){
                    status[i] = 2;
                    currCounter[i] = vec[i].second;
                }else{
                    status[i] = 1;
                    currCounter[i] = vec[i].first;
                }
            }
        }
        ans = -1;

    //    for(int i=0;i<n;i++){
    //        msg2(i, status[i],currCounter[i])
    //    }
        counter = 0;
        for(int k=0;k<10000;k++){
            tempCounter = counter;
            counter = 0;
            if(tempCounter == n){
                ans = k;
                break;
            }
            for(int i=0;i<n;i++){
                if(currCounter[i] == 0){
                    if(status[i] == 1){
                        if(tempCounter > n - tempCounter){
                            status[i] = 1;
                            currCounter[i] = vec[i].first;
                        }else{
                            status[i] = 2;
                            currCounter[i] = vec[i].second;
                        }
                    }else{
                        status[i] = 1;
                        currCounter[i] = vec[i].first;
                    }
                }
                currCounter[i]--;
                arr[i].push_back(status[i]);
                if( (status[i] == 1 ) || (status[i] == 2 && currCounter == 0)) {
                    counter++;
                }
            }
        }
    //    for(int i=1;i<=21;i++){
    //        printf("%3d", i);
    //    }
    //    cout << endl;
    //    for(int i=0;i<n;i++){
    //        for(int j=0;j<arr[i].size();j++){
    //            printf("%3d", arr[i][j]);
    //        }
    //        cout << endl;
    //    }
        cout << "Case " << caseCounter++ << ": " << ans << endl;
    //    cout << ans << endl;
    }
    return 0;
}
