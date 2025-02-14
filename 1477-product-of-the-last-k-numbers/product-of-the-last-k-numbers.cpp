class ProductOfNumbers {
public:
    vector<int> pre;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            pre.clear();
            return;
        }
        if(pre.empty()) pre.push_back(num);
        else(pre.push_back(pre[pre.size()-1]*num));
    }
    
    int getProduct(int k) {
        if(pre.size()>k){
            return pre[pre.size()-1]/pre[pre.size()-1-k];
        }
        else if(pre.size()==k){
            return pre[pre.size()-1];
        }
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */