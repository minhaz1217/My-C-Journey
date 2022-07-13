/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 141. Linked List Cycle
Problem Link: https://leetcode.com/problems/linked-list-cycle/
Complexity: O(n) // for both go to limit and the tortoise-hare algorightm
Date : 13 / Jul / 2022

Comment:
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {

    // Floyd's Algorithm for cycle finding.
    public bool TortoiseHareAlgorithm(ListNode head){
        if(head == null){
            return false;
        }
        var p1 = head;
        var p2 = head;
        while(p2.next != null && p2.next.next != null){
            p1 = p1.next;
            p2 = p2.next.next;
            if(p1 == p2){
                return true;
            }
        }
        return false;
    }

    public bool HasCycle(ListNode head) {

        return TortoiseHareAlgorithm(head);

        // if(head == null){
        //     return false;
        // }
        // for(int i=0;i<10005;i++){
        //     if(head.next == null){
        //         return false;
        //     }
        //     head = head.next;
        // }
        // return true;
    }
}
