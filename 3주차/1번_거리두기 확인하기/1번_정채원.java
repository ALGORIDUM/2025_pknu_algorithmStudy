import java.util.*;

class Solution {
    static int[][] dirs = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    static char[][] buildMaps(String[] seats) {
        char[][] maps = new char[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                maps[i][j] = seats[i].charAt(j);
            }
        }
        return maps;
    }
    
    static boolean bfs(char[][] maps, int startRow, int startCol) {
        Queue<int[]> queue = new ArrayDeque<>();
        int[][] visited = new int[5][5];

        queue.add(new int[]{startRow, startCol, 0});
        visited[startRow][startCol] = 1; 

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int currentRow = current[0];
            int currentCol = current[1];
            int currentDist = current[2];

            // 거리가 2 초과이면 상관 없음
            if (currentDist > 2) continue;

            for (int[] dir : dirs) {
                int nextRow = currentRow + dir[0];
                int nextCol = currentCol + dir[1];

                if (nextRow >= 0 && nextRow < 5 && nextCol >= 0 && nextCol < 5) {
                    
                    // 현재 P인데 사방탐색시 바로 P 나오면 거리 위반
                    if (maps[currentRow][currentCol] == 'P' && maps[nextRow][nextCol] == 'P') {
                        return false;
                    }

                    // 현재 위치가 O이고 사방 탐색 시 방문하지 않은 P가 나왔는데 현재 거리가 2 이하이면 거리 위반
                    if (maps[currentRow][currentCol] == 'O' && maps[nextRow][nextCol] == 'P'
                            && visited[nextRow][nextCol] == 0 && currentDist < 2) {
                        return false;
                    }

                    if (maps[nextRow][nextCol] != 'X' && visited[nextRow][nextCol] == 0) {
                        visited[nextRow][nextCol] = 1; 
                        queue.add(new int[]{nextRow, nextCol, currentDist + 1});
                    }
                }
            }
        }
        return true;
    }
    
    public int[] solution(String[][] places) {
        ArrayList<Integer> answer = new ArrayList<>();

        for (int t = 0; t < 5; t++) {
            String[] seats = places[t];
            char[][] maps = buildMaps(seats);
            boolean isValid = true;

            for (int i = 0; i < 5 && isValid; i++) {
                for (int j = 0; j < 5 && isValid; j++) {
                    if (maps[i][j] == 'P') {
                        isValid = bfs(maps, i, j);
                        if (!isValid) break; 
                    }
                }
            }
            if(isValid){
                answer.add(1);
            } else {
                answer.add(0);
            }
        }
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
