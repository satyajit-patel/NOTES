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
            dummyHead1 = (dummyHead1 == NULL) ? headB : dummyHead1->next;
            dummyHead2 = (dummyHead2 == NULL) ? headA : dummyHead2->next;
        }
        return dummyHead1;
    }
};