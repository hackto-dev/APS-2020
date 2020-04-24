def selection_sort(arr):
    a = []
    
    for i in range(len(arr) - 1):
        a.append(arr.pop(arr.index(min(arr))))
    a.append(arr[0])

    return a

arr = list(map(int, input().split()))

print(selection_sort(arr))
