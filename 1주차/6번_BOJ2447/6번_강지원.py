import sys

N = int(sys.stdin.readline().strip())

def div_conq(n):
    res = []
    if n==1:
        return "*"

    prev = div_conq(n//3)

    for i in range(n//3):
        res.append(prev[i]*3)
    
    for i in range(n//3):
        res.append(prev[i]+(" "*(n//3))+prev[i])
    
    for i in range(n//3):
        res.append(prev[i]*3)
    
    return res


ans = div_conq(N)
for i in range(N):
    print(ans[i])

print('\n'.join(div_conq(N)))


    
