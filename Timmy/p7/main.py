def get_next_prime(primes):
    i = primes[len(primes)-1] + 1
    while True:
        prime = True
        for p in primes:
            if i % p == 0:
                prime = False
                break 
        if prime:
            return i 
        else:
            i += 1

def main():
    primes = [2, 3, 5, 7, 11, 13]

    while len(primes) < 10001:
        next = get_next_prime(primes)
        primes.append(next)
    print("The 10001st digit is " + str(primes[-1]))

main()