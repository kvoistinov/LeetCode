class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) 
    {
        std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            int idx = std::abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                result.push_back(idx + 1);
            }
            else {
                nums[idx] = -nums[idx];
            }
        }
        return result;
    }
};


#include <bit>
#include <vector>

class Solution {
public:
	std::vector<int> findDuplicates(const std::vector<int>& nums)
    {
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(NULL);

        std::bitset<100001> cache;
        std::vector<int>    result;

        for (const int& n : nums) {
            bool duplicate = cache.test(n);

            if (duplicate) {
                result.push_back(n);
            }
            else {
                cache.set(n);
            }
        }
        return result;
    }
};
