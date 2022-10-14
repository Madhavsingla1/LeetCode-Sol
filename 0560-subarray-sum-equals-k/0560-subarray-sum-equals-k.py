class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = {}
        mp[0]=1
        res=sums=0
        
        for i in nums:
            sums+=i
            if sums-k in mp:
                res+=mp[sums-k]
            if sums in mp:
                mp[sums]+=1
            else:
                mp[sums]=1
            
        return res