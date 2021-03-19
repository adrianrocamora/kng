# 727 starting
# 738 done loading and printing
# 750 tested with sample
# 751 submitting, failed Wrong Answer, there was an edge case surely
# 757 submitting 2nd attempt
# 800 trying O(n**2) approach for now
# 809 found that I didn't remove debug logs, it might work with the code from 748

# max num of houses you can buy?
# N houses, Ai prices, B budget
# T num test cases
# N B
# A0, A1,.. A(N-1)

# out
# One line
# Case #x: y (x starts at 1, y is max num of houses you can buy)

t = int(input())
for i in range(t):
    n_b = input()
    n = int(n_b.split(' ')[0])
    b = int(n_b.split(' ')[1])
    a = input()
    a = a.split(' ')
    a = [int(a_str) for a_str in a]

    """ O(n*log n)"""
    a_sort = a
    a_sort.sort() # ascending now

    if a_sort[0] > b:
        y = 0
    else:
        curr_houses = 0
        curr_spent = 0
        for idx in range(n):
            curr_houses += 1
            curr_spent += a_sort[idx]
            if idx == n - 1:
                break
            if curr_spent + a_sort[idx+1] > b:
                break
        y = curr_houses

    print('Case #' + str(i+1) + ': ' + str(y))