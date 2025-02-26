class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = nums[0];
        int curs = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            curs+=nums[i];
            curs=max(curs , nums[i]);
            ans = max(ans , curs);
        }
        for (int i = 0; i < n; i++) {
            nums[i] = -1*nums[i];
        }
        // for(auto it:nums)cout<<it<<" ";
        curs = nums[0];
        ans = max(ans , curs);
        for (int i = 1; i < n; i++) {
            curs+=nums[i];
            curs=max(curs , nums[i]);
            ans = max(ans , curs);
        }
        return ans;
    }
};