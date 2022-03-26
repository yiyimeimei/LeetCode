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
    private:
    int ts;
    bool flag = false;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        ts = targetSum;
        helper(root, 0);
        return flag;
    }
    void helper(TreeNode* root, int sum)
    {
        sum += root->val;
        if(sum == ts && !root->left && !root->right)
        {
            flag = true;
            return;
        }
        if(root->left && !flag)
            helper(root->left, sum);
        if(root->right && !flag)
            helper(root->right, sum);
        return;
    }
};