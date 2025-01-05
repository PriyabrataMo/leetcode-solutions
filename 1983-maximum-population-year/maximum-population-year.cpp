class Solution {
public:
    int maximumPopulation(vector<vector<int>>& arr) {
        int c = 0;
        map<int,int> mpp;
        for(auto it:arr){
            mpp[it[0]]++;
            mpp[it[1]]--;
        }
        int maxp = 0;
        int ans;
        for(auto it:mpp){
            c+=it.second;
            if(c>maxp){
                ans = it.first;
                maxp = c;
            }
        }
        return ans;
    }
};