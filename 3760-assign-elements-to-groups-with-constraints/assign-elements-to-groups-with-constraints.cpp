class Solution {
public:
    vector<int> assignElements(vector<int>& gr, vector<int>& e) {
        int n = gr.size();
        int m = e.size();
        int maxi = 1e5+5;
        vector<int> arr(maxi + 1, INT_MAX);

        for (int j = 0; j < m; j++) {
            int val = e[j];
            arr[val] = min(arr[val], j);
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int ele = gr[i];
            int res = INT_MAX;
            for (int j = 1; j * j <= ele; j++) {
                if (ele % j == 0) {
                    if (j <= maxi && arr[j] != INT_MAX)
                        res = min(res, arr[j]);
                    int temp = ele / j;
                    if (temp != j && temp <= maxi && arr[temp] != INT_MAX)
                        res = min(res, arr[temp]);
                }
            }
            ans[i] = (res != INT_MAX ? res : -1);
        }
        return ans;
    }
};