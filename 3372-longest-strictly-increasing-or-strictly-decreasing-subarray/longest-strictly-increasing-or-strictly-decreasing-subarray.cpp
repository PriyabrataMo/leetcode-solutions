class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int asc = 1, dsc = 1;
        int ans = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                asc++;
                dsc = 1;
            } else if (nums[i] < nums[i - 1]) {
                dsc++;
                asc = 1;
            } else {
                asc = 1;
                dsc = 1;
            }
            ans = max(ans , max(dsc , asc));
        }
        return ans;
    }
};