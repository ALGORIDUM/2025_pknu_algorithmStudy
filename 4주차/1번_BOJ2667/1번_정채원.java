import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> answer = new ArrayList<>();
        int n = Integer.parseInt(br.readLine());
        int total = 0;
        int[][] map = new int[n][n];
        boolean[][] visited = new boolean[n][n];

        int[][] dirs = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(int i = 0; i < n; i++){
            String line = br.readLine();
            for(int j = 0; j < n; j++){
                map[i][j] = line.charAt(j) - '0';
            }
        }



        for(int i = 0; i < n; i++){
            Queue<int[]> queue = new ArrayDeque<>();
            for(int j = 0; j < n; j++){
                if(map[i][j] == 1 && !visited[i][j]){
                    int count = 1;
                    queue.add(new int[]{i, j});
                    visited[i][j] = true;

                    while(!queue.isEmpty()){
                        int[] cur = queue.poll();

                        for(int[] dir : dirs){
                            int newRow = cur[0] + dir[0];
                            int newCol = cur[1] + dir[1];

                            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n
                                    && map[newRow][newCol] == 1 && !visited[newRow][newCol]){
                                queue.add(new int[]{newRow, newCol});
                                count++;
                                visited[newRow][newCol] = true;
                            }
                        }
                    }
                    answer.add(count);
                    total++;
                }

            }
        }
        System.out.println(total);
        answer.stream().sorted().mapToInt(i -> i).forEach(System.out::println);
    }
}
