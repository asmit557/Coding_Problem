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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
         ListNode*temp1 = head1;
    ListNode*temp2 = head2;
    ListNode*temp = new ListNode(-1);
    ListNode*head = temp;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val <= temp2->val){
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
            
        }
        else if(temp1->val > temp2->val){
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    while(temp1!=NULL){
         temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
    }
    while(temp2!=NULL){
         temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
    }
    return head->next;
    }
};
