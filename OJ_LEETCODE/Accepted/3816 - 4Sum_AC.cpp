/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3816/
Date : 16 / July / 2021
Comment: the only problem was that getting value from inside the set.
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

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort( nums.begin(), nums.end() );
        set<pair< int, pair<int, pair<int,int> > > > st;
        int sz = nums.size();
        for(int i=0;i<sz-3;i++){
            for(int j=i+1;j<sz-2;j++){
                for(int k=j+1;k<sz-1;k++){
                    int temp = target - nums[i] - nums[j] - nums[k];
                    int pos = lower_bound(nums.begin() + k+1, nums.end(), temp) - nums.begin();
                    if(pos < sz && temp - nums[pos] == 0){
                        st.insert( make_pair(nums[i], make_pair(nums[j], make_pair(nums[k], nums[pos]))) );
                    }

                }
            }
        }
        vector<vector<int> > output;
        for(set<pair< int, pair<int, pair<int,int> > > >::iterator it=st.begin();it !=st.end();it++){
            vector<int> vec;
            vec.push_back((*it).first);
            vec.push_back((*it).second.first);
            vec.push_back((*it).second.second.first);
            vec.push_back((*it).second.second.second);
            output.push_back(vec);
        }
        return output;
    }
};

int main(){

    return 0;
}
