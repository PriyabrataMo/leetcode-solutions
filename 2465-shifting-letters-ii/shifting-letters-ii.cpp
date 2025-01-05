class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& arr) {
        int n = s.size();
        vector<int> mpp(n+2 , 0);
        for(auto it:arr){
            int shift = 1;
            if(it[2]==0){
                shift = 25;
            }

            mpp[it[0]]+=shift;
            mpp[it[1]+1]-=shift;
        }
        // for(auto it:mpp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int pre = 0;
        for(int i=0;i<n;i++){
            pre+=mpp[i];
            char c = s[i];
            char rep = (((s[i]-'a')+pre)%26)+'a';
            s[i] = rep;
        }
        return s;
    }
   
};