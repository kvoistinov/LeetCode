// 15
class Solution {
public:
    std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums) 
    {
        std::unordered_map<int, int> mapped_nums;

        for (auto& num : nums) {
            if (auto it = mapped_nums.find(num); it == mapped_nums.end()) {
                std::string s_num = std::to_string(num);

                for (size_t i = 0; i < s_num.size(); ++i) {
                    s_num[i] = mapping[s_num[i] - '0'] + '0';
                }
                mapped_nums[num] = std::stoi(s_num);
            }
        }
        std::stable_sort(nums.begin(), nums.end(),
            [&mapped_nums](const auto& num1, const auto& num2)
            {
                return mapped_nums[num1] < mapped_nums[num2];
            }
        );
        return nums;
    }
};

