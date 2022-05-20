def get_seq_terms(i):
    count = 1

    while i != 1:
        if i % 2 == 0:
            i /= 2
        else:
            i = (3*i) + 1
        count += 1
    return count


def main():
    max = -1
    maxInd = -1
    for i in range(1,1000000):
        terms = get_seq_terms(i)
        #print("The seq that starts with " + str(i) + " has " + str(terms) + " terms.")
        if terms > max:
            max = terms 
            maxInd = i 
    print("The starting number " + str(maxInd) + " has the most terms with " + str(max) + " terms.")


main()