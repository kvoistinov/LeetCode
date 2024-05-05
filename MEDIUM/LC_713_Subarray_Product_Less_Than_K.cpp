// To slow:
int numSubarrayProductLessThanK(const std::vector<int>& nums, int k)
{
	int32_t  subs    = 0;

	for (size_t left = 0; left < nums.size(); ++left)
	{
		uint64_t product = 1;
		size_t   right   = left;

		while (right < nums.size()) {
			product *= nums[right];
			
			if (product < k) {
				subs++;
				right++;
			}
			else {
				break;
			}
		}
	}
	return subs;
}


// 01.04.2024 
int numSubarrayProductLessThanK(const std::vector<int>&nums, int k) 
{
	if (k <= 1) {
		return 0;
	}
	uint32_t subs = 0;
	uint32_t left = 0;
	uint32_t right = 0;
	uint64_t product = 1;

	while (right < nums.size())
	{
		product *= nums[right];

		while (left <= right && product >= k)
		{
			product /= nums[left];
			left++;
		}
		subs += (right - left) + 1;
		right++;
	}
	return subs;
}

