class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 1;
        int l = 0;
        int r = 1;
        int n = nums.size();
        multiset<int> ms;
        ms.insert(nums[0]);
        while (r < n) {
            int maxi = *ms.rbegin();
            int mini = *ms.begin();
            while (l < n && l < r &&
                   (abs(maxi - nums[r]) > 2 || abs(mini - nums[r]) > 2)) {

                auto it = ms.find(nums[l]);

                ms.erase(it);
                if (ms.size() == 0)
                    break;
                maxi = *ms.rbegin();
                mini = *ms.begin();
                l++;
            }
            ms.insert(nums[r]);
            long long sz = ms.size();
            ans += sz;
            r++;
        }
        return ans;
    }
};