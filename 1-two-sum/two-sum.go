func twoSum(nums []int, target int) []int {
    var mpp = make(map[int]int)
    var ans =[]int{-1,-1}
    for i , ele := range nums {
        value , ok := mpp[target - ele]
        if ok {
            ans[0] = i
            ans[1] = value
            return ans
        }
        mpp[ele] = i;
    }
    return ans;
}