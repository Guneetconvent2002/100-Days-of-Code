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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        
        ListNode* first = head, *next = head->next;
        
        while(first && next){
            swap(first->val, next->val);
            first = first->next->next ? first->next->next : NULL;
            next = first && first->next ? first->next : NULL;
        }

        return head;
    }
};