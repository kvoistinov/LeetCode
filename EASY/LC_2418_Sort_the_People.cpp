// 1
#include <execution>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights)
    {
        std::vector<std::pair<std::string, int>> pairs{};

        for (std::size_t i = 0; i < names.size(); i++) {
            pairs.push_back(std::make_pair(names[i], heights[i]));
        }
        std::sort(std::execution::par_unseq, pairs.begin(), pairs.end(), 
            [](const auto& a, const auto& b) -> bool
            {
                return a.second > b.second;
            }
        );
        std::vector<std::string> ret;

        for (const auto& p : pairs) {
            ret.push_back(p.first);
        }

        return ret;
    }
};

// 2
class Solution {
public:
    std::vector<string> sortPeople(const std::vector<std::string>& names, const std::vector<int>& heights) 
    {
        std::vector<uint16_t> indices(names.size());
        std::iota(indices.begin(), indices.end(), 0);

        std::sort(indices.begin(),  indices.end(),
            [&heights](const uint16_t i1, const uint16_t i2)
            {
                return heights[i1] > heights[i2];
            }
        );
        std::vector<std::string> res(names.size());

        for (size_t i = 0; i < names.size(); ++i) {
            res[i] = names[indices[i]];
        }

        return res;
    }
};


// 3
class Solution {
public:
	std::vector<std::string> sortPeople(std::vector<string>& names, std::vector<int>& heights) {
        const size_t n = names.size();

        for (size_t i = 0; i < n; i++) {
            heights[i] = (heights[i] << 10) + i;
		}
		std::sort(heights.begin(), heights.end(), greater<>());

		std::vector<std::string> ans(n);

        for(size_t i = 0; i < n; i++) {
            ans[i] = names[heights[i] & 1023];
		}
        return ans;    
    }
};
