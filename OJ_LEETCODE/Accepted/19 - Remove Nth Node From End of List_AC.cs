/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 19. Remove Nth Node From End of List
Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Date: 07-Jul-2022

Comment: Used backtracking to do it in O(n) complexity.
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


public class Solution {
    int nodeNumberNeedsToBeRemoved = -1;
    int reverseNodeNumber;
    int totalNodeCount;
    ListNode linkedListHead;
    bool headNeedsToBeRemoved = false;
    public void Travarse(ListNode currentNode, int nodeNumber){
        if(currentNode.next != null){
            Travarse(currentNode.next, nodeNumber + 1);
        }else{
            // this is the last node. so we can calculate which numbered node we need to remove.
            nodeNumberNeedsToBeRemoved = nodeNumber - reverseNodeNumber + 1;
            totalNodeCount = nodeNumber;
        }


        if(nodeNumberNeedsToBeRemoved != -1){
            // remove the node
            if(nodeNumber == 1 && nodeNumberNeedsToBeRemoved == 1 ){
                headNeedsToBeRemoved = true;
            }else if(nodeNumber == nodeNumberNeedsToBeRemoved -1 ){
                if(currentNode.next.next != null){
                    currentNode.next = currentNode.next.next;
                }else{
                    currentNode.next = null;
                }
            }
        }
        return;
    }

    public ListNode RemoveNthFromEnd(ListNode head, int n) {
        linkedListHead = head;
        reverseNodeNumber = n;
        Travarse(head, 1);
        if(headNeedsToBeRemoved){
            if(head.next != null){
                head = head.next;
            }else{
                head = null;
            }
        }
        return head;
    }
}


int main(){
    _INIT;

    return 0;
}
