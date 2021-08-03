/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3837/
Date : 03 / August / 2021
Comment: from the problem statement there isn't any feelings of sorting.
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
3
1 2 2

1
0
5
1 2 3 2 3

>> outputs a result: 1 2 2 3 3

*/


class Solution {
public:
    set<deque<int> > st;
    vector<int> visited;
    vector<int> num;
    int sz;
    void backTrack(deque<int> vec, int start, int n){
        if(vec.size() == n){
            st.insert(vec);
            return;
        }

        for(int i=start;i<sz;i++){
            if(!visited[i]){
                visited[i] = 1;
                vec.push_back(num[i]);
                backTrack(vec,i+1, n);
                vec.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        st.clear();
        sort(nums.begin(),nums.end());
        num = nums;
        sz = num.size();
        visited = vector<int>(sz+2,0);

        for(int i=1;i<=sz;i++){
            for(int j=0;j<sz;j++){
                visited[j] = 0;
            }
            deque<int> temp;
            backTrack(temp, 0, i);
        }
        vector<vector<int> > result;
        vector<int> vec;
        result.push_back(vec);
        for(set<deque<int> >::iterator it = st.begin();it!=st.end();it++){
            deque<int> res = *it;
            vector<int> output;
            for(int i=0;i<res.size();i++){
                output.push_back(res[i]);
            }
            result.push_back( output );
        }
        return result;
    }
};
int main(){

    int n,a;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }

    Solution s;
    vector<vector<int> > res =  s.subsetsWithDup( vec );
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
