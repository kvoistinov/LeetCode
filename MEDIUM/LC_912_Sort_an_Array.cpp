/*	STL
 *	std::sort()
 *	std::stable_sort()
 */
class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) 
    {
        return (std::sort(nums.begin(), nums.end()), nums);
    }
};






/*
 *
 *
 */
