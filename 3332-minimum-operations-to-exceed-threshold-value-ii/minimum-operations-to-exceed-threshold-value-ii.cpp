class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto it : nums)
            pq.push(it);
        int ans = 0;
        while (pq.size() > 1 && pq.top() < k) {
            long long ele1 = pq.top();
            pq.pop();
            long long ele2 = pq.top();
            pq.pop();
            long long temp = min(ele1, ele2) * 2 + max(ele1, ele2);
            pq.push(temp);
            ans++;
        }
        return ans;
    }
};