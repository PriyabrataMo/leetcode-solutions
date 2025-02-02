class Solution {
public:
    int maxDifference(string s) {
        vector<int> mpp(26, 0);
        for (auto it : s) {
            mpp[it - 'a']++;
        }

        int odd = -1;
        int even = INT_MAX;

        for (auto it : mpp) {
            if (it == 0)
                continue;
            if (it % 2 == 1) {
                odd = max(odd, it);
            } else {
                even = min(even, it);
            }
        }

        return odd - even;
    }
};