class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (true)
        {
            if (fast == nullptr)
            {
                return false;
            }
            fast = fast->next;
            
            if (fast == nullptr)
            {
                return false;
            }   
            fast = fast->next;
            slow = slow->next;
            
            if (fast == slow)
            {
                return true;
            }
        }
    }
};
