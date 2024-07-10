static int _ = [](){ 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr); 
    return 0;
}();

// O(NlogN)
class Solution {
public:
    int minDifference(std::vector<int>& nums) 
    {
        if (nums.size() <= 4)
            return 0;
        
        std::sort(nums.begin(), nums.end());

        int min_diff = std::min(std::min(nums[nums.size() - 4] - nums[0], nums[nums.size() - 1] - nums[3]),
                                std::min(nums[nums.size() - 2] - nums[2], nums[nums.size() - 3] - nums[1]) ); 

        return min_diff;
    }
};

