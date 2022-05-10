/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include<queue>
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        vector<vector<int>> result;
        vector<int> temp;
        if(root == nullptr)
            return result;
        while(!q.empty())
        {
            Node* cur = q.front();
            q.pop();
            if(cur == nullptr)
            {
                result.push_back(temp);
                temp.clear();
                if(!q.empty())
                    q.push(nullptr);
            }
            else
            {
                temp.push_back(cur->val);
                int len = cur->children.size();
                for(int i = 0; i < len; ++i)
                {
                    q.push(cur->children[i]);
                }
            }
        }
        return result;
    }
};