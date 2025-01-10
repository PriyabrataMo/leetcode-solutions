class Solution {
public:
    vector<int> mpp;
    bool func(vector<int>& mp) {
        for (int i = 0; i < 26; i++) {

            if (mp[i] < mpp[i]) {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        vector<string> ans;
        mpp.resize(26,0);
        for (auto& it : b) {
            vector<int> mp(26,0);
            for (auto& itt : it) {
                mp[itt - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                mpp[i] = max(mp[i], mpp[i]);
            }
        }
        // for (auto it : mpp) {
        //     cout << it << " ";
        // }
        //cout << endl;

        for (auto& it : a) {
            vector<int> mp2(26,0);
            for (auto& itt : it) {
                mp2[itt - 'a']++;
            }
            // for (auto it : mp2) {
            //     cout << it << " ";
            // }
            // cout << endl;
            if (func(mp2)) {
                ans.emplace_back(it);
            }
        }
        return ans;
    }
};