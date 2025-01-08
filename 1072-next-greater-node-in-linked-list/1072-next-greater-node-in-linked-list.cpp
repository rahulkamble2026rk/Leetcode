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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>vct; 
        while(head!=NULL)
        {   
            cout<<head->val;
            vct.push_back(head->val); 
            head=head->next;
        } 
        stack<int>stk; 
        vector<int>ans; 
         
         int n=vct.size();
        for(int i=n-1;i>=0;i--)
        {   
            int x=vct[i];
            while(!stk.empty()&&x>=stk.top())
            {
                stk.pop();
            } 
            if(!stk.empty())
            {
                ans.push_back(stk.top());
            }  
            else
            {
                ans.push_back(0);
            } 
            stk.push(x);
        }  

       reverse(ans.begin(),ans.end());
        return ans;
    }
};