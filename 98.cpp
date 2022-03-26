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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return false;
        return helper(root, nullptr, nullptr);
    }
    bool helper(TreeNode* root, int *max, int *min)
    {
        bool flag1 = true, flag2 = true;
        if(root->left)
        {
            if(root->left->val < root->val && (min == nullptr || root->left->val > (*min)))
            {
                int *tmp = new int(root->val);
                flag1 = helper(root->left, tmp, min);
                delete tmp;
            }
            else
                return false;
        }
        if(root->right)
        {
            if(root->right->val > root->val && (max == nullptr || root->right->val < (*max)))
            {
                int *tmp = new int(root->val);
                flag2 = helper(root->right, max, tmp);
                delete tmp;
            }
            else
                return false;
        }
        return flag1 && flag2;
    }
};