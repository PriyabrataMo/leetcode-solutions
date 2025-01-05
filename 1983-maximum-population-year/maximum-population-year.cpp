class Solution {
public:
    int maximumPopulation(vector<vector<int>>& arr) {
        int c = 0;
        vector<int> mpp(110 , 0);
        
        for(auto it:arr){
            mpp[it[0]-1950]++;
            mpp[it[1]-1950]--;
        }
        int maxp = 0;
        int ans;
        for(int i=0;i<110;i++){
            c+=mpp[i];
            if(c>maxp){
                ans = i+1950;
                maxp = c;
            }
        }
        return ans;
    }
};