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
    ListNode* fun(ListNode* temp, int k) 
    {
        int cnt=1;
        while(temp!=NULL)
        {
            if(cnt==k)
            {
                return temp;
            }
            cnt++;

            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL||k==0)
        {
            return head;
        }
        ListNode *tail=head;
        int count=1;
        
        while(tail->next)
        {
            count++;
            tail=tail->next;

        }
        if(k%count==0)
        {
            return head;
        }
        k=k%count;
        tail->next=head;

        ListNode *newnode =fun(head,count-k);
        
        head=newnode->next;
        newnode->next=NULL;
        
        
        
        return head;

    }
};