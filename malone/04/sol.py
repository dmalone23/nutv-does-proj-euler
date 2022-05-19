def is_palindrome(x):
    return x == x[::-1]

def sol1():
    m = []

    for x in range(999,99,-1):
        for y in range(999,99,-1):
            if is_palindrome(str(x * y)):
                m.append(x * y)

    return max(m)

def sol2():
    # thanks internet! i found a haskell solution online and realized
    # how easy it was in python
    return max([(i*j) for i in range(100,1000) for j in range(100,1000) if is_palindrome(str(i*j))])

if __name__ == "__main__":
    print(sol1())
    print(sol2())
