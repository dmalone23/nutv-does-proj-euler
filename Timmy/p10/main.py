
def get_next_prime(primes):
    last = primes[-1] + 1
    while True:
        is_prime = True 
        for p in primes:
            if last % p == 0:
                is_prime = False 
                break
        if is_prime:
            return last
        last += 1


def sum_vector(v):
    sum = 0
    for i in v:
        sum += i
    return sum



def main():
    primes = [2, 3]
    while True:
        next = get_next_prime(primes)
        if next < 2000000:
            primes.append(next)
        else:
            break
    print("Sum of primes under 2,000,000 is " + str(sum_vector(primes)))

main()