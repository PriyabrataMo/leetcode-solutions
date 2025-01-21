class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long s1 = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long s2 = 0;
        long long mini = LLONG_MAX;
        for (long long i = 0; i < n; i++) {
            s1-=grid[0][i];
            mini = min(mini , max(s1,s2));
            s2+=grid[1][i];
        }

        return mini;
    }
};