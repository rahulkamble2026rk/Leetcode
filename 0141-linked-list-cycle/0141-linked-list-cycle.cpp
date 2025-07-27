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
    bool hasCycle(ListNode *head)   
    {
        //use the unordered_map and check whether that partilcular address is present or not in the map , if found then cycle is present: 

        set<ListNode*>st; 
        ListNode* temp=head; 

        while(temp!=NULL)
        {
            if(st.count(temp)==1)
            {
                return true;
            }  
            st.insert(temp);
            temp=temp->next;
        } 
        return false;
    }
};