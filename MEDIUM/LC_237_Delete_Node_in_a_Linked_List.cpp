// O(1)
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* next = node->next;
        *node = *next;
        
        delete next;
    }
};

// O(N)
