def getPrimeSumsUnder(max):
    primeSums = {}
    last_prime = 0
    for i in range(2, max):
        prime = True
        for p in primeSums.keys():
            if i % p == 0:
                prime = False
                break 
        if prime:
            primeSums[i] = {1: i}
            if last_prime > 0:
                for k in primeSums[last_prime].keys():
                    primeSums[i][k+1] = primeSums[last_prime][k] + i
            last_prime = i
    return primeSums

def getPrimes(max):
    primes = []
    for i in range(2, max):
        prime = True
        for p in primes:
            if i % p == 0:
                prime = False
                break 
        if prime:
            primes.append(i)
    print("GOT ALL " + str(len(primes)) + " primes.")
    return primes

def findMaxSeq(primeSums):
    max_seq_length = 0
    sum = 0
    for p in primeSums.keys():
        for length in primeSums[p].keys():
            if length > max_seq_length and primeSums[p][length] in primeSums.keys():
                max_seq_length = length
                sum = primeSums[p][length]
    print("MAX SEQ LENGTH = " + str(max_seq_length))
    print("SUM = " + str(sum))


def main():
    getPrimes(1000000)
    #findMaxSeq(getPrimeSumsUnder(100000))
main()