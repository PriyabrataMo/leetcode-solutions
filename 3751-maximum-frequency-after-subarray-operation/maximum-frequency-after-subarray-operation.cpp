class Solution {
public:
    int func(vector<int>& arr) {
        if (arr.empty())
            return 0;
        int cur = arr[0];
        int maxi1 = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            cur = max(arr[i], cur + arr[i]);
            maxi1 = max(maxi1, cur);
        }
        return maxi1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int ext = 0;
        int cnt = 0;
        for (auto it : nums) {
            if (it == k)
                cnt++;
        }
        for (int i = 1; i <= 50; i++) {
            if (i == k) continue; 
            vector<int> temp;
            temp.reserve(n);
            for (auto it : nums) {
                if (it == i) {
                    temp.push_back(1);
                } else if (it == k) {
                    temp.push_back(-1);
                } else {
                    temp.push_back(0);
                }
            }
            int cur = func(temp);
            if (cur > ext) {
                ext = cur;
            }
        }
        return cnt + ext;
    }
};