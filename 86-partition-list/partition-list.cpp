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
    ListNode* partition(ListNode* head, int x) {
        ListNode* slist=new ListNode(0,NULL);
        ListNode* blist=new ListNode(0,NULL);
        ListNode* small=slist;
        ListNode* big=blist;
        while(head){
            if(head->val<x){
                small->next=head;
                small=small->next;
            }
            else{
                big->next=head;
                big=big->next;
            }
            head=head->next;
        }
        small->next=blist->next;
        big->next=NULL;
        ListNode* result=slist->next;
        //no need of slist and blist
        delete slist;
        delete blist;
        return result;
    }
};