class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long s;
        for(auto it:nums){
            s+=it;
        }
        long long cs = 0;
        int ans = 0;
        for(long long i=0;i<nums.size()-1;i++){
            cs+=nums[i];
            s-=nums[i];
            if(cs>=s){
                ans++;
            }
        }
        
        return ans;
    }
};