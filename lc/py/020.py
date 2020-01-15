class Solution(object):
    def isValidParen(self, s):
        stack = []
        match = {'(' : ')'
