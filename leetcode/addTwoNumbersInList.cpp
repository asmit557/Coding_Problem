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
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
         ListNode* head1 = first;
         ListNode* head2 = second;
         ListNode* dummy = new ListNode(-1);
         ListNode* ans = dummy;
          int carry = 0;
          int sum = 0;
         while(head1!=NULL || head2!=NULL){
             sum = 0;
            if(head1) sum += head1->val;
            if(head2) sum += head2->val;
            sum += carry;

            ListNode* temp = new ListNode(sum % 10);
            dummy->next = temp;
            dummy = temp;
            carry = sum/10; 
            if(head1) head1 = head1->next;
            if(head2) head2 = head2->next;
         }
         if(carry!=0){
            ListNode* temp = new ListNode(carry);
            dummy->next = temp;
            dummy = temp;
         }
         return ans->next;
    }
};
