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
#include <unordered_set>
class Solution {
public:
    unordered_set<int> set;
    bool flag = false;
    bool findTarget(TreeNode* root, int k) 
    {
        helper(root, k);
        return flag;
        
    }
    void helper(TreeNode* root, int k)
    {
        if(root == nullptr)
        {
            return;
        }
        else
        {
            if(set.find(k - root->val) != set.end())
            {
                flag = true;
                return;
            }
            else
            {
                set.insert(root->val);
                helper(root->left, k);
                helper(root->right,k);
                return;
            }
        }
    }
};