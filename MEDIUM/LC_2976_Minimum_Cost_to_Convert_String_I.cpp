// 
// Runtime 68ms    Beats 99.88%
// Memory  94.27MB Beats 91.31%
//

const auto _ = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    long long minimumCost(
        const std::string        source, 
        const std::string        target, 
        const std::vector<char>& original, 
        const std::vector<char>& changed, 
        const std::vector<int>&  cost
    ) 
    {
        if (source == target) {
            return 0;
        }
        uint64_t INF = std::numeric_limits<uint64_t>::max();
        uint64_t g[26][26];
        
        for (size_t i = 0; i < 26; ++i)
        {
            std::memset(&g[i], 0xFF, 208);
        }

        for (size_t i = 0; i < original.size(); ++i) 
        {
            uint64_t curr_cost = g[original[i] - 'a'][changed[i] - 'a'];

            if (curr_cost == INF || curr_cost > cost[i]) {
                g[original[i] - 'a'][changed[i] - 'a'] = cost[i];
            }
        }   

        for (size_t k = 0; k < 26; ++k) 
        {
            for (size_t i = 0; i < 26; ++i) 
            {
                for (size_t j = 0; j < 26; ++j) 
                {
                    if (g[i][j] > (g[i][k] + g[k][j]) && (g[k][j] != INF && g[i][k] != INF))
                    {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                } 
            }
        }
        uint64_t total_cost = 0;

        for (size_t i = 0; i < source.size(); ++i)
        {
            if (source[i] != target[i]) {
                uint64_t cost = g[source[i] - 'a'][target[i] - 'a'];

                if (cost == INF) {
                    return -1;
                }
                total_cost += cost;
            }
        }
        return total_cost;
    }
};
