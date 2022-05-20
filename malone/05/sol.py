# TODO: HINT: use math properties, 1*2*3*4*5*6*7*8*9*10?
def dbf20(x):
  for i in range(1,21):
    if x % i != 0:
      print(f"*** {x} NOT DIVISIBLE BY {i}")
      break
    else:
      print(f"{x} divisible by {i}")
