#pragma GCC optimize("03")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

static const int _ = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* createBinaryTree(const std::vector<std::vector<int>>& descriptions) 
    {
        std::unordered_map<int, TreeNode*> map_value_to_node;
        std::unordered_map<int, int>       map_value_to_parent;

        for (auto& d: descriptions)
        {
            auto parent = map_value_to_node.find(d[0]);

            if (parent == map_value_to_node.end()) {
                TreeNode* new_parent = new TreeNode(d[0]);
                auto res = map_value_to_node.insert({d[0], new_parent});

                parent = res.first;
            }
            TreeNode* child = nullptr;

            if (auto it = map_value_to_node.find(d[1]); it != map_value_to_node.end()) {
                child = it->second;
            }
            else {
                child = new TreeNode(d[1]);
            }
            map_value_to_node[d[1]] = child;

            if (d[2] == 1) {
                parent->second->left = child;
            }
            else {
                parent->second->right = child;  
            }
            map_value_to_parent[d[1]] = d[0];
            auto it_p = map_value_to_parent.find(d[0]);

            if (it_p == map_value_to_parent.end()) {
                map_value_to_parent[d[0]] = -1;
            }
        }
        TreeNode* root = nullptr;

        for (auto vp : map_value_to_parent) {
            if (vp.second == -1) {
                auto it = map_value_to_node.find(vp.first);
                root = it->second;
            }
        }
        return root;
    }
};
