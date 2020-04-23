# cook your dish here
from collections import Counter
from itertools import permutations

movies = ['A', 'B', 'C', 'D']
moviesPerms = list(permutations(movies, 4))
# print(moviesPerms)
times = ["12", "3", "6", "9"]
allPerms = []
for perm in moviesPerms:
    comb = []
    for j in range(4):
        comb.append(perm[j]+times[j])
    allPerms.append(comb)

t = int(input())
allMaxPermValues = []

for _ in range(t):
    n = int(input())

    reqs = []
    for i in range(n):
        a, b = input().split()
        reqs.append(a+b)

    requestsCounter = Counter(reqs)

    # print(requestsCounter)
    curentPermProfit = []
    for perm in allPerms:
        currentReqs = []
        for movTime in perm:
            if movTime in requestsCounter:
                currentReqs.append(requestsCounter[movTime])
            else:
                currentReqs.append(0)
        currentReqs.sort()

        currentTotal = 0
        currentTicketAmount = 25
        # currentProfits = []
        for reqCounts in currentReqs:
            if(reqCounts == 0):
                currentTotal -= 100
            else:
                currentTotal += currentTicketAmount*reqCounts
            currentTicketAmount += 25
        curentPermProfit.append(currentTotal)
    curentPermProfit.sort()
    allMaxPermValues.append(curentPermProfit[-1])
    print(allMaxPermValues[-1])
print(sum(allMaxPermValues))
