class Solution {
public:
    int minOperations(const std::vector<std::string>& logs) {
        std::stack<std::string> st;

        for (auto& op : logs) {
            if (op == "../" && st.size() > 0) {
                st.pop();
            }
            else if (op != "./" && op != "../") {
                st.push(op);
            }
        }
        return st.size();
    }
};
