/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int len(ListNode *head){
        int size = 0;
        
        while(head && head->next){
            size++;
            head = head->next;
        }

        return size;
    }

    ListNode* common(ListNode *head){
        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // int lena = len(headA), lenb = len(headB);
        
        unordered_set<ListNode*> set;
        while(headA){
            set.insert(headA);
            headA = headA->next;
        }

        while(headB){
            if(set.find(headB) != set.end()) return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};