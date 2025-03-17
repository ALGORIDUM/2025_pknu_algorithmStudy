from collections import deque

def solution(begin, target, words):
    answer = 0
    INF = 1e9
    w = len(words[0])
    
    if target not in words:
        return 0
    
    def check (a,b):
        cnt = 0
        for i in range(w):
            if a[i]!=b[i]:
                cnt+=1
            if cnt>=2:
                return False
        return True
    
    def bfs(start,visited):
        dq = deque()
        dq.append((start,0))
        res = INF
        
        while dq:
            node = dq.popleft()
            visited[node[0]]=True
            
            if node[0]==target:
                res = min(node[1],res)
            
            for word in words:
                if word == node[0] or visited[word] or node[1]>=res or not check(word,node[0]):
                    continue
                    
                dq.append((word,node[1]+1))
                
        return res
        
    visited = {}
    for word in words:
        visited[word]=False
        
    answer = bfs(begin,visited)

    if answer==INF:
            answer = 0
        
    return answer