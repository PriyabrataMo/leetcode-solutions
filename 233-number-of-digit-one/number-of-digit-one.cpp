class Solution {
public:
    int countDigitOne(int n) {
        if(n==0) return 0;
        if(n<=9) return 1;
        map<int,int> fre;
        fre[9] = 1;
        for(int i=9;i<(INT_MAX-9)/10;i = (i*10) + 9){
            fre[(i*10) + 9] = (fre[i]*10)+(i+1);
            
        }
        int ans=0;
        int temp = n;
        int lo = log10(temp);
        int div = pow(10 , lo);
        int fd = temp/div;
        int rem = temp%div;
        // cout<<rem<<" "<<fd<<endl;
        ans+=fre[div-1]*fd;
        ans+=fd>1?div : 0;
        ans+= fd==1?rem+1:0;
        ans+=countDigitOne(rem);
        // cout<<ans<<endl;
        return ans;
    }
};