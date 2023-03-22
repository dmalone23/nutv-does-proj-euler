def b(n):
    i = 0
    max = 0
    while True:
        next = 2 ** i 
        if n % next == 0:
            max = next 
        i += 1 
        if next >= n:
            return max

A_dict = {}

def A(x):
    if x not in A_dict.keys():
        if x == 0:
            a = 1
        elif x % 2 == 0:
            n = x / 2
            a = (3 * A(n)) + (5 * A((2 * n) - b(n)))
        else:
            n = (x - 1) / 2
            a = A(n)
        A_dict[x] = a 
    return A_dict[x]

def H(t, r):
    return A(((2 ** t) + 1) ** r)

def main():
    i = 0
    #print(((2 ** ((10 ** 14) + 31)) + 1) ** 62)
    # while i < 30:
    #     print("A(" + str(i) + ") = " + str(A(i)))
    #     i += 1
    for t in range(21):
        for r in range(11):
            print("H(" + str(t) + ", " + str(r) + ") = A(" + str(((2 ** t) + 1) ** r) + ") = " + str(H(t,r)))
    #print(H((10 ** 14) + 31, 62))

main()