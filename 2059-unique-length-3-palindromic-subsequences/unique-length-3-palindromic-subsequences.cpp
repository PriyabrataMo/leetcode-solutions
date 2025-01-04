#define ff first
#define ss second
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> fre(26 , {-1,-1});

        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(fre[s[i]-'a'].ff==-1){
                fre[s[i]-'a'].ff = i;
            }
            fre[s[i]-'a'].ss = i;
        }
        for(auto it:fre){
            if(it.ss>it.ff&&it.ff!=-1){
                //cout<<it.ss<<" "<<it.ff<<endl;
                ans+= unordered_set(s.begin()+it.ff+1 , s.begin()+it.ss).size();
            }
        }
        return ans;

    }
};