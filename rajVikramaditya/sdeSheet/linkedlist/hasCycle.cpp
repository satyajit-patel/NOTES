/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//https://leetcode.com/problems/linked-list-cycle/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* tortoise = head;
        ListNode* rabbit = head;
        while(rabbit && rabbit->next) {
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
            if(tortoise == rabbit) return true;
        }
        return false;
    }
};