class Solution {
public:
    unordered_map<char, int> mpp;
    bool func(unordered_map<char, int> &mp) {
        for (auto itt : mpp) {

            if (mp[itt.first] < mpp[itt.first]) {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        vector<string> ans;

        for (auto &it : b) {
            unordered_map<char, int> mp;
            for (auto &itt : it) {
                mp[itt]++;
            }
            for(auto it:mp){
                mpp[it.first] = max(mp[it.first] , mpp[it.first]);
            }
        }
        
        for (auto &it : a) {
            unordered_map<char, int> mp;
            for (auto &itt : it) {
                mp[itt]++;
            }
            if(func(mp)){
                ans.push_back(it);
            }
        }
        return ans;
    }
};