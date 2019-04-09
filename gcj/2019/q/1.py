# n         # of jamcoins
#           at least 1 digit that is a 4
#           that key is broken on the printer
#           Send them 2 checks of value
# a + b     Value of n in separate checks

# t         # of test cases
t = int(input())

import math

for i in range(1, t + 1):
    n = int(input())

    lut = {
            '0': ('0', '0'),
            '1': ('0', '1'),
            '2': ('1', '1'),
            '3': ('1', '2'),
            '4': ('2', '2'),
            '5': ('2', '3'),
            '6': ('3', '3'),
            '7': ('2', '5'),
            '8': ('2', '6'),
            '9': ('3', '6')
            }

    nstr = str(n)

    ali = []  
    bli = []
    for c in nstr:
        ali.append(lut[c][0])
        bli.append(lut[c][1])

    astr = ''.join(ali)
    bstr = ''.join(bli)

    a = int(astr)
    b = int(bstr)
    
    print("Case #{}: {} {}".format(i, a, b)) 

