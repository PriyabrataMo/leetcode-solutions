class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,0);
        dp[0] = *min_element(costs.begin() , costs.end());
        for(int i=1;i<n;i++){
            int cost = costs[0]+dp[i-1];
            int ind7 = lower_bound(days.begin(),days.end(),days[i]-6)- days.begin();
            
            if(ind7!=0)cost = min(cost , dp[ind7-1]+costs[1]);
            else cost = min(cost ,costs[1]);
            

            
            int ind30 = lower_bound(days.begin(),days.end(),days[i]-29)- days.begin();
            
            if(ind30!=0)cost = min(cost , dp[ind30-1]+costs[2]);
            else cost = min(cost ,costs[2]);
            
            
            dp[i] = cost;
            cout<<ind7<<" "<<ind30<<" "<<dp[i]<<endl;
        }
        return dp[n-1];
    }
};