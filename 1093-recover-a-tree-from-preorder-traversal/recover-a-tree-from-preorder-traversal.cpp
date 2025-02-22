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
    TreeNode* recoverFromPreorder(string s) {
        unordered_map<int,vector<TreeNode*>> mpp;
        int dep=0;
        int n = s.length();
        int num=0;
        int i=0;
        while(i<n&&s[i]!='-'){
            num = num*10+(s[i]-'0');
            i++;
        }
        TreeNode* root = new TreeNode(num);
        mpp[0].push_back(root);
        
        for(;i<n;i++){
            if(s[i]=='-'){
                dep++;
            }
            else{
                num=0;
                while(i<n&&s[i]!='-'){
                    num = num*10+(s[i]-'0');
                    i++;
                }
                // cout<<i<<endl;
                TreeNode* newNode = new TreeNode(num);
                mpp[dep].push_back(newNode);
                // // cout<<dep<<endl;
                if(mpp[dep-1].back()->left==NULL){
                    mpp[dep-1].back()->left=newNode;
                }
                else{
                    mpp[dep-1].back()->right=newNode;
                }
                dep=1;
            }
        }
        // for(auto it:mpp){
        //     cout<<it.first<<endl;
        //     for(auto itt:it.second){

        //         cout<<itt->val<<" ";
        //     }
        //     cout<<endl;
        //     // cout<<"dhjfs"<<endl;
        // }
        return root;
    }
};