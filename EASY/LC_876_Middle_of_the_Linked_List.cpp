class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        return slowPtr;
    }
};
