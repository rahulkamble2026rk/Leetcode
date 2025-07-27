/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
         set<ListNode*>st; 
        ListNode* temp=head; 

        while(temp!=NULL)
        {
            if(st.count(temp)==1)
            {
                return temp;
            }  
            st.insert(temp);
            temp=temp->next;
        } 
        return NULL;
    }
};