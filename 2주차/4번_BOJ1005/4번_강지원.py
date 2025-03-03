import sys

T = int(sys.stdin.readline())

for t in range(T):
    N,K = map(int,sys.stdin.readline().split())
    rules = [[] for i in range(N)]
    status = [0 for i in range(N)]
    times = list(map(int,sys.stdin.readline().split()))


    for i in range(K):
        x,y = map(int,sys.stdin.readline().split())
        rules[x-1].append(y-1)
        status[y-1]+=1
    
    W= int(sys.stdin.readline())
    
    now = 0    

    dp = [0 for i in range(N)]
    while 1:
        if  sum(status)==-N:
            break

        if status[now]==0:
            status[now]=-1
            dp[now]+=times[now]

            for rule in rules[now]:
                status[rule]-=1
                print(dp)
                if dp[rule]!=0:
                    dp[rule]=max(dp[now],dp[rule])
                else:
                    dp[rule]+=dp[now]
        
        now = (now+1)%N

    
    print(dp[W-1])
    