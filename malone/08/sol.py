import functools

number = 123123123123998999123123123123
desired_sequence_length = 4

def int_to_int_arr(x):
    return list(map(int,[x for x in str(x)]))

def largest_series_product(x, desired_sequence_length):
    x_list = int_to_int_arr(x)
    current_sequence = [x_list[0]]
    current_sequence_length = len(current_sequence)
    current_product = functools.reduce(lambda x, y: x * y,current_sequence,1)
    position = 0
    while position < len(x_list):
        # TODO: variables for best current product, etc (like p-values for weighted interval scheduling)
        # TODO: if x_list[position] == 0, then clear the array and continue to next iteration
        if x_list[position] == 0:
            pass
        if current_sequence_length == desired_sequence_length:
            # TODO: check if x_list[position] * (product of all elements in current sequence minus the first one) >= current optimal product;
            # TODO: if it is, then remove the element at the front of the list and push x_list[position] to the back of the list
            # TODO: example: if we have [1, 2, 3, 4, 5] and we want to add 6, then we get [2, 3, 4, 5, 6] (remove 1 from front, and push 6 to back) (like q queue)
            pass
        else:
            # TODO: check if x_list[position] * current_product >= current optimal product; if it is, then add x_list[position] to the current sequence
            pass
        # TODO: recalculate everything

largest_series_product(number,4)