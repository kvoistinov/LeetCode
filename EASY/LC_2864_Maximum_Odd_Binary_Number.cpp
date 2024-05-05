class Solution {
public:
    std::string maximumOddBinaryNumber(std::string s) {
        int cnt = 0;
        for (auto ch : s) {
            if (ch == '1') {
                cnt++;
            }
        }
        std::string res(s.size(), '0');
        if (cnt == 1) {
            res.back() = '1';
        }
        else if (cnt > 1) {
            for (int i = 0; i < cnt - 1; ++i) {
                res[i] = '1';
            }
            res.back() = '1';
        }
        return res;
    }
};
