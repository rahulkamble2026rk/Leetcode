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
    ListNode* partition(ListNode* head, int x) 
    {
        
        ListNode* sm=new ListNode(0);  
        ListNode* bg=new ListNode(0);
        ListNode* small=sm; 
        ListNode* big=bg;
        
        
        ListNode* temp=head;  
        
        while(temp!=NULL)
        {
            if(temp->val<x)
            {   
                small->next=temp; 
                small=small->next;
            }   
            else
            {
                big->next=temp; 
                big=big->next;
            }
            temp=temp->next;
        } 
         
        big->next=NULL;
        small->next=bg->next; 
        ListNode* ans=sm->next;
        return ans;
    }
};