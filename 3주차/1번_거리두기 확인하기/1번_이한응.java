import java.util.LinkedList;
import java.util.Queue;

class Solution {

    // 동 남 서 북
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    public int[] solution(String[][] places) {
        int[] answer = new int[places.length];

        for (int i = 0; i < 5; i++) {
            if (isValidPlace(places[i]))
                answer[i] = 1;
            else
                answer[i] = 0;
        }

        return answer;
    }

    public boolean isValidPlace(String[] room) {

        char [][] map = new char[5][5];

        for (int i = 0; i < 5; i++) {
            map[i] = room[i].toCharArray();
        }

        // P에 대해 독립적으로 BFS 수행해야함!
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (map[i][j] == 'P') {
                    if (!bfs(map, i, j)) { // 하나라도 조건 만족 X -> 거리두기 위반
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public boolean bfs(char[][] map, int sx, int sy) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{sx, sy});


        while (!queue.isEmpty()) {
            int[] pos = queue.poll();
            int x = pos[0], y = pos[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || (nx == sx && ny == sy))
                    continue;

                int distance = Math.abs(nx - sx) + Math.abs(ny - sy);

                if (map[nx][ny] == 'P' && distance <= 2) { // 거리두기 위반
                    return false;
                } else if (map[nx][ny] == 'O' && distance < 2) { // 빈 테이블은 계속 탐색
                    queue.offer(new int[]{nx, ny});
                }
            }
        }
        return true;
    }
}


public class Main {
    public static void main(String[] args) {

        String[][] places = {
                {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
        };

        Solution sol = new Solution();
        int[] result = sol.solution(places);

        for (int res : result) {
            System.out.print(res + " ");
        }
    }
}

