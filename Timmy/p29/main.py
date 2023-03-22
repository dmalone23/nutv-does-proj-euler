
def get_set(minA, maxA, minB, maxB):
    all = []
    for a in range(minA, maxA+1):
        for b in range(minB, maxB+1):
            #print("{0} ** {1} = {2}".format(a,b, a**b))
            all.append(a ** b)
    all = list(set(all))
    return len(all)

def main():
    print(get_set(2,100,2,100))

main()