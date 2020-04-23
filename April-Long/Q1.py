from sys import stdin

t = int(stdin.readline())

while t > 0:
    n = int(stdin.readline())
    profit = 0
    s = 0
    mod = 10**9 + 7
    l = list(map(int,stdin.readline().split()))
    l.sort(reverse=True)

    for i in range(n):
        profit = 0
        profit += (l[0] - i)
        if(profit < 0):
            profit = 0
        s += profit
        l.remove(l[0])

    print(s%mod)

    t -= 1