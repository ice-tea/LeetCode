/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return recBuildTree(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1);
    }
    
    public TreeNode recBuildTree(int[] inorder, int is, int ie, int[] postorder, int ps, int pe){
        if(is > ie || ps > pe) return null;
        
        TreeNode root = new TreeNode(postorder[pe]);
        int n = is;
        for(; n < ie; n++){
            if(inorder[n] == postorder[pe])
                break;
        }
        
        root.left = recBuildTree(inorder, is, n-1, postorder,ps, (ps+n-is-1));
        root.right = recBuildTree(inorder, n+1, ie, postorder, (ps+n-is), pe-1);
        
        return root;
    }
}
