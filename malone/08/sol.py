import functools

number = []
with open('number.txt','r') as file:
    for line in file:
        number.append(line.strip())
number = int(''.join(number))

desired_sequence_length = 13

def int_to_int_arr(x):
    return list(map(int,[x for x in str(x)]))

def largest_series_product(x, desired_sequence_length):
    x_list = int_to_int_arr(x)
    current_sequence = [x_list[0]]
    current_sequence_length = len(current_sequence)
    current_sequence_product = functools.reduce(lambda x, y: x * y,current_sequence,1) # fold function in python
    current_optimal_product = 0
    position = 0
    while position < len(x_list):
        if x_list[position] == 0:
            current_sequence.clear()
            position += 1
            continue

        if current_sequence_length == desired_sequence_length:
            if x_list[position] * functools.reduce(lambda x, y: x * y,current_sequence[1:],1) >= current_optimal_product:
                current_optimal_product = x_list[position] * functools.reduce(lambda x, y: x * y,current_sequence[1:],1)
            current_sequence = current_sequence[1:]
            current_sequence.append(x_list[position])
        else:
            if x_list[position] * current_sequence_product >= current_optimal_product:
                current_optimal_product = x_list[position] * current_sequence_product
            current_sequence.append(x_list[position])

        position += 1
        current_sequence_length = len(current_sequence)
        current_sequence_product = functools.reduce(lambda x, y: x * y,current_sequence,1)
    
    return current_optimal_product

print(largest_series_product(number,desired_sequence_length))