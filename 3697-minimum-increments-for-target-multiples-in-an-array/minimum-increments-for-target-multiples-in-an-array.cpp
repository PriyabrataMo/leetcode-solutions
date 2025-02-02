class Solution {
public:
    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int m = target.size();
        int comb = pow(2, m);
        vector<long long> mpp(comb, 1);
        for (int i = 1; i < comb; i++) {
            long long val = 1;
            for (int j = 0; j < m; j++) {
                int po = pow(2, j);
                if (i & po) {
                    val = lcm(val, target[j]);
                }
            }
            mpp[i] = val;
        }

        vector<long long> dp(comb, 1e18);
        dp[0] = 0;

        for (auto it : nums) {
            vector<long long> cost(comb, 1e18);
            for (int i = 1; i < comb; i++) {
                long long val = mpp[i];
                long long mod = it % val;
                long long amt = (mod == 0 ? 0 : val - mod);
                cost[i] = amt;
            }
            vector<long long> dp2 = dp;
            for (int i = 0; i < comb; i++) {
                if (dp[i] == 1e18)
                    continue;
                for (int j = 1; j < comb; j++) {
                    int cur = i | j;
                    dp2[cur] = min(dp2[cur], dp[i] + cost[j]);
                }
            }
            dp = dp2;
        }

        return dp[comb - 1];
    }
};