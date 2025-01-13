class Solution {
public:
    int minimumLength(string s) {
        vector<int> fre(26,0);
        for (auto& it : s) {
            fre[it - 'a']++;
        }
        
        int ans = 0;
        for (auto& it : fre) {
            cout<<it<<endl;
            if (it % 2)
                ans += 1;
            else
                ans += it?2:0;

            cout<<ans<<endl;
        }
        return ans;
    }
};