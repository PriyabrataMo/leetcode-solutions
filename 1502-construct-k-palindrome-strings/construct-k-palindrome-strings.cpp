class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        vector<int> fre(26,0);
        for (char &c : s) {
            fre[c-'a']++;
        }

        int oddCount = 0;
        for (auto& entry : fre) {
            if (entry % 2 != 0) oddCount++;
        }

        return oddCount <= k;
    }
};