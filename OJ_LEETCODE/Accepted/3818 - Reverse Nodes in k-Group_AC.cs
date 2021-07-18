public class ListNode
{
    public int val;
    public ListNode next;
    public ListNode(int val = 0, ListNode next = null)
    {
        this.val = val;
        this.next = next;
    }
}

public class Solution
{
    public ListNode ReverseKGroup(ListNode head, int k)
    {
        ListNode currentNode = head, curr = null;
        bool headSelected = false;
        Stack<ListNode> stack = new Stack<ListNode>();
        while (currentNode != null)
        {
            stack.Push(currentNode);
            currentNode = currentNode.next;
            if (stack.Count == k)
            {
                if (!headSelected)
                {
                    head = stack.Peek();
                    headSelected = true;
                }
                ListNode temp = stack.Peek().next;
                if (curr != null)
                {
                    curr.next = stack.Peek();
                }
                while (stack.Count > 0)
                {
                    curr = stack.Peek();
                    stack.Pop();
                    curr.next = stack.Count == 0 ? temp : stack.Peek();
                }
            }
        }
        return head;
    }
}
