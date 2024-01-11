/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// idea is for each node we check all value in its right & left tree, and store the maximum value of diff & and after traversing the left & right tree for any perticular node we pop out that node from the parent array.
    int ans=INT_MIN;
    void findDiff(TreeNode* root,vector<int>&parent){
        if(!root)return;
        for(auto x:parent){
            ans=max(ans,abs(root->val-x));
        }
        parent.push_back(root->val);
        findDiff(root->left,parent);
        findDiff(root->right,parent);
        parent.pop_back();
    } 
    int maxAncestorDiff(TreeNode* root) {
        if(!root)return INT_MIN;
        vector<int>temp;
        findDiff(root,temp);
        return ans;

        
    }
};