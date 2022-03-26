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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        TreeNode *cur = root, *parent = nullptr;
        bool lr = true;
        while(1)
        {
            if(cur == nullptr)
            {
                cur = new TreeNode(val);
                if(lr)
                    parent->left = cur;
                else
                    parent->right = cur;
                break;
            }
            if(cur->val > val)
            {
                parent = cur;
                lr = true;
                cur = cur->left;
            }
            else if(cur->val < val)
            {
                parent = cur;
                lr = false;
                cur = cur->right;
            }
        }
        return root;
    }
};