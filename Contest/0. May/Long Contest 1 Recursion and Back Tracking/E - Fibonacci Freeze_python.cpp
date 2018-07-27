
arr = []

def fiv(n):
    if(n==0):
        return 0
    elif(n==1):
        return 1
    elif(arr[n] != 0):
        return arr[n];
    else:
        arr[n] = fiv(n-1) + fiv(n-2)
        return arr[n]

for i in range(0,5004):
    arr.append(0)

fiv(5002)
while(1):

    try:
        n = int(input())
        print("The Fibonacci number for {} is {}".format(n,arr[n]))
    except EOFError:
        #print("ERROR")
        break

