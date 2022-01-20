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
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom()
    {
        //蓄水池容量为1（只要随机选一个数字即可）
        int reservoir = head->val;
        int index = 1;//记录ptr指向当前链表的前一个位置
        ListNode* ptr = head->next;
        while(ptr != nullptr)
        {
            index++;
            int d = rand()%index;
            if(d == 0)
            {
                reservoir = ptr->val;
            }
            ptr = ptr->next;
        }
        return reservoir;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */