class Solution {
public:
    int findDuplicate(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        
        for(int i = 1; i < static_cast<int>(nums.size()); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                return nums[i];
            }
        }
        throw std::invalid_argument("no duplicate numbers");
    }
};

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) 
    {
        std::array<uint16_t, 100'001> arr{};

        for (int v : nums) {
            arr[v]++;
            if (arr[v] > 1) {
                return v;
            }
        }
        return -1;
    }
};
