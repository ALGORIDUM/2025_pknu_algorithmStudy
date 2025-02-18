import sys
import heapq

INF = 1e9

V,E=map(int,sys.stdin.readline().split())

K = int(sys.stdin.readline())-1
graph = [[]for i in range(V)]

for i in range(E):
    u,v,w = map(int,sys.stdin.readline().split())
    graph[u-1].append((v-1,w))


dis=[INF for i in range(V)]

def dijkstra(start):
    q=[]
    heapq.heappush(q,(0,start))
    dis[start]=0

    while q:
        d,n = heapq.heappop(q)

        if dis[n]<d:
            continue

        for next in graph[n]:
            cost = dis[n]+next[1]
            if cost<dis[next[0]]:
                dis[next[0]]=cost
                heapq.heappush(q,(cost,next[0]))

dijkstra(K)
for i in range(V):
    if dis[i]==INF:
        print("INF")
    else:
        print(dis[i])