class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        if((s1%2==0)&&(s2%2==0)){
            return 0;
        }
        int xo = 0;
        if(s1%2){
            for(auto it:nums2){
                xo^=it;
            }
        }
        if(s2%2){
            for(auto it:nums1){
                xo^=it;
            }
        }
        return xo;
    }
};