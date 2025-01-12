class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {

        int m = coins.size();
        int n = coins[0].size();
        int dp[505][505][3];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = INT_MIN;
                }
            }
        }

        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0];
            dp[0][0][1] = 0; 
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[i][j][k] == INT_MIN)
                        continue;
                    for (auto& it : vector<pair<int, int>>{{1, 0}, {0, 1}}) {
                        int ni = i + it.first, nj = j + it.second;
                        if (ni >= m || nj >= n)
                            continue;
                        int val = dp[i][j][k];
                        int c = coins[ni][nj];
                        dp[ni][nj][k] = max(dp[ni][nj][k], val + c);
                        if (c < 0 && k < 2) {
                            dp[ni][nj][k + 1] = max(dp[ni][nj][k + 1], val);
                        }
                    }
                }
            }
        }

        int ans = max(
            {dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});

        return ans;
    }
};