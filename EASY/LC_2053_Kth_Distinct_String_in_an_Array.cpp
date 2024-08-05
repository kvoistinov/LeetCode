// Time: O(N) | Memory: O(N)

class Solution {
public:
    std::string kthDistinct(std::vector<std::string>& arr, int k) 
    {
        std::unordered_map<std::string, std::size_t> str_map;

        for (auto& s : arr) {
            str_map[s]++;
        }
        std::string res = "";

        for (size_t i = 0; i < arr.size(); ++i) {
            if (str_map[arr[i]] == 1 && !(--k)) {
                res = arr[i];
                break;
            }
        }
        return res;
    }
};
