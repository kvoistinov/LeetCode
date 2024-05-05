class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = head;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = nullptr;
        head = prev;

        return head;
    }
};
