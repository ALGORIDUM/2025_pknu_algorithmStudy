#시간초과
import sys

N,M,H = map(int,sys.stdin.readline().split())

graph = [[False for i in range(N+1)]for i in range(H+1)]
empty = []

for i in range(M):
    a,b = map(int,sys.stdin.readline().split())
    graph[a][b] = True

for i in range(1,H+1):
    for j in range(1,N+1):
        if not graph[i][j]:
            empty.append((i,j))


def check(stair,now):
    x = now[0]
    y = now[1]

    if x==H+1:
        return y
    
    if stair[x][y]==False:
        if stair[x][y-1]==True:
            return check(stair,(x+1,y-1))
        
    else:
        return check(stair,(x+1,y+1))
    
    return check(stair,(x+1,y))

ans = []
def get_stairs(stair,depth,a):

    if depth > 3:
        return -1
    
    res = True
    for i in range(N):
        if check(stair,(1,i+1)) != i+1:
            res = False
            break
    
    if res:
        ans.append(depth)
        return depth
    
    for i in range(a,N*H-M):
        next = empty[i]
        if next[1]>=N:
            continue

        if stair[next[0]][next[1]] or stair[next[0]][next[1]+1]:
            continue

        stair[next[0]][next[1]]=True
        get_stairs(stair,depth+1,i)
        stair[next[0]][next[1]]=False
    
    return -1

get_stairs(graph,0,1)
if len(ans)==0:
    print(-1)
else:
    print(min(ans))
