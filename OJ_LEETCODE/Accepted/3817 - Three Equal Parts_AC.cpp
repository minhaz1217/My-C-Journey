/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3817/
Date : 18 / July / 2021
Comment: Leetcode hard, too mane edge cases needed to be handled.
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
/*

10101
output : 0,3

11011
output: -1, -1

11001
output: 0, 2

111
output: 0,2
000

100011
output: 0,5

11010011011101
output: 3,10
*/



class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        bitset<30003> b1,b2,b3;
        int n;
        n= arr.size();
        for(int i=0;i<n;i++){
            //cout << arr[i] << " ";
            if(arr[n-i-1] == 1){
                b2.flip(i);
            }
        }
        int i=n-1,j=0,res1=0,res2=n-1;
        int b1Size = 0, b3Size = 0, b1Full = 0;
        while( !(b1Size >=n || b3Size>=n)){
            if( !(b1 == b2 && b2 == b3) ){
                if(b2.test(0) == 0){
                    b2 = b2 >> 1;
                    j++;
                    res2--;
                    b3Size++;
                }else if(b2.test(i) == 0 && !b1Full){
                    b1 = b1 << 1;
                    res1++;
                }else if(b1Size > b3Size && b1Full){ // first array is longer, so we push front b3
                    if(b2.test(0) == 1){
                        b3.flip(j);
                    }
                    b2 = b2 >> 1;
                    j++;
                    res2--;
                    b3Size++;
                }else{ // second array is longer, push back b1
                    b1 = b1 << 1;
                    if(b2.test(i) == 1){
                        b1.flip(0);
                        b2.flip(i);
                        b1Full = 1;
                    }
                    b1Size++;
                    res1++;
                }
                i--;
            }else{
                break;
            }
        }
        vector<int> vec;
        if(b1 == b2 && b2 == b3){
            if(res1 > 0){
                res1--;
            }
            if(res2 <n-1){
                res2++;
            }
            vec.push_back(res1);
            vec.push_back(res2);
        }else{
            vec.push_back(-1);
            vec.push_back(-1);
        }
        return vec;
    }
};


int main(){
    int n,a;
    string str;
    cin >> str;
    vector<int>vec;
    for(int i=0;i<str.size();i++){
        vec.push_back( str[i]-'0' );
    }

    Solution solution;
    vector<int> vec2 = solution.threeEqualParts(vec);
    for(int i=0;i<vec2.size();i++){
        cout << vec2[i] << " ";
    }
    cout << endl;
    return 0;
}
