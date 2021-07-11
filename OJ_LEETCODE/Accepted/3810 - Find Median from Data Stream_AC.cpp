/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3810/
Date : 11 / July / 2021
Comment: tried with AVL tree, tried with k-th smallest in avl, couldn't make it work, got stuck because of the last test case, after that solved it in the worst way possible.
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

class MedianFinder {
public:
    double lastVal, val1,val2,a;
    int sz,seekVal1,pad;
    map<int, int> m;
    int Kth_smallest(int k)
    {
        int freq = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            freq += (it->second);
            if (freq >= k)
            {
                return it->first;
            }
        }
        return -1;
    }

    // this k is k+1
    int KP1th_smallest(int k)
    {
        int freq = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            freq += (it->second);
            if (freq >= k)
            {
                val2 = it->first;
                if(k-1 > freq - it->second ){
                    val1 = it->first;
                }else{
                    it--;
                    val1 = it->first;
                }
                return it->first;
            }
        }
        return -1;
    }

    /** initialize your data structure here. */
    MedianFinder() {
        sz = 0;
        m.clear();
        pad = 100005;
    }

    void addNum(int num) {
        if(m.find(num) == m.end()){
            m[num] = 1;
        }else{
            m[num]++;
        }
        sz++;
    }

    double findMedian() {
        if(sz%2 == 0){
            //val2 = Kth_smallest(sz/2+1) - pad;

            //val1 = Kth_smallest(sz/2) - pad;
            KP1th_smallest(sz/2+1);
            val1 = val1;
            val2 = val2;
            return (val1+val2)/2.0;
        }

        val1 = Kth_smallest((sz+1)/2);

        return val1;
    }
};

int main(){

    return 0;
}
