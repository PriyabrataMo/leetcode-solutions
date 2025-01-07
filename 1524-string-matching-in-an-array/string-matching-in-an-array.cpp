class Solution {
public:
    vector<string> stringMatching(vector<string>& w) {
        int n = w.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    int res = w[j].find(w[i]);
                    if(res!=string::npos){
                        ans.push_back(w[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};