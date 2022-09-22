class Solution:
    def isPalindrome(self, x: int) -> bool:
        d= f'{x}'
        return d==d[::-1]
        