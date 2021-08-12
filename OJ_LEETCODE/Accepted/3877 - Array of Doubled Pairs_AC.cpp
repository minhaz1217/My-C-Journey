/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 12 / August / 2021
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
/*
[0,0]
[0,0,0,1,2,4]
[4,-2,2,-4]
[1,2,4,16,8,4]
[2,1,2,6]
[3,1,3,6]
[2,4,16,8]
[0,0,0,0]
[1,1,1,1,1,1,2,2,2,2,2,2,3,6,6,12]
[-5,-2]
[-1,0]
[0,-1]
[1,0]
[0,1]
*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> intCounter, negativeCounter;
        intCounter[0] = 0;
        int padding = 0;
        for(int index=0;index<arr.size();index++){
            int value = arr[index] + padding;
            if(value >= 0){
                if(intCounter.find( value ) == intCounter.end() ){
                    intCounter[value] = 1;
                }else{
                    intCounter[value]++;
                }
            }else{
                value = value * -1;
                if(negativeCounter.find( value ) == negativeCounter.end() ){
                    negativeCounter[value] = 1;
                }else{
                    negativeCounter[value]++;
                }
            }
        }

        for(map<int,int>::iterator it=intCounter.begin();it!=intCounter.end();it++){
            int numberCount = it->second;
            int number = it->first;
            int find = number *2;
            for(int index=numberCount;index>0;index--){
                if( intCounter[find] >0 ){
                    intCounter[find]--;
                }else{
                    return false;
                }
            }
        }
       // cout << "Negative" << endl;
        for(map<int,int>::iterator it=negativeCounter.begin();it!=negativeCounter.end();it++){
            int numberCount = it->second;
            int number = it->first;
            int find = number *2;
            //cout << number << " " << numberCount << endl;
            for(int index=numberCount;index>0;index--){
                if( negativeCounter[find] >0 ){
                    negativeCounter[find]--;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){

    return 0;
}
