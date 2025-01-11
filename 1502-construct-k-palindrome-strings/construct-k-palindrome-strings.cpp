class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        vector<int> fre(26,0);
        for (char &c : s) {
            fre[c-'a']++;
        }

        int ans = 0;
        for (auto& it : fre) {
            if (it % 2 != 0) ans++;
        }

        return ans <= k;
    }
};