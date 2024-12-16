class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        int n = nums.size();
        while (k > 0) {
            int mini = 1e9;
            int ind = -1;
            for (int i = 0; i < n; i++) {
                if(nums[i]<mini){
                    mini = nums[i];
                    ind = i;
                }
            }
            nums[ind]*=m;
            k--;
        }
        return nums;
    }
};