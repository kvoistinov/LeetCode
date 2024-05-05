class Solution {
public:
    std::string customSortString(const std::string& order, std::string& s) 
    {
        std::unordered_map<char, int> map;
        map.reserve(order.size());

        for (size_t i = 0; i < order.size(); ++i) {
            map[order[i]] = i + 1;
        } 
        for (size_t i = 0; i < 26; ++i) {
            if (map.find('a' + i) == map.end()) {
                map.insert(std::make_pair('a' + i, map.size()));
            }
        }
        std::sort(s.data(), s.data() + s.size(), 
            [&map](const char a, const char b)
            {
                return  map[a] < map[b];
            }); 

        return s;      
    }
};
