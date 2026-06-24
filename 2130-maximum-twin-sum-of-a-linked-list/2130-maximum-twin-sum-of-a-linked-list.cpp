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
    int pairSum(ListNode* head)  
    {
        // n is the even , known as the twin (n-1-i)th node, if 0<=i<=(n/2)-1 

        vector<int>store;  
        ListNode* temp=head;
        while(temp!=NULL)
        {
            store.push_back(temp->val); 
            temp=temp->next;
        } 
 
        int maxi=-1; 

        for(int i=0;i<=(store.size()/2)-1;i++)
        {
            maxi=max(maxi,store[i]+store[store.size()-1-i]);
        } 

        return maxi;
    }
};