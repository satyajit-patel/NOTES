/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* rabbit = head;
        ListNode* entry = head;
        while(rabbit && rabbit->next) {
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
            if(tortoise == rabbit) {
                while(entry != tortoise) {
                    tortoise = tortoise->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};