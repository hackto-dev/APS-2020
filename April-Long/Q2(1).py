from sys import stdin

t = int(stdin.readline())

while t > 0:
    n = int(stdin.readline())

    l = list(map(int,stdin.readline().split()))

    dist = []

    for i in range(n):
        if(l[i] == 1):
            