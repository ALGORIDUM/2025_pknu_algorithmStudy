def solution(n, costs):
    answer = 0
    parents = [i for i in range(n)]
    
    def find_parent(a):
        if parents[a]!=a:
            return find_parent(parents[a])
        return parents[a]
    
    def union(a,b):
        a = find_parent(a)
        b = find_parent(b)
        
        if a<=b:
            parents[b]=a
        else:
            parents[a]=b
    
    for cost in costs:
        a = cost[0]
        b = cost[1]
        c = cost[2]
        
        if find_parent(a)!=find_parent(b):
            union(a,b)
            answer+=c
        
        
    return answer