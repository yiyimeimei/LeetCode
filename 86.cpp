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
    ListNode* partition(ListNode* head, int x) {
        ListNode *head1, *head2, *cur1, *cur2;

        cur1 = new ListNode();
        cur2 = new ListNode();
        head1 = cur1;
        head2 = cur2;
        while(head != nullptr)
        {
            if(head->val < x)
            {
                ListNode *temp = new ListNode(head->val);
                cur1->next = temp;
                cur1 = temp;
            }
            else
            {
                ListNode *temp = new ListNode(head->val);
                cur2->next = temp;
                cur2 = temp;
            }
            head = head->next;
        }
        cur1->next = head2->next;
        delete head2;
        return head1->next;
    }
};