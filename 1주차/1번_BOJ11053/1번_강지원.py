import sys

N = int(sys.stdin.readline())
nums = list(map(int,sys.stdin.readline().split()))

dp = []

for i in range(N):
    dp.append(1)
    for j in range(i):
        if nums[j]<nums[i]:
            dp[i]=max(dp[i],dp[j]+1)

          
print(max(dp))

