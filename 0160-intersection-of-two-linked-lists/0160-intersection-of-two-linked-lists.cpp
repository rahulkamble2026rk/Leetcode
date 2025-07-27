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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)  
    {
        set<ListNode*>st; 
        ListNode* temp=headA; 
        while(temp!=NULL)
        {
            st.insert(temp); 
            temp=temp->next;
        } 

        temp=headB;
        while(temp!=NULL)
        {
            if(st.count(temp)==1)
            {
                return temp;
            } 
            temp=temp->next;
        } 
        return NULL;
    }
};