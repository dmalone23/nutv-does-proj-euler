import sys 

def is_prime(n):
    for i in range(2, n):
        if n % i == 0:
            return False 
    return True




def main():
    if len(sys.argv) > 1:
        val = int(sys.argv[1])
    else:
        val = 600851475143
    i = 2
    while True:
        if val % i == 0:
            if is_prime(int(val/i)):
                print(str(i) + " is a factor with " + str(val/i) + " which a prime")
                return 0

        i += 1

main()