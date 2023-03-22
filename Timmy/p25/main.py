F = {}

def fib(i):
    if i == 1 or i == 2:
        F[i] = 1
    else:
        F[i] = F[i-1] + F[i-2]
    return F[i]

def main():
    i = 1
    max_digits = 1
    while True:
        next = fib(i)
        if len(str(next)) > max_digits:
            max_digits = len(str(next))
            if max_digits == 1000:
                print("F[{0}] has {1} digits".format(str(i), str(max_digits)))
                return
            
        i += 1

main()