vector<int> compute_PLE(const vector<int>& nums) {
    int n = nums.size();
    vector<int> PLE(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        PLE[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return PLE;
}

vector<int> compute_NLE(const vector<int>& nums) {
    int n = nums.size();
    vector<int> NLE(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        NLE[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return NLE;
}

vector<int> compute_PGE(const vector<int>& nums) {
    int n = nums.size();
    vector<int> PGE(n, -1);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        PGE[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return PGE;
}

vector<int> compute_NGE(const vector<int>& nums) {
    int n = nums.size();
    vector<int> NGE(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        NGE[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return NGE;
}

long long calculate_count(int a_prev, int d_next, int i, int k, int n) {
    if (d_next < i) {
        return 0;
    }
    int A = max(a_prev, i - k + 1);
    if (A > i) {
        return 0;
    }
    int x = d_next - k + 1;
    int B = min(i, x);
    long long sum1 = 0;
    if (A <= B) {
        int terms = B - A + 1;
        sum1 = static_cast<long long>(k - i) * terms;
        sum1 += (static_cast<long long>(B) * (B + 1)) / 2 - (static_cast<long long>(A - 1) * A) / 2;
    }
    int C = max(B + 1, A);
    int D = i;
    long long sum2 = 0;
    if (C <= D) {
        int terms2 = D - C + 1;
        sum2 = static_cast<long long>(d_next - i + 1) * terms2;
    }
    return sum1 + sum2;
}

class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        auto PLE = compute_PLE(nums);
        auto NLE = compute_NLE(nums);
        auto PGE = compute_PGE(nums);
        auto NGE = compute_NGE(nums);

        long long sum_min = 0;
        for (int i = 0; i < n; ++i) {
            int a_prev = PLE[i] + 1;
            int d_next = NLE[i] - 1;
            sum_min += static_cast<long long>(nums[i]) * calculate_count(a_prev, d_next, i, k, n);
        }

        long long sum_max = 0;
        for (int i = 0; i < n; ++i) {
            int a_prev = PGE[i] + 1;
            int d_next = NGE[i] - 1;
            sum_max += static_cast<long long>(nums[i]) * calculate_count(a_prev, d_next, i, k, n);
        }

        return sum_min + sum_max;
    }
};