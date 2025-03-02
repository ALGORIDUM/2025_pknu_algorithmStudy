import sys

N,C = map(int,sys.stdin.readline().split())
INF = 1e9
house = []
for i in range(N):
    house.append(int(sys.stdin.readline().strip()))

house.sort()

install = []

def check(dis):
    count = 1
    prev = 0
    for i in range(1,N):
        if house[i]-house[prev]>=dis:
            count+=1
            prev=i
    
    if count>=C:
        return True
    else:
        return False
    

def binary_search(start,end):
    if start>=end:
        return 0
    
    mid = (start+end)//2

    if check(mid):
        return max(mid,binary_search(mid+1,end))
    else:
        return binary_search(start,mid)


print(binary_search(1,house[-1]-house[0]+1))

    



    



    



