class Solution {
public:
    vector<int> minOperations(string arr) {
        int n = arr.length();
        int presum = 0, sufsum = 0;
        vector<int> ans(n, 0);
        int b = 0;
        if (arr[0] == '1')
            b = 1;

        for (int i = 1; i < n; i++) {
            presum += b;
            ans[i] += presum;
            if (arr[i] == '1')
                b++;
        }
        b = 0;
        if (arr[n - 1] == '1')
            b = 1;
        for (int i = n - 2; i >= 0; i--) {
            sufsum += b;
            ans[i] += sufsum;
            if (arr[i] == '1')
                b++;
        }
        return ans;
    }
};