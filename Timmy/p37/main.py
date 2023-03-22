def is_prime(n):
    if n == 1:
        return False
    for i in range(2, (n/2) + 1):
        if n % i == 0:
            return False
    return True

def get_truncs(n):
    strn = str(n)
    lot = []
    for i in range(len(strn)):
        subl = strn[i: len(strn)]
        subr = strn[0:len(strn)-i]
        lot.append(subl)
        lot.append(subr)
    return lot

def is_trunc(n):
    if len(str(n)) == 1:
        return False
    lot = get_truncs(n)
    for s in lot:
        if not is_prime(int(s)):
            return False
    return True
    # strn = str(n)
    # for i in range(len(strn)):
    #     subl = strn[i: len(strn)]
    #     subr = strn[0:len(strn)-i]
    #     # print(subl)
    #     # print(subr)
    #     if not is_prime(int(subl)) or not is_prime(int(subr)):
    #         return False
    # return True

def get_next_prime(primes):
    n = primes[-1] + 1
    while True:
        np = True
        for p in primes:
            if n % p == 0:
                np = False
                break
        if np:
            primes.append(n)
            return primes 
        else:
            n += 1

def solve2():
    sum = 0
    count = 0
    primes = [2]
    while True:
        primes = get_next_prime(primes)
        n = primes[-1]
        if is_trunc(n):
            sum += n
            count += 1
            print("The {0} trun is {1}".format(count, n))
            if count == 11:
                print(sum)
                return


def solve():
    sum = 0
    i = 10
    count = 0
    while True:
        if is_trunc(i):
            sum += i 
            count += 1
            print("The {0} trun is {1}".format(count, i))
        i += 1
        if count == 11:
            break 
    print(sum)

def main():
    #
    solve2()

main()