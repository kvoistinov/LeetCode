static const int _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode  tmp{};
        ListNode* curr              = head;
        ListNode* result_list       = &tmp;
        int32_t   curr_interval_sum = 0;

        while (curr) 
        {
            if (curr->val == 0 && curr_interval_sum != 0) {
                result_list->next = new ListNode(curr_interval_sum);
                result_list       = result_list->next;
                curr_interval_sum = 0;
            }
            else if (curr->val != 0) {
                curr_interval_sum += curr->val;
            }
            curr = curr->next;
        }

        return tmp.next;
    }
};
