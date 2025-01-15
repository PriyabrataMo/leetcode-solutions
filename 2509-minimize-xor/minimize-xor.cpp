class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> n2(num2);
        bitset<32> n1(num1);
        int one1 = n1.count();
        int one2 = n2.count();
        cout<<one1<<" "<<one2<<endl;
        if(one1==one2) return num1;
        bitset<32> ans;
        for(int i=31;i>=0;i--){
            if(n1[i]==1&&one2>0){
                
                one2--;
                ans[i] = 1;
            }
            
        }
        for(int i=0;i<=31;i++){
            if(n1[i]==0&&one2>0){
                one2--;
                ans[i] = 1;
            }
        }
        return  static_cast<int>(ans.to_ulong());

    }
};