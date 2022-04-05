def insertion_sort(arr):
    for i in range(1,len(arr)):
        k = i-1

        if(arr[i] < arr[k]):
            temp = arr[i]

            while(temp < arr[k]):
                arr[k+1] = arr[k]
                k -= 1

                if k == -1:
                    break

            arr[k+1] = temp

    return arr

arr = list(map(int,input().split()))

print(insertion_sort(arr))