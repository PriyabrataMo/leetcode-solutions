class Solution {
public:
    int minimumLength(string s) {
        vector<int> fre(26, 0);
        for (auto &it : s) {
            fre[it - 'a']++;
        }
        int ans = 0;
        for (auto& it : fre) {
            if (it >= 2) {
                if (it % 2)
                    ans += 1;
                else
                    ans += 2;
            } else
                ans += it;
        }
        return ans;
    }
};