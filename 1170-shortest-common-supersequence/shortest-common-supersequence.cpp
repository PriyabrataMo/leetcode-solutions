class Solution {
public:
    string shortestCommonSupersequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        string ans = "";
        int i = n;
        int j = m;
        while(i>0&&j>0){
            if(word1[i-1]==word2[j-1]){
                ans+=word1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+= word1[i-1];
                i--;
            }
            else{
                ans+= word2[j-1];
                j--;
            }
        }
        
            while(j>0){
                ans+=word2[j-1];
                j--;
            }
            while(i>0){
                ans+=word1[i-1];
                i--;
            }
        reverse(ans.begin(),ans.end());
        return ans ;

    }
};