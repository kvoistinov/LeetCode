class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) {
            return false;
        }
        TreeNode* parent_x = nullptr;
        TreeNode* parent_y = nullptr;
        int depth_x = 0;
        int depth_y = 0;

        dfs(root, 0, x, y, depth_x, depth_y, parent_x, parent_y);

        return (depth_x == depth_y) && (parent_x != parent_y);
    }

private:
    void dfs(TreeNode*  root, 
             int        curr_depth, 
             int        x, 
             int        y, 
             int&       depth_x,
             int&       depth_y,
             TreeNode*& parent_x, 
             TreeNode*& parent_y
    ) 
    {
        if (!root) {
            return;
        }
        if (root->left && root->left->val == x || root->right && root->right->val == x) {
            parent_x = root;
            depth_x  = curr_depth + 1;
            return;
        }
        if (root->left && root->left->val == y || root->right && root->right->val == y) {
            parent_y = root;
            depth_y  = curr_depth + 1;
            return;
        }
        
        dfs(root->left,  curr_depth + 1, x, y, depth_x, depth_y, parent_x, parent_y);
        dfs(root->right, curr_depth + 1, x, y, depth_x, depth_y, parent_x, parent_y);
        
    }
};
