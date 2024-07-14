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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }
        ListNode* newLL = new ListNode(0);
        ListNode* ans = newLL;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            if(sum>9){
                int tmp = sum;
                sum = sum%10;
                carry = tmp/10;
            }else carry = 0;
            ListNode* newN = new ListNode(sum);
            newLL->next = newN;
            newLL = newLL->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int sum = l1->val + carry;
            if(sum>9){
                int tmp = sum;
                sum = sum%10;
                carry = tmp/10;
            }else{
                carry = 0;
            }
            ListNode* newN = new ListNode(sum);
            newLL->next = newN;
            newLL = newLL->next;
            l1= l1->next;
        }
        while(l2!=NULL){
            int sum = l2->val + carry;
            if(sum>9){
                int tmp = sum;
                sum = sum%10;
                carry = tmp/10;
            }else carry = 0;
            ListNode* newN = new ListNode(sum);
            newLL->next = newN;
            newLL = newLL->next;
            l2= l2->next;
        }
        if(carry!=0){
            newLL->next = new ListNode(carry);
        }
        return ans->next;
    }
};