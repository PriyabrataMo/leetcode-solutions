class Solution {
public:
    bool func(const string& str1, const string& str2) {
        int s1 = str1.size(), s2 = str2.size();
        if (s1 > s2)
            return false;
        return str2.substr(0, s1) == str1 && str2.substr(s2 - s1) == str1;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (func(words[i], words[j])) {
                   ans = ans+1;
                }
            }
        }
        return ans;
    }
};