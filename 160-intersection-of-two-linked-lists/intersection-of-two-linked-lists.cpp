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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>st;
        ListNode* tempA = headA;
        while (tempA != NULL) {
            st.insert(tempA);
            tempA = tempA->next;
        }
        while(headB){
            if(st.find(headB)!=st.end()){
                return headB;
            }
            headB=headB->next;
        }
        return NULL;


    }
};