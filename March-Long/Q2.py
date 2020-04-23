from sys import stdin

set_bits = [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4]


def countBits(n):
    count = 0

    while n > 0:
        count += set_bits[n & 0xf]
        n = n >> 4

    return count


t = int(stdin.readline())

for _ in range(t):
    n, q = map(int, stdin.readline().split())
    l = list(map(int, stdin.readline().split()))

    odd = 0

    for i in l:
        if (countBits(i) & 1):
            odd += 1

    even = n - odd

    while q > 0:
        p = int(stdin.readline())

        if(countBits(p) & 1):
            print(odd, even)

        else:
            print(even, odd)

        q -= 1
