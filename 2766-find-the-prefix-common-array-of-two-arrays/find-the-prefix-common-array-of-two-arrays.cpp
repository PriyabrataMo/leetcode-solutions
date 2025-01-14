class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> fre(n,0);
        int c = 0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            fre[a[i]-1]+=1;
            fre[b[i]-1]+=2;
            for(auto &it:fre){
                if(it==3){
                    c++;
                    it=-1;
                }

            }
            ans[i] = c;

        }
        return ans;
    }
};