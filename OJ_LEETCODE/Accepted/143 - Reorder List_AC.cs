/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 143. Reorder List
Problem Link: https://leetcode.com/problems/reorder-list/
Complexity: O(n)
Date : 12 / Jul / 2022

Comment: Go to the end and keep a pointer in the head, then return and keep moving the 2 pointers.
*/


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {


    ListNode p1,p2;
    bool reachedEnd = false, reorderFinished = false;

    public void Reorder(ListNode node){

        if(node == null){
            reachedEnd = true;
            return;
        }

        if(!reachedEnd){
            Reorder(node.next);
        }

        if(reorderFinished){
            return;
        }

        if(reachedEnd){
            p2 = node;
        }

        if(p1 == p2){
            p1.next = null;
            reorderFinished = true;
            return;
        }

        if(reachedEnd){

            if(p1.next == p2){
                reorderFinished = true;
            }
            p2.next = p1.next;
            p1.next = p2;
            p1 = p2.next;

            if(p1 == p2){
                p1.next = null;
                reorderFinished = true;
                return;
            }
        }
        return;
    }

    public void ReorderList(ListNode head) {
        p1 = head;
        Reorder(head);
    }
}
