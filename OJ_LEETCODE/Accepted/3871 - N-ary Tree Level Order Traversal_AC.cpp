/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3871/
Date : 06 / August / 2021
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

public class Solution
{
    public IList<IList<int>> LevelOrder(Node root)
    {
        var listAll = new List<IList<int>>();
        if(root == null)
        {
            return listAll;
        }
        Queue<(Node,int)> q = new Queue<(Node, int)>();
        q.Enqueue((root, 1));
        while(q.Count > 0)
        {
            var top = q.Dequeue();
            var u = top.Item1;
            var level = top.Item2;
            if(level > listAll.Count)
            {
                listAll.Add(new List<int>());
            }
            listAll[level - 1].Add(u.val);
            for(int i = 0; i < u.children.Count; i++)
            {
                if(u.children[i] != null)
                {
                    q.Enqueue( (u.children[i], level+1) );
                }
            }
        }
        return listAll;
    }
}

int main(){

    return 0;
}
