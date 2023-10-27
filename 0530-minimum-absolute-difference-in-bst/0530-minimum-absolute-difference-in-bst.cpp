class Solution {
public:
    void function(TreeNode* root,int &preVal,int &minDiff){
        if(root == NULL)
        return;
        function(root->left,preVal,minDiff);
        if(preVal != -1){
            minDiff = min(minDiff,root->val - preVal);
        }
        preVal = root->val;
        function(root->right,preVal,minDiff);
    }
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int preVal = -1;
      function(root,preVal,minDiff);
      return minDiff;
    }
};