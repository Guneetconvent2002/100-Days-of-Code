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
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        stack<int> st;

        while(slow){
            st.push(slow->val);
            slow = slow->next;
        }

        slow = head;
        int sum = INT_MIN;
        while(!st.empty()){
            sum = max(sum, slow->val + st.top());
            st.pop();
            slow = slow->next;
        }

        return sum;
    }
};