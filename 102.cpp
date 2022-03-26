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
    vector<vector<int>> result;
    queue<TreeNode*> q;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
        {
            return result;
        }
        q.push(root);
        q.push(nullptr);
        while(q.front() != nullptr)
        {
            helper();
        }
        return result;
    }

    void helper()
    {
        vector<int> floor;
        while(q.front() != nullptr)
        {
            floor.push_back(q.front()->val);
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        q.pop();
        q.push(nullptr);
        result.push_back(floor);
    }
};