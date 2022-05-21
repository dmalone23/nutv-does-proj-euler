sum_total = 0

with open('numbers.txt','r') as file:
    for line in file:
        sum_total += int(line.strip())

print(''.join(map(str,list(map(int,[x for x in str(sum_total)]))[:10])))