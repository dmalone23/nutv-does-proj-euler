
def even_div(n):
    for i in range(1,21):
        if n % i != 0:
            return False 
    return True

def main():
    i = 21
    while True:
        if even_div(i):
            print(i)
            return 0
        i+=1

main()