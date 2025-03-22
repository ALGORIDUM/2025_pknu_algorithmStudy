import sys

INF = 1e9
N = int(sys.stdin.readline().strip())

nums = list(map(int,sys.stdin.readline().split()))
opers = list(map(int,sys.stdin.readline().split()))

O = sum(opers)

ans = []

def dfs(cnt,now,idx):
    tmp = 0

    print(cnt,now,idx)

    if idx == N:
        return now
    
    for i in range(4):
        if opers[i]==0:
            continue

        opers[i]-=1
        if i == 0 :
            tmp = dfs(cnt+1,now+nums[idx],idx+1)
        elif i == 1:
            tmp = dfs(cnt+1,now-nums[idx],idx+1)
        elif i == 2:
            tmp = dfs(cnt+1,now*nums[idx],idx+1)
        else:
            if now <0 :
                tmp = dfs(cnt+1,-(abs(now)//nums[idx]),idx+1)
            else:
                tmp = dfs(cnt+1,now//nums[idx],idx+1)

        opers[i]+=1
        if tmp != INF+1:  
            ans.append(tmp)

    return INF+1


dfs(1,nums[0],1)

print(max(ans))
print(min(ans))

