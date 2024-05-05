class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) 
    {
        std::vector<std::vector<int>> result(2);
        std::set<int>      winners;
        std::map<int, int> lossers;

        for (size_t i = 0; i < matches.size(); ++i) {
            auto pair_1 = winners.insert(matches[i][0]);
            lossers[matches[i][1]]++;

        }
        for (auto it_b = lossers.begin(),
                  it_e = lossers.end(); it_b != it_e; ++it_b) 
        {
            auto it = winners.find(it_b->first);
            if (it != winners.end()) {
                winners.erase(it);
            }
        }
        for (auto it_b = winners.begin(),
                  it_e = winners.end(); it_b != it_e; ++it_b) 
        {
            result[0].push_back(*it_b);
        }
        for (auto it_b = lossers.begin(),
                  it_e = lossers.end(); it_b != it_e; ++it_b) 
        {
            if (it_b->second == 1) {
                result[1].push_back(it_b->first);
            }
        }
        return result;
    }
};

