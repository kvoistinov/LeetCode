class Solution {
public:
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::unordered_map<std::string, uint32_t> map;
        std::vector<TreeNode*> res;

        inorder(root, map, res);

        return res;
    }

private:
    std::string inorder(
        TreeNode* root, 
        std::unordered_map<std::string, uint32_t>& map, 
        std::vector<TreeNode*>& res
    ) {
        if (!root) {
            return {};
        }

        std::string str = "<";
        str += inorder(root->left, map, res);
        str += std::to_string(root->val);
        str += inorder(root->right, map, res);
        str += ">";

        if (map[str] == 1) {
            res.push_back(root);
        }
        map[str]++;

        return str;
    }
};
