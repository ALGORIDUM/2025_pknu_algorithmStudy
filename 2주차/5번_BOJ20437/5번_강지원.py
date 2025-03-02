import sys

INF = 1e9
T = int(sys.stdin.readline())

for _ in range(T):
    W = str(sys.stdin.readline().strip())
    K = int(sys.stdin.readline())

    l = len(W)

    def get_ascii_index(t):
        return ord(t)-ord('a')
    
    idx = [[]for i in range(26)]
    for i in range(l):
        idx[get_ascii_index(W[i])].append(i)
    
    shortest = INF
    longest = -1

    for p in idx:
        t = len(p)
        for i in range(t-K+1):
            if i+K-1 >=t:
                continue

            shortest = min(shortest,p[i+K-1]-p[i]+1)
            longest = max(longest,p[i+K-1]-p[i]+1)
    
    if shortest==-1 or longest==-1:
        print(-1)
    else:   
        print(shortest,longest)

    
    
            

            
            


        







    
