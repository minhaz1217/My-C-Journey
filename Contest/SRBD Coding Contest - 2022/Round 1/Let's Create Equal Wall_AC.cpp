/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name:
Problem Link: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/lets-create-equal-walls
Complexity:
Date : 16 / Aug / 2022

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

int main(){
    _INIT;
    int n1,n2,n3, a, sum1 = 0, sum2 = 0, sum3 = 0;
    cin >> n1 >> n2 >> n3;
    vector<int> vec1,vec2,vec3;
    int index1 =0,index2 = 0, index3 = 0;

    while(n1--){
        cin >> a;
        vec1.push_back(a);
        sum1 += a;
    }


    while(n2--){
        cin >> a;
        vec2.push_back(a);
        sum2 += a;
    }


    while(n3--){
        cin >> a;
        vec3.push_back(a);
        sum3 += a;
    }

    while(1){
        if(index1 == vec1.size() || index2 == vec2.size() || index3 == vec3.size()){
            break;
        }
        // msg2(sum1, sum2, sum3)
        if(sum1 == sum2 && sum2 == sum3){
            cout << sum1 << endl;
            return 0;
        }else if(sum1 >= sum2 && sum1 >= sum3){
            sum1 -= vec1[index1];
            index1++;
        }else if(sum2 >= sum1 && sum2 >= sum3){
            sum2 -= vec2[index2];
            index2++;
        }else if(sum3 >= sum1 && sum3 >= sum2){
            sum3 -= vec3[index3];
            index3++;
        }
    }
    cout << 0 << endl;
    return 0;
}
