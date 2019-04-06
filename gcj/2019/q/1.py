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

    # here they are each as big as possible
    a = math.floor(n/2)
    b = n - a

    ## Careful, we might land in a "bad area"
    # Like 4444444

    def is_pair_good(a, b):
        for c in str(a):
            if c == '4':
                return False
        for c in str(b):
            if c == '4':
                return False
        return True

    def get_next_candidates(a, b):
        a -= 1
        b += 1
        return a, b
    
    while not is_pair_good(a, b):
        a, b = get_next_candidates(a, b)
    
    print("Case #{}: {} {}".format(i, a, b)) 

