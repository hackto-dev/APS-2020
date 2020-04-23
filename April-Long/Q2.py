from sys import stdin

t = int(stdin.readline())

while t > 0:
    n = int(stdin.readline())
    l = list(map(int,stdin.readline().split()))

    min_distance = 5

    flag = 0

    for i in range(n):

        if(l[i] == 1):

            if(min_distance < 5):

                print("NO")
                flag = 1
                break

            min_distance = 0
        
        else:
            min_distance += 1

    if(flag == 0):
        print("YES")

    t -= 1




