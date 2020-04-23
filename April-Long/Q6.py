OR = {'|': [
    [(0, 0)],
    [(0, 1), (1, 0), (1, 2), (2, 1), (1, 3), (3, 1), (3, 2), (2, 3), (1, 1)],
    [(0, 2), (2, 0), (2, 2)],
    [(0, 3), (3, 0), (3, 3)]
    ]
}

AND = {'&': [[(0, 0), (0, 1), (1, 0), (0, 2), (2, 0), (3, 0), (0, 3), (2, 3), (3, 2)],
          [(1, 1)],
          [(2, 1), (1, 2), (2, 2)],
          [(3, 1), (1, 3), (3, 3)]
          ]
}

XOR = {'^': [[(0, 0), (1, 1), (2, 2), (3, 3)],
          [(1, 0), (3, 2), (2, 3), (0, 1)],
          [(0, 2), (2, 0), (1, 3), (3, 1)],
          [(0, 3), (3, 0), (1, 2), (2, 1)]
          ]
}


def seniority(op):

    if op == '|':
        return 1
    if op == '^':
        return 2
    if op == '&':
        return 3
    return 0


def operate(a, b, op):
    global AND,OR,XOR
    l = []
    if op == "|":
        for i in OR[op]:
            s = 0
            for j in i:
                prod = a[j[0]] * b[j[1]]
                s += prod
            l.append(s)

    elif op == "&":
        for i in AND[op]:
            s = 0
            for j in i:
                prod = a[j[0]] * b[j[1]]
                s += prod
            l.append(s)

    elif op == "^":
        for i in XOR[op]:
            s = 0
            for j in i:
                prod = a[j[0]] * b[j[1]]
                s += prod
            l.append(s)

    return l


def evaluateExpression(tokens):

    value = []
    ops = []
    i = 0

    while i < len(tokens):

        if tokens[i] == '(':
            ops.append(tokens[i])

        elif tokens[i] == '#':
            val = [1, 1, 1, 1]
            value.append(val)

        elif tokens[i] == ')':

            while len(ops) != 0 and ops[-1] != '(':

                val2 = value.pop()
                val1 = value.pop()
                op = ops.pop()

                value.append(operate(val1, val2, op))

            ops.pop()

        else:
            while (len(ops) != 0 and
                   seniority(ops[-1]) >= seniority(tokens[i])):

                val2 = value.pop()
                val1 = value.pop()
                op = ops.pop()

                value.append(operate(val1, val2, op))

            ops.append(tokens[i])

        i += 1

    while len(ops) != 0:

        val2 = value.pop()
        val1 = value.pop()
        op = ops.pop()

        value.append(operate(val1, val2, op))

    return value[-1]


def powerCalculator(number, n, m):
    number %= m
    prod = 1
    while(n != 0):
        if((n & 1) == 1):
            prod = (prod*number) % m
        number = (number*number) % m
        n >>= 1
    return prod


t = int(input())
while t > 0:
    exp = input()
    output = evaluateExpression(exp)
    m = exp.count('#')
    m = 4**m
    moderator = 998244353
    # print(*output)
    for i in range(len(output)):
        output[i] = output[i] * \
            powerCalculator(m, moderator-2, moderator) % moderator
    print(*output)

    t -= 1
