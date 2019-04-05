# n         # of jamcoins
#           at least 1 digit that is a 4
#           that key is broken on the printer
#           Send them 2 checks of value
# a + b     Value of n in separate checks

# t         # of test cases
t = int(input())

for i in range(1, t + 1):
    n = int(input())
    lypath = input()

    # We can just invert them for now?
    path = ''
    for c in lypath:
        path += 'E' if c == 'S' else 'S'

    print("Case #{}: {}".format(i, path)) 

