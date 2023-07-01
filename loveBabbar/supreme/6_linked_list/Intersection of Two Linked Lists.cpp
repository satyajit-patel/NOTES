/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummyHead1 = headA;
        ListNode* dummyHead2 = headB;
        while(dummyHead1 != dummyHead2) {
            if(dummyHead1 != NULL && dummyHead2 != NULL)
                std::cout<<dummyHead1->val<<" "<<dummyHead2->val<<std::endl;
            dummyHead1 = (dummyHead1 == NULL) ? headB : dummyHead1->next;
            dummyHead2 = (dummyHead2 == NULL) ? headA : dummyHead2->next;
        }
        return dummyHead2; // return any dummyHead
    }
};