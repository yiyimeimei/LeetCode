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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        invert(root);
        return root;
    }
    void invert(TreeNode* root)
    {
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = r;
        root->right = l;
        if(l)
            invert(l);
        if(r)
            invert(r);
    }
};