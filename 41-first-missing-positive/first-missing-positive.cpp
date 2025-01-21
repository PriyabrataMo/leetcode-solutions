class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // set<int> s;
        int n = nums.size();
        // for(int i=0;i<n;i++){
        //     s.insert(nums[i]);
        // }
        // for(int i=1;i<1e5+5;i++){
        //     if(s.find(i)==s.end()){
        //         return i;
        //     }
        // }
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(x==i+1) continue;
            while(x>0&&x<n+1&&x!=i+1&&nums[x-1]!=x){
                swap(nums[i] , nums[x-1]);
                x = nums[i];
            }
            
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        
        return n+1;
    }
};