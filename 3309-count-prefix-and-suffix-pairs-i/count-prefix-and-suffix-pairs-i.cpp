class Solution {
public:
    bool func(string& str1, string& str2) {
        int s1 = str1.size(), s2 = str2.size();
        if (s1 > s2)
            return false;
        bool flag = true;
        for(int i=0;i<s1;i++){
            if(str1[i]!=str2[i]) return false;
            if(str1[i]!=str2[s2-s1+i]) return false;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += func(words[i], words[j]);   
            }
        }
        return ans;
    }
};