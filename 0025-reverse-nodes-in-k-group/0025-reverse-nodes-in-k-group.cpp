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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* temp=head;  
        int count=k; 
        vector<int>store; 
        stack<ListNode*>stk; 
        
        while(temp!=NULL)
        {
            if(count==0)
            {   
                int ind=0;
                while(!stk.empty())
                {
                    ListNode* temp2=stk.top(); 
                    temp2->val=store[ind]; 
                    ind++; 
                    stk.pop();
                } 
                
               
                store.clear(); 
                count=k;
            } 
            
                
                store.push_back(temp->val); 
                stk.push(temp);  
                --count;
                temp=temp->next;
        } 

            if (count == 0)
        {
            int ind = 0;
            while (!stk.empty())
            {
                ListNode* temp2 = stk.top(); 
                temp2->val = store[ind]; 
                ind++; 
                stk.pop();
            }
        }
        

                return head;
    }
    
};