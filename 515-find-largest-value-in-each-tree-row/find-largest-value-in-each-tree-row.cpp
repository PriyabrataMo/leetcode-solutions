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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int> ans;
        if(root==NULL) return {};
        while(!q.empty()){
            int sz = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<sz;i++){
                auto it = q.front();
                q.pop();
                maxi = max(it->val , maxi);
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};