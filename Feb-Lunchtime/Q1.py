t = int(input())
while t > 0:

	n, k = map(int, input().split())
	l = list(input().split())

	heads = False

	for i in range(k):
	    head = l.pop()
	if not heads:
	    if head == 'H':
	        heads = not heads
	else:
	    if head == 'T':
	        heads = not heads

	if heads:
	    print(l.count('T'))
	else:
	    print(l.count('H'))

	t -= 1
