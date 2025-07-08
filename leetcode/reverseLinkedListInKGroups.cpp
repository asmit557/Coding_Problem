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
    ListNode* f1(ListNode* head, int k,int n,int &index){
        if(head==NULL){
           return NULL;
        }
        if(n-index < k){
            return head;
        }
        int count =0;
        ListNode*curr = head;
         ListNode*prev = NULL;
         ListNode*temp = NULL;
        while(curr!=NULL &&  count<k ){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp; 
            index++;
            count++;
        }
        if(curr!=NULL){
            head->next = f1(curr,k,n,index);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        cout<<cnt;

        int index = 0;
        return f1(head,k,cnt,index);
    }
};
