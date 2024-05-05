class Solution {
public:
    std::vector<int> intersection(
                        /*const*/ std::vector<int>& a, 
                        /*const*/ std::vector<int>& b
    ) 
    {
        std::vector<int> result;

        std::sort(std::begin(a), std::end(a));
        std::sort(std::begin(b), std::end(b));

        int pos_a = 0;
        int pos_b = 0;
        int prev = -1;

        while (pos_a < a.size() && pos_b < b.size())
        {
            if (a[pos_a] == b[pos_b] && prev != a[pos_a])
            {
                prev = a[pos_a];
                result.push_back(a[pos_a]);
                pos_a++;
                pos_b++;
            }
            else if (a[pos_a] < b[pos_b])
            {
                pos_a++;
            }
            else
            {
                pos_b++;
            }
        }

        return result;
    }
};
