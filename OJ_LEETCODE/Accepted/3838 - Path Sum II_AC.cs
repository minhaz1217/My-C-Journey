/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 04 / August / 2021
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


public class TreeNode
{
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

public class Solution
{
    IList<IList<int>> finalList;
    int targetValue;
    void travarse(TreeNode node, int currentVal, List<int> currentList)
    {
        if (node == null)
        {
            return;
        }

        if (node.left == null && node.right == null)
        {
            if (node.val + currentVal == targetValue)
            {
                currentList.Add(node.val);
                finalList.Add(currentList);
            }
            return;
        }
        currentList.Add(node.val);
        var rightList = new List<int>(currentList);
        var leftList = new List<int>(currentList);
        travarse(node.left, currentVal + node.val, leftList);
        travarse(node.right, currentVal + node.val, rightList);
    }

    public IList<IList<int>> PathSum(TreeNode root, int targetSum)
    {
        finalList = new List<IList<int>>();
        if (root == null)
        {
            return finalList;
        }
        targetValue = targetSum;
        List<int> list = new List<int>();
        travarse(root, 0, list);
        return finalList;
    }
}
