class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int max_sum = std::numeric_limits<int>::min();
        int level = 0;
        int level_max = 0;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            size_t size = q.size();
            int level_sum = 0;

            for (size_t i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                level_sum += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ++level;
            if (level_sum > max_sum) {
                max_sum = level_sum;
                level_max = level;
            }
        }
        return level_max;
    }
};
