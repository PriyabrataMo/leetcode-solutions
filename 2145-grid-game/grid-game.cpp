class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> pre1(n, 0), pre2(n, 0);
        pre2[n - 1] = grid[1][n - 1];
        pre1[0] = grid[0][0];
        for (long long i = n - 2; i >= 0; i--) {
            pre2[i] = pre2[i + 1] + grid[1][i];
        }
        for (long long i = 1; i < n; i++) {
            pre1[i] = pre1[i - 1] + grid[0][i];
        }
        // for(auto it:pre1)cout<<it<<" ";
        // cout<<endl;
        long long s1 = pre1[n - 1];
        long long s2 = pre2[0];

        long long mini = s1+s2;
        long long ind = -1;
        for (long long i = 0; i < n; i++) {
            long long val = max(s1-pre1[i] , s2-pre2[i]); 
            if (val < mini) {
                mini = val;
                
            }
        }

        return mini;
    }
};