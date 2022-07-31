/*
Minhazul Hayat Khan
github.com/minhaz1217
Bangladesh

Problem Name: 21. Merge Two Sorted Lists
Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/
Complexity: O(m+n)
Date : 01 / Aug / 2022

Comment: Just compare and connect the two lists.
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
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null){
            return list2;
        }else if(list2 == null){
            return list1;
        }

        ListNode outputHead = null;
        if(list1.val <= list2.val){
            outputHead = list1;
            list1 = list1.next;
        }else{
            outputHead = list2;
            list2 = list2.next;
        }
        var currentTail = outputHead;
        while(list1 != null && list2 != null){
            if(list1.val <= list2.val){
                currentTail.next = list1;
                list1 = list1.next;
            }else{
                currentTail.next = list2;
                list2 = list2.next;
            }
            // Console.WriteLine(currentTail.val);
            currentTail = currentTail.next;
        }

        if(list1 != null){
            currentTail.next = list1;
        }else if(list2 != null){
            currentTail.next = list2;
        }
        return outputHead;

    }
}

/*
Input:
[1,2,4]
[1]
[1]
[1,3,4]
[1,5]
[1,1,1,3,4]
[]
[]
[]
[0]

Output:
[1,1,2,4]
[1,1,3,4]
[1,1,1,1,3,4,5]
[]
[0]

*/
