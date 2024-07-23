// 1
class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) 
    {
        std::unordered_map<int, int> freq;

        for (auto& v : nums) {
            freq[v]++;
        }
        std::sort(nums.begin(), nums.end(),
            [&freq](const auto& a, const auto& b)
            {
                if (freq[a] < freq[b]) {
                    return true;
                }
                else if (freq[a] == freq[b]) {
                    return a > b;
                }
                return false;
            }
        );
        return nums;
    }
};
