import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;
    static int[] nums;
    static int n;

    static void backtrack(int result, int currentNumIndex, int[] remainOperators) {
        if (remainOperators[0] == 0 && remainOperators[1] == 0 && remainOperators[2] == 0 && remainOperators[3] == 0) {
            max = Math.max(max, result);
            min = Math.min(min, result);
            return;
        }

        for(int i = 0; i < 4; i++){
            int[] nextOperators = remainOperators.clone();
            nextOperators[i]--;
            if(nextOperators[i] < 0) continue;
            if(i == 0){
                backtrack(result + nums[currentNumIndex], currentNumIndex + 1, nextOperators);
            } else if(i == 1){
                backtrack(result - nums[currentNumIndex], currentNumIndex + 1, nextOperators);
            } else if(i == 2){
                backtrack(result * nums[currentNumIndex], currentNumIndex + 1, nextOperators);
            } else {
                backtrack(result / nums[currentNumIndex], currentNumIndex + 1, nextOperators);
            }
        }

    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        nums = new int[n];
        int[] operators = new int[4]; // [+, -, *, /]

        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            operators[i] = Integer.parseInt(st.nextToken());
        }

        backtrack(nums[0], 1, operators);

        System.out.println(max);
        System.out.println(min);
    }

}
