# if N is 3 and the bit pattern is 00010011, the next patterns would be 00010101, 00010110, 00011001, 00011010, 00011100, 00100011,
# and so forth.

v = 17

t = (v | (v - 1)) + 1

w = t | ((((t & -t) / (v & -v)) >> 1) - 1)

print(w)