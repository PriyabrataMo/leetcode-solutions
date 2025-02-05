class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c = 0;
        int n = s1.length();
        int ind1 = -1, ind2 = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                c++;
                if (c > 2)
                    return false;
                if (ind1 == -1)
                    ind1 = i;
                else
                    ind2 = i;
            }
        }
        // cout << c << endl;
        // cout << ind1 << " " << ind2 << endl;
        // cout << s1[ind1] << " " << s1[ind2] << " " << s2[ind1] << " "
        //      << s2[ind2] << endl;
        return c == 0 ||
               (c == 2 && s1[ind1] == s2[ind2] && s1[ind2] == s2[ind1]);
    }
};