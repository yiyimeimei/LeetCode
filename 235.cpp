/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* ancestor = nullptr;
    int v1, v2;
    bool flag1 = false, flag2 = false;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        v1 = p->val;
        v2 = q->val;
        helper(root);
        return ancestor;
    }
    bool helper(TreeNode* root)
    {
        bool l = false, r = false;
        if(root->left)
            l = helper(root->left);
        if(root->right)
            r = helper(root->right);
        if(l && r)
        {
            ancestor = root;
            return false;
        }
        else if(l || r)
        {
            if(root->val == v1 || root->val == v2)
            {
                ancestor = root;
                return false;
            }
            else
                return true;
        }
        else
        {
            if(root->val == v1 || root->val == v2)
                return true;
            else
                return false;
        }
        
    }
};

