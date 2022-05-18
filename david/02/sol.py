import sys

def sol(n):

    # iterative memoized fibonacci algorithm
    if n == 0 or n == 1:
        return 0
    if n == 2:
        return 1
    m = [0]*(n+1)
    m[0] = 0
    m[1] = 0
    m[2] = 1
    for i in range(3,n+1):
        if m[i-1] > 4000000: # from problem description
            break
        m[i] = m[i-1] + m[i-2]

    # filter out the odd numbers and sum the list
    return sum(filter(lambda x: x % 2 == 0,m))

if __name__ == "__main__":
    print(sol(1000000)) # big-ass number
