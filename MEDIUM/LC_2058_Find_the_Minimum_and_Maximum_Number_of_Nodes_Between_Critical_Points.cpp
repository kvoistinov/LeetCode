 static const int _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
 }();

class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::vector<int> critical_points;
        std::vector<int> min_max_dist{ -1, -1};


        ListNode* prev = nullptr;
        ListNode* mid  = nullptr;
        ListNode* next = head;

        if (next) {
            prev = next;
            next = next->next;
        }
        if (next) {
            mid = next;
            next = next->next;
        }
        int pos = 3;
        while (next != nullptr) {
            if (prev->val < mid->val && mid->val > next->val || 
                prev->val > mid->val && mid->val < next->val) 
            {
                critical_points.push_back(pos);
            }
            prev = mid;
            mid  = next;
            next = next->next;
            pos++;
        }
        if (critical_points.size() < 2) {
            return min_max_dist;
        }
        int min_dist = std::numeric_limits<int>::max();

        for (size_t i = 1; i < critical_points.size(); ++i) {
            int curr_dist = critical_points[i] - critical_points[i - 1];

            if (curr_dist < min_dist) {
                min_dist = curr_dist;
            }
        }
        min_max_dist[0] = min_dist;
        min_max_dist[1] = critical_points.back() - critical_points.front();

        return min_max_dist;
    }
};
