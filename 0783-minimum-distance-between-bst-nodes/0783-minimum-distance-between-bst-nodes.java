class Solution {
    TreeNode prev = null; // To keep track of the previous node during traversal
    int minDiff = Integer.MAX_VALUE;

    public int minDiffInBST(TreeNode root) {
        inOrderTraversal(root);
        return minDiff;
    }

    public void inOrderTraversal(TreeNode node) {
        if (node == null) {
            return;
        }

        inOrderTraversal(node.left);

        if (prev != null) {
            minDiff = Math.min(minDiff, node.val - prev.val);
        }

        prev = node;

        inOrderTraversal(node.right);
    }
}
