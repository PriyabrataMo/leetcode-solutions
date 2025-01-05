class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& arr) {
        int n = s.size();
        vector<int> mpp(n + 2, 0);
        for (auto &it : arr) {
            mpp[it[0]] += 2*it[2]-1;
            mpp[it[1] + 1] -= 2*it[2]-1;
        }

        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre = (pre + mpp[i]) % 26;

            s[i] = (((s[i] - 'a') + pre + 26) % 26) + 'a';
        }
        return s;
    }
};