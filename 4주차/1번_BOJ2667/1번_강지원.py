import sys
from collections import deque

move = [[-1,0],[1,0],[0,-1],[0,1]]
N = int(sys.stdin.readline().strip())
board = []
for i in range(N):
    board.append(list(map(int,sys.stdin.readline().strip())))

def dfs(prev):
    visited[prev[0]][prev[1]] = True
    board[prev[0]][prev[1]]=0
    cnt = 1

    for m in move:
        x = prev[0]+m[0]
        y = prev[1]+m[1]

        if 0<=x<N and 0<=y<N and not visited[x][y] and board[x][y]==1:
            cnt += dfs((x,y),visited)

    return cnt


answer = []
visited = [[False for i in range(N)]for j in range(N)]

for i in range(N):
    for j in range(N):
        if board[i][j]==0 and visited[i][j]:
            continue

        answer.append(dfs((i,j),visited))

a = len(answer)
answer.sort()
print(a)
for i in range(a):
    print(answer[i])





