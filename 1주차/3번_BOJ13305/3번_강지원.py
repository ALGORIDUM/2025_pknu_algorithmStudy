import sys

ans = 0
N = int(sys.stdin.readline().strip())

dis=list(map(int,sys.stdin.readline().split()))
oil=list(map(int,sys.stdin.readline().split()))

min_oil = oil[0]
for i in range(N-1):
    min_oil=min(min_oil,oil[i])
    ans+=min_oil*dis[i]

print(ans)   

