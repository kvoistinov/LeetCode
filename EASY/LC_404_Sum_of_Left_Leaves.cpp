// 14.04.2024
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        std::stack<TreeNode*> st;
        TreeNode* curr = root;
        int sum = 0;

        while (!st.empty() || curr)
        {
            if (curr) {
                st.push(curr);
                curr = curr->left;

                if (curr && (!curr->left && !curr->right)) {
                    sum += curr->val;
                }
            }
            else {
                curr = st.top();
                st.pop();
                curr = curr->right;
                    
            }
        }
        return sum;
    }
};

// 
class Solution {
private:
	int solve(TreeNode* root)
    {
        if(!root) {
			return 0;
		}
        int sum = 0;

        if (root->left && !root->left->left && !root->left->right) {
			sum += root->left->val;
        }
        sum += solve(root -> left);          
        sum += solve(root -> right);

        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root)
	{
        return solve(root);
    }
};
