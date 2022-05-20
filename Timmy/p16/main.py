
def main():
    full_str = str(2**1000)
    sum = 0
    for i in range(len(full_str)):
        sum += int(full_str[i])
    print(sum)

main()