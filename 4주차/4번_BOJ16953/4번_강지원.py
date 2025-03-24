import sys

INF = 1e9
A,B = map(int,sys.stdin.readline().split())

def dfs(prev,cnt):
    res = 0

    if prev==B:
        return cnt
    if prev > B:
        return INF
    
    tmp_1 = dfs(prev*2,cnt+1)
    tmp_2 = dfs(prev*10+1,cnt+1)

    return min(tmp_1,tmp_2)

ans = dfs(A,0)
if ans == INF:
    print(-1)
else:
    print(ans+1)
