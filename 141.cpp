/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head != nullptr)
        {
            if(set.count(head) == 1)
            {
                return true;
            }
            else
            {
                set.emplace(head);
            }
            head = head->next;
        }
        return false;
        
    }
};