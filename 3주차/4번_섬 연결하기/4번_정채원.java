import java.util.Arrays;

class Solution {
    // MST
    static int[] parent;
    
    static int find(int u){
        if(parent[u] < 0) return u;
        parent[u] = find(parent[u]);
        return parent[u];
    }
    
    static boolean union(int u, int v){
        int rootU = find(u);
        int rootV = find(v);
        
        if(rootU == rootV) return false;
        
        if(parent[rootU] > parent[rootV]){ // root
            int tmp = rootU;
            rootU = rootV;
            rootV = tmp;
        }
        
        if(parent[rootU] == parent[rootV]){
            parent[rootU]--;
        }
        parent[rootV] = rootU;
        return true;
    }
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        int count = 0;
        
        parent = new int[n];
        
        for(int i = 0; i < n; i++) {
            parent[i] = -1;
        }
        
        Arrays.sort(costs, (o1, o2) -> Integer.compare(o1[2], o2[2]));
        
        for(int[] cost : costs) {
            int u = cost[0];
            int v = cost[1];
            if(count == n-1) return answer;
            
            if(find(u) == find(v)) continue;
            if(find(u) != find(v)) {
                union(u, v);
                answer += cost[2];
            }
        }    
        return answer;
    }
}