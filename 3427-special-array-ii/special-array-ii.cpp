class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& q) {
    int n = a.size();
    vector<int> pre(n);
    vector<bool> ans;

    for (int i = 0; i < n-1; ++i) {
        if (a[i] % 2 != a[i + 1] % 2) {
            pre[i] = 1;
        } else {
            pre[i] = 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        pre[i] += pre[i - 1];
    }

    for (auto it : q) {
        int f = it[0];
        int s = it[1];
        int req = s - f;
        int sum;

        if (f == s) {
            ans.push_back(true);
            continue;
        }

        if (f == 0) {
            sum = pre[s - 1];
        } else {
            sum = pre[s - 1] - pre[f - 1];
        }

        if (sum == req) {
            ans.push_back(true);
        } else {
            ans.push_back(false);
        }
    }

    return ans;
        
    }
};