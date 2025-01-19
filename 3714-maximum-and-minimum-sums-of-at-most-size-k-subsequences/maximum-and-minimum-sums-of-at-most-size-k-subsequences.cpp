int MOD = 1e9+7;

long long fa[100003], in[100003];

class Solution {
public:
    long long func1(long long b, long long e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1)
                res = (res * b) % MOD;
            b = (b * b) % MOD;
            e >>= 1;
        }
        return res;
    }

    void func2(int n) {
        fa[0] = 1;
        for (int i = 1; i <= n; i++)
            fa[i] = (fa[i - 1] * i) % MOD;
        in[n] = func1(fa[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--)
            in[i] = (in[i + 1] * (i + 1)) % MOD;
    }

    long long func3(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return (fa[n] *
                ((in[r] * in[n - r]) % MOD)) %
               MOD;
    }

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        func2(n);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long contri = 0;
            for (int j = 1; j <= k; j++) {
                contri =
                    (contri + func3(i, j - 1)) % MOD;
            }
            ans = (ans + nums[i] * contri) % MOD;

            long long cont = 0;
            for (int j = 1; j <= k; j++) {
                cont =
                    (cont + func3(n - 1 - i, j - 1)) % MOD;
            }
            ans = (ans + nums[i] * cont) % MOD;
        }

        return ans;
    }
};