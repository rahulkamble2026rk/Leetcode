class Solution {
public:
    ListNode* oddEvenList(ListNode* head)  
    {
        if (!head || !head->next) return head;

        ListNode* odd = head; 
        ListNode* even = head->next; 
        ListNode* evenHead = even;  // store for final link

        while (even && even->next)
        {
            odd->next = even->next;  // link next odd
            odd = odd->next;

            even->next = odd->next;  // link next even
            even = even->next;
        } 

        odd->next = evenHead;  // attach even list at the end of odd
        return head;
    }
};
