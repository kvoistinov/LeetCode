/* 14.02.2024
 *
 *  time:   O(N)
 *  memory: O(N)
 */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::vector<std::pair<int, int>> pairs(nums.size() >> 1);
        int i = 0;
        int j = 0;

        for (int v : nums) {
            if (v >= 0) {
                pairs[i].first = v;
                i++;
            }
            else {
                pairs[j].second = v;
                j++;
            }
        }
        i = 0;
        for (auto& p : pairs) {
            nums[i++] = p.first;
            nums[i++] = p.second;
        }
        return nums;
    }
};



/*
 *
 *
 */
