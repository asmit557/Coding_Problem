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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> ans;
        if(head==NULL){
            return NULL;
        }
        ListNode* temp = head;
        while(head){
            ans.push_back(head->val);
            head = head->next;
        }
        head = temp;
        k = k % ans.size();
        reverse(ans.begin(),ans.end());
        reverse(ans.begin(),ans.begin()+k);
        reverse(ans.begin()+k,ans.end());
        int index = 0;
        while(temp){
           temp->val = ans[index];
           index++;
           temp = temp->next;
        }
        return head;

    }
};
