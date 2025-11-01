#include <unordered_set>

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        // Use an unordered_set for efficient O(1) lookup
        set<int> numSet(nums.begin(), nums.end());
        
        ListNode* p = head; 
        ListNode* q = head != nullptr ? head->next : nullptr;  
       
        // Handle the case where the head node should be deleted
        while (head != nullptr && numSet.find(head->val) != numSet.end()) {
            head = head->next;  // Move the head to the first valid node
        }

        // If all nodes are deleted, return NULL
        if (head == nullptr) {
            return nullptr;
        }

        // Traverse the list starting from p and q
        while(q != nullptr) 
        {
            if (numSet.find(q->val) != numSet.end()) 
            {
                q = q->next;  // Skip q if its value is in nums
            } 
            else 
            {  
                p->next = q;  // Link p to q
                p = q;        // Move p to q
                q = q->next;  // Move q forward
            }
        }  

        // Ensure the last node points to null
        p->next = nullptr;

        return head;    
    }
};
