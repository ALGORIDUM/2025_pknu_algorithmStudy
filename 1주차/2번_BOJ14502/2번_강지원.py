import sys
from collections import deque


moves = [[-1,0],[1,0],[0,-1],[0,1]]
ans = 0
N,M = map(int,sys.stdin.readline().split())

board = []
empty = []
virus = []
for i in range(N):
    board.append(list(map(int,sys.stdin.readline().split())))
    for j in range(M):
        if board[i][j] == 0:
            empty.append((i,j))
        if board[i][j] == 2:
            virus.append((i,j))

def copy():
    tmp = [[0 for i in range(M)]for j in range(N)]
    for i in range(N):
        for j in range(M):
            tmp[i][j]=board[i][j]
    
    return tmp

def bfs(start,visited):
    dq = deque()
    dq.append(start)
    
    while dq:
        now = dq.popleft()

        for move in moves:
            x=now[0]+move[0]
            y=now[1]+move[1]

            if x<0 or x>=N or y<0 or y>=M or visited[x][y]!=0:
                continue

            dq.append((x,y))
            visited[x][y]=2

    return visited


def get_safe(tmp):
    res = 0
    for i in range(N):
        for j in range(M):
            if tmp[i][j]==0:
                res+=1
    return res

len_empty = len(empty)
for x in range(len_empty):
    
    for y in range(len_empty):
        if y == x:
            continue
        for z in range(len_empty):
            if z==x or z==y:
                continue
            
            tmp = copy()
            tmp[empty[x][0]][empty[x][1]]=1
            tmp[empty[z][0]][empty[z][1]]=1
            tmp[empty[y][0]][empty[y][1]]=1

            for v in virus:
                tmp = bfs(v,tmp)

            ans = max(ans,get_safe(tmp))
  
print(ans)