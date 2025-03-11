from collections import deque

def solution(places):
    answer = []
    moves = [[1,0],[-1,0],[0,-1],[0,1]]
    
    for place in places:
        board = []
        peoples = []
        for i in range(5):
            board.append(list(place[i]))
            for j in range(5):
                if board[i][j]=="P":
                    peoples.append((i,j))
        
        def bfs(start,visited):
            if visited[start[0]][start[1]] :
                return True
                        
            dq = deque()
            dq.append((start,0))
            
            while dq:
                node = dq.popleft()
                visited[node[0][0]][node[0][1]] = True
                
                for move in moves:
                    x = node[0][0]+move[0]
                    y = node[0][1]+move[1]

                    if x<0 or x>=5 or y<0 or y>=5 or board[x][y]=="X" or visited[x][y]:
                        continue
                    
                    if board[x][y]=="P":
                        if node[1]+1<=2:
                            return False
                        else:
                            dq.append(((x,y),0))
                    else:
                        dq.append(((x,y),node[1]+1))
            return True
        
        visited = [[False for i in range(5)]for j in range(5)]  
        flag = True
        
        for people in peoples:
            if not bfs(people,visited) :
                flag = False
                break
        if not flag:
            answer.append(0)
        else:
            answer.append(1)
        
    return answer