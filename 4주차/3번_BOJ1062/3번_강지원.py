import sys

N,K = map(int,sys.stdin.readline().split())

words=[]

# base = 0
# base_char = ['a','c','n','t','i']
# for c in base_char:
#         base = base | (1<<(ord(c)-ord('a')))

for i in range(N):
    tmp = sys.stdin.readline().strip()
    bit = 0
    for c in tmp:
        # if c in ['a','c','n','t','i']:
        #     continue
        bit = bit | (1<<(ord(c)-ord('a')))
    if bin(bit).count('1')<=K:
        words.append(bit)

if K<5:
    print(0)


else:
    N = len(words)

    def dfs(now,cnt,n):
        res = 0
        if n>=N:
            if bin(now).count('1')<=K:
                return cnt
            else:
                return 0
        
        tmp = words[n] | now
        if bin(tmp).count('1')<=K:
            res = dfs(tmp,cnt+1,n+1)
        
        return max(res,dfs(now,cnt,n+1))

    print(dfs(0,0,0))

    
