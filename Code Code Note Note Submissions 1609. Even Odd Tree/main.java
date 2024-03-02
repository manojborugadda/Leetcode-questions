/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {//TC:O(N)  SC:O(N) ------ we are using BFS here
    public boolean isEvenOddTree(TreeNode root) {
      Queue<TreeNode>q = new LinkedList<>();
      q.add(root);
      int level = 0;
      while(!q.isEmpty()) {
          TreeNode prevNode = null;//when we are changing the levels we assign "prevNode = null"
          int size = q.size();
          for(int i = 0;i<size;i++) {
              TreeNode currNode = q.poll();
              if(level % 2 == 0) {//even level
                if(currNode.val % 2 == 0) {//if it is EVEN integer   
                    return false;
                }
                if(prevNode != null && prevNode.val  >= currNode.val ) {
                    return false;
                }
              } else {//odd level
                if(currNode.val % 2 != 0) {//if it is ODD integer   
                    return false;
                }
                if(prevNode != null && prevNode.val  <= currNode.val ) {
                    return false;
                }
              }
            prevNode  = currNode;
            if(currNode.left != null) {
                q.add(currNode.left);
            }
            if(currNode.right != null) {
                q.add(currNode.right);
            }
          }

        level++;
      } 
      return true; 
    }
}
