/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 30 / June / 2021
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
intput: here -1 means null, although in the real problem, there can be negative values
3 5 1 6 2 0 8 -1 -1 7 4
*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<pair< TreeNode*, pair<int,int> > > treeQ;
        vector<pair<int,pair<int,TreeNode*> > > tree(100004,make_pair(INT_MIN, make_pair(0, root))); // { value, original position, node }
        vector<TreeNode*> treeNodes(100004);
        int nodePosition = 0;
        tree[1] =  make_pair(root->val,make_pair(1, root) );
        if(root->left != NULL){
            treeQ.push(make_pair(root->left, make_pair(1,-1))); // 2nd 2nd value -1 means left
        }
        if(root->right != NULL){
            treeQ.push(make_pair(root->right, make_pair(1,1))); // 2nd 2nd value 1 means right
        }
        while(!treeQ.empty()){
            int parent = treeQ.front().second.first;
            if(treeQ.front().first != NULL){
                TreeNode* node = treeQ.front().first;
                if(treeQ.front().second.second == -1){ // left node
                    nodePosition = 2*parent;
                }else{  // right node
                    nodePosition = 2*parent + 1;
                }
                tree[nodePosition] = make_pair(node->val, make_pair(nodePosition, treeQ.front().first) );
                if(node->left != NULL){
                    treeQ.push(make_pair(node->left, make_pair(nodePosition,-1)));
                }
                if(node->right != NULL){
                    treeQ.push(make_pair(node->right, make_pair(nodePosition,1)));
                }
            }
            treeQ.pop();
        }

        sort(tree.begin(),tree.end());
        int pPosition = lower_bound(tree.begin(), tree.end(),make_pair(p->val, make_pair(0, root))) - tree.begin();
        int qPosition = lower_bound(tree.begin(), tree.end(), make_pair(q->val, make_pair(0, root))) - tree.begin();
        map<int, int> pParents;
        pPosition = tree[pPosition].second.first;
        qPosition = tree[qPosition].second.first;
        if(qPosition > pPosition){
            swap(qPosition, pPosition);
        }
        while(pPosition > 0){
            pParents[pPosition] = 1;
            pPosition = pPosition /2;
        }
        while(qPosition > 0){
            if(pParents.find(qPosition) != pParents.end()){
                break;
            }
            qPosition = qPosition /2;
        }
        for(int i=0;i<tree.size();i++){
            if(tree[i].second.first == qPosition){
                return tree[i].second.second;
            }
        }
        return root;
    }
};
int main(){

    return 0;
}
