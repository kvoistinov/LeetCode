class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* prev_l1 = list1;
        ListNode* curr_l1 = list1->next;

        while (b--) {
            if (--a > 0) {
                prev_l1 = curr_l1;
            }
            curr_l1 = curr_l1->next;
        }
        ListNode* d_start = prev_l1->next;

        while (d_start != curr_l1) {
            ListNode* d_node = d_start;
            d_start = d_start->next;

            delete d_node;
        }
        prev_l1->next = list2;
     
        while (list2->next != nullptr) {
                list2 = list2->next;
        }
        list2->next = curr_l1;

        return list1;
    }
};
