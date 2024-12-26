class Solution {
public:
    int func(int n, int d, vector<int> &arr) {
    int s = 0;

    for(int i=0;i<n;i++){
        s+=arr[i];
    }
    int tar = s-d;
    if(tar<0||tar%2) return 0;
    int k = tar/2;
    int mod = 1e9+7;
    vector<vector<int>> dp(n,vector<int>(k+1,0));    
    if(arr[0]<=k&&arr[0]!=0) dp[0][arr[0]]=1;
    if(arr[0]==0) dp[0][0]=2;
    else{
        dp[0][0]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int nottake = dp[i-1][j];
            int take = 0;
            if(arr[i]<=j) take = dp[i-1][j-arr[i]];
            dp[i][j] = (take+nottake)%mod;
        }
    }
    return dp[n-1][k];

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = func(n,target,nums);
        return ans;
    }
};