# 26 unique, increasing and sorted prime numbers smaller than N
# smallest is A
# decrypt msg has no spacing

# crypt msg = prim(msg[0])*prim(msg[1]) + ...
#             prim(msg[1])*prim(msg[2]) + ...
#             ... +
#             prim(msg[:-1])*prim(msg[:]) + ...


# INPUT 
# cypher message
# N

# OUTPUT
# decrypted message


t = int(input())

for i in range(1, t + 1):
    n, l = [int(s) for s in input().split(" ")] 
    crymsg = [int(s) for s in input().split(" ")] 

    def gcd(x, y): 
        while(y): x, y = y, x % y 
        return x 

    primes = []

    for j in range(l - 1):
        primes.append(gcd(crymsg[j], crymsg[j+1]))

    primes.insert(0, crymsg[0] // primes[0])
    primes.append(crymsg[l-1]//primes[l-1])
    primes.sort()
    print(primes)
    primes_set = set(primes)
    print(primes_set)
    print(len(primes_set))
    prim = list(primes_set)
    print(prim)
    print(len(prim))

    abc = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

    prime_to_char = { prim[x] : abc[x] for x in range(26)}
    #char_to_prime = { abc[x] : primes[x] for x in range(26)}

    print(prime_to_char)
    #print(char_to_prime)

    def get_prime_pair(num, primes):
        for a in primes:
            if num % a == 0:
                b = num // a
                return a, b
            else:
                continue

    tuple_list = []
    for c in crymsg:
        tuple_list.append(get_prime_pair(c, prim))
#    print(tuple_list)

    prime_msg = []
    for t in tuple_list:
        prime_msg.append(t[0])
    prime_msg.append(tuple_list[-1][1])
    print(prime_msg)

    msg_li = []
    for p in prime_msg:
        msg_li.append(prime_to_char[p])

    msg = ''.join(msg_li)

    print("Case #{}: {}".format(i, msg)) 

