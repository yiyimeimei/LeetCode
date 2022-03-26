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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead, *pre = nullptr, *cur = nullptr, *next = nullptr;
        while(head != nullptr)
        {
            cur = head;
            next = head->next;
            cur->next = pre;
            pre = cur;
            head = next;
        }
        return cur;
    }
};