class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> fre(n,0);
        int c = 0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            fre[a[i]-1]+=1;
            if(fre[a[i]-1]==2)c++;

            fre[b[i]-1]+=1;
            if(fre[b[i]-1]==2)c++;
            ans[i] = c;
            
            

        }
        return ans;
    }
};