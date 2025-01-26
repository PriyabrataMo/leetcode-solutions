class Solution {
public:
    bool static comp(vector<string>& a, vector<string>& b) {
        int timea = stoi(a[1]);
        int timeb = stoi(b[1]);
        if (timea != timeb)
            return timea < timeb;
        return (a[0] == "OFFLINE" && b[0] != "OFFLINE");
    }
    vector<int> countMentions(int n, vector<vector<string>>& e) {
        vector<int> off(n, 0);
        vector<int> ans(n, 0);

        sort(e.begin(), e.end(),comp);
             
        for (auto& it : e) {
            if (it[0] == "OFFLINE") {
                int t = stoi(it[1]);
                int u = stoi(it[2]);
                off[u] = 60 + t;
            } else if (it[0] == "MESSAGE") {
                vector<bool> ison(n, false);
                int t = stoi(it[1]);
                string str = it[2];

                for (int i = 0; i < n; i++) {
                    if (off[i] <= t) {
                        ison[i] = true;
                    }
                }
                if (str == "HERE") {

                    for (int i = 0; i < n; i++) {
                        if (ison[i]) {
                            ans[i]++;
                        }
                    }
                } else if (str == "ALL") {
                    for (int i = 0; i < n; i++) {
                        ans[i]++;
                    }

                } else {
                    istringstream ss(str);
                    string word;
                    while (ss >> word) {
                        int id = stoi(word.substr(2));
                        ans[id]++;
                        // cout<<id<<endl;
                    }
                }
            }
        }
        return ans;
    }
};