import sys
from collections import deque

D = 2
R = 3
C = 4

N = int(sys.stdin.readline().strip())
board = []
for i in range(N):
    board.append(list(map(int,sys.stdin.readline().split())))

board[0][0] = R
if board[N-1][N-1]==1:
    print(0)
    sys.exit()

def available(way,node):
    if way == R:
        if node[1]+1>=N:
            return False
        if board[node[0]][node[1]+1]==0:
            return True
        
    elif way == C:
        if node[0]+1>=N or node[1]+1>=N:
            return False
        
        if board[node[0]][node[1]+1]==0 and board[node[0]+1][node[1]]==0 and board[node[0]+1][node[1]+1]==0:
            return True
    
    elif way == D:
        if node[0]+1>=N:
            return False
        if board[node[0]+1][node[1]]==0:
            return True
    
    return False

def dfs(prev,visited):
    res = 0

    if prev[0]==N-2 and prev[1]==N-2 and board[prev[0]][prev[1]]==C:
        return 1
    elif prev[0]==N-1 and prev[1]==N-2 and board[prev[0]][prev[1]]==R:
        return 1
    elif prev[0]==N-2 and prev[1]==N-1 and board[prev[0]][prev[1]]==D:
        return 1

    x=prev[0]
    y=prev[1]

    if board[x][y]==R:
        y+=1
        if available(R,(x,y)):
            board[x][y]=R
            res+=dfs((x,y),visited)
            board[x][y]=0

        if available(C,(x,y)):
            board[x][y]=C
            res+=dfs((x,y),visited)
            board[x][y]=0
        
        return res

            
    elif board[x][y]==D:
        x+=1
        if available(D,(x,y)):
            board[x][y]=D
            res+=dfs((x,y),visited)
            board[x][y]=0

        if available(C,(x,y)):
            board[x][y]=C
            res+=dfs((x,y),visited)
            board[x][y]=0
        x-=1
        return res

    
    elif board[x][y]==C:
        x+=1
        y+=1
        if available(D,(x,y)):
            board[x][y]=D
            res+=dfs((x,y),visited)
            board[x][y]=0

        if available(C,(x,y)):
            board[x][y]=C
            res+=dfs((x,y),visited)
            board[x][y]=0

        if available(R,(x,y)):
            board[x][y]=R
            res+=dfs((x,y),visited)
            board[x][y]=0
        
        x-=1
        y-=1
        return res

    
    
    return res

print(dfs((0,0),0))

            