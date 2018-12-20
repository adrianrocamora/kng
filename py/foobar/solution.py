# Write a function answer(n) which returns the smallest positive integer
# base b, at least 2, in which the integer n is a palindrom.
# The input will be "0 <= n <= 1000"
# 0 => 2
# 42 => 4

# TODO: Give a unique "ID", a number should be fine, to each alphabet 
#       symbol within a base. This will scale for when the base goes 
#       beyond 10 

# Returns a list with the numbers that make up the number n in the base
# b
def toBaseB(n, b):
    if b < 2:
        return None
    if n == 0:
        return [0]
    if n == 1:
        return [1]
    res = []
    div = 1;
    while div * b <= n:
        div *= b
    while div > 0: 
        res.append(n / div)
        n = n % div
        div /= b
    return res

def isListPalindrome(li):
    if len(li) <= 1:
        return True
    for idx in range(0, len(li) / 2):
        mirrorIdx = len(li) - idx  - 1
        if li[idx] != li[mirrorIdx]:
            return False
    return True

def answer(n):
    # your code here
    b = 2
    while(not isListPalindrome(toBaseB(n, b))):
        b += 1
    return b
