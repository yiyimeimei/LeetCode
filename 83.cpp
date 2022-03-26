/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        int preVal = head->val;
        ListNode *preNode = head, *result = head;
        head = head->next;
        while(head != nullptr)
        {
            if(head->val == preVal)
            {
                preNode->next = head->next;
                ListNode *del = head;
                head = head->next;
                delete del;
            }
            else
            {
                preVal = head->val;
                preNode = head;
                head = head->next;
            }
        }
        return result;
    }
};