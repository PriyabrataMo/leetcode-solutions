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
        unordered_map<int,vector<int>> mpp;
        for(auto it:nums){
            int s = sum(it);
            mpp[s].push_back(it);
        }
        int ans=-1;
        for(auto it:mpp){
            auto arr = it.second;
            if(arr.size()<2) continue;
            sort(arr.begin() , arr.end());
            reverse(arr.begin() , arr.end());
            ans = max(ans , arr[0]+arr[1]);
        }
        return ans;
    }
};