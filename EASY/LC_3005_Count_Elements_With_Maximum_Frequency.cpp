class Solution {
public:
    int maxFrequencyElements(const std::vector<int>& nums) {
        int freq[100] = {};

        for (int v : nums) {
            freq[v - 1]++;
        }
        std::sort(&freq[0], freq + 100);
        int res = freq[99];

        for (int i = 99; i >= 1; --i) {
            if (freq[i - 1] == freq[i]) {
                res += freq[i - 1];
            }
            else {
                break;
            }
        }
        return res;
    }
};
