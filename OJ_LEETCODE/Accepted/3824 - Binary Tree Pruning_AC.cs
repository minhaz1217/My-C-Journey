// /*
//   Definition for a binary tree node.*/
//  public class TreeNode {
//      public int val;
//      public TreeNode left;
//      public TreeNode right;
//      public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
//          this.val = val;
//          this.left = left;
//          this.right = right;
//      }
//  }
 public class Solution {

    public int OneCount(TreeNode node){
        if(node == null){
            return 0;
        }
        int leftCount = OneCount(node.left);
        if(leftCount == 0){
            node.left = null;
        }
        int rightCount = OneCount(node.right);
        if(rightCount == 0){
            node.right = null;
        }

        if(node.val == 1){
            return 1 + leftCount + rightCount;
        }
        return leftCount + rightCount;

    }

    public TreeNode PruneTree(TreeNode root) {
        var count = OneCount(root);
        if(count == 0){
            root = null;
        }
        return root;
    }
}
