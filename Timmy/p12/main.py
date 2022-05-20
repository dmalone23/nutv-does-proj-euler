import sys 

def get_next_triangle_num(tris):
    last = tris[-1]
    return last + (len(tris) + 1)

def get_factors(n):
    f = []
    for i in range(1, n):
        if n % i == 0:
            f.append(i)
    return f

def main():
    if len(sys.argv) == 1:
        f = 500
    else:
        f = sys.argv[1]
    tris = [1]

    while True:
        next = get_next_triangle_num(tris)
        factors = get_factors(next)
        print("The next triangle number is " + str(next) + " and has " + str(len(factors)) + " factors")
        tris.append(next)
        if len(factors) > f:
            break

main()
        