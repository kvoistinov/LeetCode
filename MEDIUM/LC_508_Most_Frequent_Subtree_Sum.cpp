/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root,unordered_map<int,int>& rec,int &maximum){
        if(!root){
            return 0;
        }
        int left = dfs(root->left, rec, maximum);
        int right = dfs(root->right, rec, maximum);
        int tree = left+right+root->val;
        
        maximum = max(maximum,++rec[tree]);
        return tree;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> rec;
        int maximum = 0;
        dfs(root,rec,maximum);
        
        vector<int> ans;
        for(auto& it:rec){
            if(it.second == maximum){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// ускорение - зачем лишние действия, если можем отслеживать сумму с макс частотой
class Solution {
public:
    int dfs(TreeNode* root,unordered_map<int,int>& rec,int &maximum){
        if(!root){
            return 0;
        }
        int left = dfs(root->left, rec, maximum);
        int right = dfs(root->right, rec, maximum);
        int tree = left+right+root->val;
        
        maximum = max(maximum,++rec[tree]);
        return tree;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> rec;
        int maximum = 0;
        dfs(root,rec,maximum);
        
        vector<int> ans;
        for(auto& it:rec){
            if(it.second == maximum){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
