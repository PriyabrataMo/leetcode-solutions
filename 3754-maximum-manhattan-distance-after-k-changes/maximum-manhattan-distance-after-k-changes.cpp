class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int no = 0, so = 0;
        int ea = 0, we = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == 'N')
                no++;
            else if (c == 'S')
                so++;
            else if (c == 'E')
                ea++;
            else if (c == 'W')
                we++;

            int dis = i + 1;
            int dont1 = so + we;
            int res1 = dis - 2 * max(0, dont1 - k);

            int dont2 = so + ea;
            int res2 = dis - 2 * max(0, dont2 - k);

            int dont3 = no + we;
            int res3 = dis - 2 * max(0, dont3 - k);

            int dont4 = no + ea;
            int res4 = dis - 2 * max(0, dont4 - k);

            int res = max(max(res1, res2), max(res3, res4));
            ans = max(ans, res);
        }
        return ans;
    }
};