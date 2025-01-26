class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int s = 0;
        for(auto it:nums)s+=it;
        int cs = 0;
        int ans = 0;
        for(int i=0;i<nums.size()-1;i++){
            s-=nums[i];
            cs+=nums[i];
            if((cs-s)%2==0){
                ans++;
            }
        }
        return ans;
    }
};