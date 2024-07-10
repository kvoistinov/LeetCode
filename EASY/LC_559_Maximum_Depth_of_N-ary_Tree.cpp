class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int max_depth = 0;
        dfs(root, max_depth);

        return max_depth + 1;
    }
private:
    int dfs(Node* root, int& max_depth) {
        if (!root) {
            return 0;
        }
        int local_max_depth = 0;
        for (size_t i = 0; i < root->children.size(); ++i) {
            int curr_depth = dfs(root->children[i], max_depth) + 1;
            local_max_depth = std::max(local_max_depth, curr_depth);
            max_depth = std::max(max_depth, curr_depth);
        }
        return local_max_depth;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) {
            return 0;
        }
        int maxi = 1; 

        for (auto child : root->children) {
            maxi = std::max(maxi, 1 + maxDepth(child));
        }
        return maxi;
    }
};
