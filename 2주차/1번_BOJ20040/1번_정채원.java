import java.util.Scanner;

public class Main {

    static int[] parent;

    static int find(int x) {
        if(x == parent[x]) {
            return x;
        }else {
            parent[x] = find(parent[x]); 
            return parent[x];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // 점의 갯수 3 <= n <= 500,000
        int m = sc.nextInt(); // 진행된 차례

        parent = new int[n];

        // 일단 모든 점들을 각자의 집합으로 만들어준다
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // 사이클이 완성되면 i를 반환 for문이 완료되면 0을 반환
        for(int i = 1; i <= m; i++) {
            // 두 점을 받아서 find
            int a = sc.nextInt();
            int b = sc.nextInt();

            if(find(a) != find(b)) {
                parent[find(a)] = find(b); // 유니온
            } else {
                System.out.println(i);
                return;
            }

        }
        System.out.println(0);
        return;
    }
}