class Solution {
public:
    vector<int> minOperations(string arr) {
        int n = arr.length();
        vector<int> pre(n,0) , suf(n,0);
        
        vector<int>ans (n,0);
        if(arr[0]=='1')pre[0] = 1;
        int s =0;
        for(int i=1;i<n;i++){
            s+=pre[i-1];
            if(arr[i]=='1')pre[i] = pre[i-1]+1;
            else pre[i] = pre[i-1];
            ans[i] += s;
            
        }
        s=0;
        if(arr[n-1]=='1')suf[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            s+=suf[i+1];
            if(arr[i]=='1')suf[i] = suf[i+1]+1;
            else suf[i] = suf[i+1];
            ans[i]+=s;
        }
        return ans;
    }
};