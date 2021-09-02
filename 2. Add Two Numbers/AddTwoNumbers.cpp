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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool Is_l1_nullptr =false, Is_l2_nullptr = false;
        int ShiftedNum = 0;
        int Sum = 0;
        ListNode* FirstNode = l1, *Prev_l1, *Prev_l2;
        while (!Is_l1_nullptr || !Is_l2_nullptr)
        {
            Is_l1_nullptr = l1 == nullptr;
            Is_l2_nullptr = l2 == nullptr;
            if (!Is_l1_nullptr && !Is_l2_nullptr)
            {
                Sum = l1->val + l2->val + ShiftedNum;
                if(Sum<10)
                {
                    l1->val = Sum;
                    ShiftedNum = 0;
                }
                else
                {
                    l1->val = Sum - 10;
                    ShiftedNum = 1;
                }
                Prev_l1 = l1;
                Prev_l2 = l2;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (!Is_l1_nullptr && Is_l2_nullptr)
            {
                Sum = l1->val + ShiftedNum;
                if (Sum >= 10)
                {
                    l1->val = Sum-10;
                    ShiftedNum = 1;
                }
                else
                {
                    l1->val = Sum;
                    ShiftedNum = 0;
                }
                Prev_l1 = l1;
                l1 = l1->next;
            }
            else if(Is_l1_nullptr && !Is_l2_nullptr)
            {
                Sum = l2->val + ShiftedNum;
                if (Sum >= 10)
                {
                    Prev_l1->next = new ListNode(Sum-10);
                    ShiftedNum = 1;
                }
                else
                {
                    Prev_l1->next = new ListNode(Sum);
                    ShiftedNum = 0;
                }
                Prev_l2 = l2;
                Prev_l1 = Prev_l1->next;
                l2 = l2->next;
            }
            else
            {
                if (ShiftedNum==1)
                {
                    Prev_l1->next = new ListNode(1);
                }
            }            
        }
        return FirstNode;
    }
};