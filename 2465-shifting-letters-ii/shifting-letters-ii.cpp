class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& arr) {
        int n = s.size();
        vector<int> mpp(n + 2, 0);
        for (auto it : arr) {
            // int shift = 1;
            // if (it[2] == 0) {
            //     shift = -1;
            // }
            mpp[it[0]] += 2*it[2]-1;
            mpp[it[1] + 1] -= 2*it[2]-1;
        }

        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre = (pre + mpp[i]) % 26;

            char rep = (((s[i] - 'a') + pre + 26) % 26) + 'a';
            s[i] = rep;
        }
        return s;
    }
};