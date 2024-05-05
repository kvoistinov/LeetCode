class Solution {
public:
    void reorderList(ListNode* head) {
        if ( head             == nullptr || 
             head->next       == nullptr || 
             head->next->next == nullptr )
        {
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while ( fast != nullptr && fast->next != nullptr ) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head_1 = head;
        ListNode* head_2 = slow->next;

        ListNode* prev = nullptr;
        slow->next     = nullptr;

        while (head_2 != nullptr) 
        {
            ListNode* temp = head_2->next;
            head_2->next   = prev;
            prev           = head_2;
            head_2         = temp;
        }
        head_2 = prev;

        while (head_2 != nullptr) 
        {
            ListNode* next_1 = head_1->next;
            ListNode* next_2 = head_2->next;

            head_1->next = head_2;
            head_2->next = next_1;

            head_1 = next_1;
            head_2 = next_2;
        }
    }
};
