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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *pre;
        pre = new ListNode(0, nullptr);
        head = pre;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                pre->next = list1;
                pre = pre->next;
                list1 = list1->next;
            }
            else
            {
                pre->next = list2;
                pre = pre->next;
                list2 = list2->next;
            }
        }
        while(list1 != nullptr)
        {
            pre->next = list1;
            pre = pre->next;
            list1 = list1->next;
        }
        while(list2 != nullptr)
        {
            pre->next = list2;
            pre = pre->next;
            list2 = list2->next;
        }
        return head->next;
    }
};