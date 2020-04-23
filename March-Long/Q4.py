# cook your dish here
from sys import stdin

t = int(input())

while t > 0:
    n, q = map(int, input().split())
    points = list(map(int, input().split()))

    x_axis = []
    y_axis = []

    for i in range(1, n):
        x_axis.append((2*i+1)/2)

    while q > 0:
        x1, x2, y = map(int, input().split())

        count = 0

        for i in range(n-1):
            if(x_axis[i] < x2 and x_axis[i] > x1 and ((points[i] >= y and points[i+1] <= y) or (points[i+1] >= y and points[i] <= y)) and points[i] != points[i+1]):
                count += 1

        print(count)

        q -= 1

    t -= 1
