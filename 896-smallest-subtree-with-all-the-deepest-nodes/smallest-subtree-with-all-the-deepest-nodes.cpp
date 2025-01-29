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
    pair<int , TreeNode*> dfs(TreeNode* root){
        
        int dp1 = 0 , dp2 = 0;
        TreeNode* node1;
        TreeNode* node2;
        if(root->left!=NULL){
            auto it = dfs(root->left);
            dp1 = it.first;
            node1 = it.second;
        }
        if(root->right!=NULL){
            auto it = dfs(root->right);
            dp2 = it.first;
            node2 = it.second;
        }
        cout<<root->val<<" "<<dp1<<" "<<dp2<<endl;
        if(dp1==dp2){
            return {dp1+1 , root};
        }
        else if(dp1>dp2){
            return {dp1+1 , node1};
        }
        return {dp2+1 , node2};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL) return NULL;
        return dfs(root).second;
    }
};