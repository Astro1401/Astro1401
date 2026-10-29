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
    int getDecimalValue(ListNode* head) {
        int cnt = 0;
        int ans = 0;

        ListNode* temp = head;

        while(temp->next != nullptr){
            cnt++;
            temp = temp->next;
        }
       
        temp = head;

        while(temp != nullptr){
            if(temp->val == 1){
               ans += pow(2,cnt); 
            }
            cnt--;
            temp = temp->next;
        }
      return ans;
    }
};