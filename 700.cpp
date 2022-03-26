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
    int target;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;
        target = val;
        return helper(root);
    }
    TreeNode* helper(TreeNode* root)
    {
        if(root->val == target)
            return root;
        TreeNode *l, *r;
        if(root->left)
            l = helper(root->left);
        else
            l = nullptr;
        if(root->right)
            r = helper(root->right);
        else
            r = nullptr;
        if(l == nullptr)
            return r;
        else
            return l;
    }
};