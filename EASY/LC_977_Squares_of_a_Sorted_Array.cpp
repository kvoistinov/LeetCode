class Solution {
public:
    std::vector<int> sortedSquares(const std::vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        std::vector<int> res(nums.size());

        for (int i = nums.size() - 1; i >= 0; i--) 
        {
            int32_t a = nums[left];
            int32_t b = nums[right];

            if (a * a > b * b) {
                res[i] = a * a;
                left++;
            }
            else
            {
                res[i] = b * b;
                right--;
            }
        }
        return res;
    }
};
