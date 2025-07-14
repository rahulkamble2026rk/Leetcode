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
    int getDecimalValue(ListNode* head)  
    { 
        vector<int>vct;
        if(head==NULL) 
        {
            return 0;
        }  
        while(head!=NULL) 
        {
              vct.push_back(head->val);
              head=head->next;
        } 
        reverse(vct.begin(),vct.end());
        int sum=0;
        for(int i=0;i<vct.size();i++) 
        {
            sum=sum+std::pow(2,i)*vct[i];
        } 
        return sum;
    }
};