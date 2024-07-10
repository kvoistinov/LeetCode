 static const int _ = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
 }();

class Solution {
public:
    std::vector<int> largestValues(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::vector<int> res;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t level_size = q.size();
            int level_max = std::numeric_limits<int>::min();

            for (size_t i = 0; i < level_size; ++i) {
                TreeNode* curr_node = q.front();
                q.pop();

                level_max = std::max(level_max, curr_node->val);

                if (curr_node->left) {
                    q.push(curr_node->left);
                }
                if (curr_node->right) {
                    q.push(curr_node->right);
                }
            }
            res.push_back(level_max);
        }
        return res;
    }
};
