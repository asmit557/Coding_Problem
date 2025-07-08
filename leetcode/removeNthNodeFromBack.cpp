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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* curr = head;
        while(head){
            cnt++;
            head=head->next;
        }
        head = curr;
        n = cnt - n;
        if(n==0){
            return curr->next;
        }
        ListNode* prev = NULL;
        int index = 0;
        while(index<n){
            prev = curr;
            curr = curr->next;
            index++;
        }
        prev->next = curr->next;
        return head;
    }
};
