
def getPrimesBelow(n):
    primes = []
    for i in range(2, n):
        isPrime = True 
        for p in primes:
            if p > i/2:
                break
            if i % p == 0:
                isPrime = False 
                break 
        if isPrime:
            print("PRIME AT {0}".format(str(i)))
            primes.append(i)
    return primes

def isCircularPrime(p):
    p_str = str(p)
    if len(p_str) == 1:
        return True
    else:
        pass
    return False

def getCircles(p):
    circle = []
    nstr = str(p)
    for i in range(len(nstr)-1):
        first_char = nstr[0]
        nstr = nstr[1: len(nstr)] + first_char
        circle.append(int(nstr))
    return circle

def flipStr(str):
    l = len(str)
    flip = ""
    for i in range(l):
        flip += str[l - (i+1): l-i]
    return flip

def getCircularPrimesBelow(n):
    all_primes = getPrimesBelow(n)
    print("FOUND ALL PRIMES")
    cir_primes = []
    for p in all_primes:
        if p in cir_primes:
            continue
        # Check if circular
        p_str = str(p)
        if len(p_str) == 1:
            cir_primes.append(p)
            continue
        else:
            cirs = getCircles(p)
            allp = True 
            for c in cirs:
                if c not in all_primes:
                    allp = False
                    break
            if allp:
                cir_primes.append(p)
    return cir_primes


def main():
    print(len(getCircularPrimesBelow(1000000)))
main()