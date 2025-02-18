import sys
from collections import deque

N,M = map(int,sys.stdin.readline().split())
board=[]
stars=[]
moves = [[-1,0],[1,0],[0,-1],[0,1]]
for i in range(N):
    board.append(list(map(str,sys.stdin.readline().strip())))
    for j in range(M):
        if board[i][j]=="*":
            stars.append((i,j))

crosses=[]
checked=[]

for star in stars:
    info=[[]for i in range(4)]
    min_depth=101

    for i in range(4):
        x=star[0]
        y=star[1]

        depth = 0
        while board[x][y]=="*":
            x+=moves[i][0]
            y+=moves[i][1]

            if x<0 or x>=N or y<0 or y>=M or board[x][y]==".":
                break

            info[i].append((x,y))
            depth+=1
        
        min_depth=min(min_depth,depth)
    
    if min_depth>0 and min_depth<101:
        checked.append(star)
        for i in range(4):
            checked+=info[i][:min_depth]
        for i in range(min_depth):
            crosses.append([star[0]+1,star[1]+1,i+1])


res=len(crosses)
if len(set(checked))!=len(stars):
    res=-1

if res>0:
    print(res)
    for cross in crosses:
        for info in cross:
            print(info,end=" ")
        print()
else:
    print(-1)


    
            
        



            






