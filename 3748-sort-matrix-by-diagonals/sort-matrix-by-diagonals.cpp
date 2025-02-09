class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int, vector<int>> mpp;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mpp[i - j].push_back(grid[i][j]);
            }
        }
        for (auto& it : mpp) {
            int ind = it.first;
            if (ind >= 0) { 
                sort(it.second.begin(), it.second.end(), greater<int>());
            } else {
                sort(it.second.begin(), it.second.end());
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ind = i - j;
                grid[i][j] = mpp[ind].front();
                mpp[ind].erase(mpp[ind].begin());
            }
        }
        return grid;
    }
};