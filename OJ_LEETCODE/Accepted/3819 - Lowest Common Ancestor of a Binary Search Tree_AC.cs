/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        Queue<TreeNode> queue = new Queue<TreeNode>();
        Dictionary<int, TreeNode> parents = new Dictionary<int, TreeNode>();
        Dictionary<TreeNode, int> parentsOfP = new Dictionary<TreeNode, int>();
        queue.Enqueue(root);
        parents[root.val] = root;
        while(queue.Count > 0)
        {
            if(queue.Peek().left != null)
            {
                queue.Enqueue(queue.Peek().left);
                parents[queue.Peek().left.val] = queue.Peek();
            }
            if (queue.Peek().right != null)
            {
                queue.Enqueue(queue.Peek().right);
                parents[queue.Peek().right.val] = queue.Peek();
            }
            queue.Dequeue();
        }
        TreeNode current = p;
        while(current != root)
        {
            parentsOfP[current] = 1;
            current = parents[current.val];
        }

        current = q;
        while (current != root)
        {
            if ( parentsOfP.ContainsKey(current) )
            {
                return current;
            }
            current = parents[current.val];
        }
        return root;
    }
}
