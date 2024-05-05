// 07.04.2024
class Solution {
public:
    std::string minRemoveToMakeValid(const std::string& s) 
    {
        std::stack<std::pair<char, size_t>> st;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') {
                st.push( {')', i} );
            }
            else if (s[i] == ')') {
                if (st.size() > 0 && st.top().first == ')') {
                    st.pop();
                }
                else {
                    st.push( {'*', i} );
                }
            }
        }
        if (st.empty()) {
            return s;
        }
        std::string res(s);

        while (!st.empty()) {
            res.erase(st.top().second, 1);
            st.pop();
        }

        return res;
    }
};
