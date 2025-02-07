class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> mpp;
        map<int,int> st;
        vector<int> ans;
        for(auto it:queries){
            // cout<<it[0]<<endl;
            // cout<<it[1]<<endl;
            if(mpp.find(it[0])==mpp.end()){
                
                mpp[it[0]] = it[1];
                st[it[1]]++;
            }
            else{
                int color = mpp[it[0]];
                st[color]--;
                if(st[color]==0){
                    
                    st.erase(color);
                }
                mpp[it[0]] = it[1];
                st[it[1]]++;
            }
            // for(auto itt:st){
            //     cout<<itt.first<<endl;
            // }
            //cout<<endl;
            ans.push_back(st.size());
        }
        return ans;
    }
};