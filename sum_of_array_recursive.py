def sum_array(arr,n):
    if(n <= 0):
        return 0

    return (sum_array(arr,n-1) + arr[n-1])

arr = list(map(int,input().split()))

sum = sum_array(arr,len(arr))

print(sum)