import sys

n,m = map(int,sys.stdin.readline().split())

ans = 0

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

parent = [i for i in range(n)]

for i in range(m):
    a,b = map(int,sys.stdin.readline().split())

    if find_parent(parent,a) == find_parent(parent,b):
        ans = i+1
        break
    else:
        union_parent(parent,a,b)

print(ans)
    




    
