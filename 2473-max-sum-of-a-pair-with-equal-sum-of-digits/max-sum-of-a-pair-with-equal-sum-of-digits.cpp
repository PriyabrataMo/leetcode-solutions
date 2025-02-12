class Solution {
public:
    int sum(int n){
        int res = 0;
        while(n>0){
            res+=n%10;
            n = n/10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        vector<int> sums(85,-1);
        int ans = -1;
        for(auto it:nums){
            int s = sum(it);
            if(sums[s]!=-1){
                ans = max(ans , sums[s]+it);
                sums[s] = max(sums[s] , it);
            }
            else{
                sums[s] = it;
            }
        }
        
        return ans;
    }
};