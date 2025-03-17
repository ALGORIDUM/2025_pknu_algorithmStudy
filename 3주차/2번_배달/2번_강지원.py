import heapq

def solution(N, road, K):
    answer = 0
    INF = 1e9
    
    graph = [[]for i in range(N)]
    for r in road:
        graph[r[0]-1].append((r[1]-1,r[2]))
        graph[r[1]-1].append((r[0]-1,r[2]))
        
    dist = [INF for i in range(N)]
    
    def dijkstra(start):
        dist[start] = 0
        
        q=[]
        heapq.heappush(q,(0,start))
        
        while q:
            dis,node = heapq.heappop(q)
            
            for nxt in graph[node]:
                tmp = nxt[1]+dis
                if tmp<=K and tmp<dist[nxt[0]]:
                    dist[nxt[0]]=tmp
                    heapq.heappush(q,(dis+nxt[1],nxt[0]))
                    
        
    dijkstra(0)
    for i in range(0,N):
        if dist[i]!=INF:
            answer+=1
    
    return answer