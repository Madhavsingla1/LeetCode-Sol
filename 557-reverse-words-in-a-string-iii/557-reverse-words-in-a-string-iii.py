class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split()
        ans = ""
        for word in s:
            ans+=(word[::-1]+' ')
        return ans.strip();