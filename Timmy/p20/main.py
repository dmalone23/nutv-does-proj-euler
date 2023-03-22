
def factorial(n):
    p = n
    for i in range(1, n):
        p *= i 
    return p

def sum_of_digits(n):
    nstr = str(n)
    sum = 0
    for i in range(len(nstr)):
        sum += int(nstr[i])

    return sum

def main():
    print("Sum of digits of factorial of 100 is " + str(sum_of_digits(factorial(100))))

main()