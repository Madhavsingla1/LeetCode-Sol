class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        d = s.strip()
        k = d.split(" ")
        return len(k[-1])
        