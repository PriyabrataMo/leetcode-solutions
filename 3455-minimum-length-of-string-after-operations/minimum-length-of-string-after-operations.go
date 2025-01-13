func minimumLength(s string) int {
    fre := make([]int , 26)
    for _ , c := range s{
        fre[c-'a']++
    }
    ans:=0
    for _ , occ := range fre{
        if occ%2!=0 {
            ans++
        } else {
            if occ > 0 {
                ans+=2
            }
        }
    }
    return ans
}