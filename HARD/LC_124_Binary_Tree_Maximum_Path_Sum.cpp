class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int global_max = std::numeric_limits<int>::min();
        traverse(root, global_max);
        return global_max;
    }

private:
    int traverse(TreeNode* root, int& global_max)
    {
        if (!root) {
            return 0;
        }
        int l = std::max(0, traverse(root->left, global_max));
        int r = std::max(0, traverse(root->right, global_max));
        int local_max = root->val + l + r;

        global_max = std::max(global_max, local_max);

        return root->val + std::max(l, r);
    }
};
