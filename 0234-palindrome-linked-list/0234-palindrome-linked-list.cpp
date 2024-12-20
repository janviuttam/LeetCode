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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode *p=head;
        while(p){
            s.push(p->val);
            p=p->next;
        }
        p=head;
        while (p){
            if(p->val==s.top()){
                s.pop();
                p=p->next;
            }
            else{
                return false;
            }
           
        }
        return true;
    }   
};