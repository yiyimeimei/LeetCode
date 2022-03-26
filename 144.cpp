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
    vector<int> result;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return result;
        pre(root);
        return result;
    }
    void pre(TreeNode *root)
    {
        result.push_back(root->val);
        if(root->left)
            pre(root->left);
        if(root->right)
            pre(root->right);
        return;
    }
};