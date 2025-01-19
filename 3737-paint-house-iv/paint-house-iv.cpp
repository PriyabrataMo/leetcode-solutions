class Solution {
public:
    long long minCost(int n, vector<vector<int>>& nums) {
        vector<pair<int, int>> p = {{0, 1}, {0, 2}, {1, 0},
                                         {1, 2}, {2, 0}, {2, 1}};

        vector<vector<long long>> pri(n / 2, vector<long long>(6));
        for (int i = 0; i < n / 2; i++) {
            for (int s = 0; s < 6; s++) {
                int c1 = p[s].first;
                int c2 = p[s].second;
                pri[i][s] = nums[i][c1] + nums[n - 1 - i][c2];
            }
        }

        vector<vector<int>> adjacen(6);
        for (int s1 = 0; s1 < 6; s1++) {
            for (int s2 = 0; s2 < 6; s2++) {
                if (p[s1].first != p[s2].first &&
                    p[s1].second != p[s2].second) {
                    adjacen[s1].push_back(s2);
                }
            }
        }

        vector<long long> dp(6, LLONG_MAX), dp2(6, LLONG_MAX);
        for (int s = 0; s < 6; s++) {
            dp[s] = pri[0][s];
        }
        for (int i = 1; i < n / 2; i++) {
            for (int s = 0; s < 6; s++) {
                dp2[s] = LLONG_MAX;
            }
            for (int s1 = 0; s1 < 6; s1++) {
                for (int j = 0; j < adjacen[s1].size(); j++) {
                    int s2 = adjacen[s1][j];
                    dp2[s2] = min(dp2[s2], dp[s1] + pri[i][s2]);
                }
            }
            dp = dp2;
        }

        long long ans = *min_element(dp.begin(), dp.end());
        return ans;
    }
};