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
    queue<int> l, r;
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        /* if(root->left == nullptr && root->right == nullptr)
            return true;
        if(root->left == nullptr || root->right == nullptr)
            return false; */
        helperLeft(root);
        helperRight(root);
        if(l.size() != r.size())
            return false;
        while(!l.empty() && !r.empty())
        {
            if(l.front() != r.front())
                return false;
            l.pop();
            r.pop();
        }
        if(l.empty() && r.empty())
            return true;
        return false;
    }
    void helperLeft(TreeNode* root)
    {
        l.push(root->val);
        if(root->left)
            helperLeft(root->left);
        else
            l.push(-101);
        if(root->right)
            helperLeft(root->right);
        else
            l.push(-101);
    }
    void helperRight(TreeNode* root)
    {
        r.push(root->val);
        if(root->right)
            helperRight(root->right);
        else
            r.push(-101);
        if(root->left)
            helperRight(root->left);
        else
            r.push(-101);
    }
}; 