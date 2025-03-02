import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.lang.StringBuilder;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
     
        int T = sc.nextInt();
        sc.nextLine();

        for(int i = 0; i < T; i++) {
            HashMap<Character, ArrayList<Integer>> map = new HashMap<>();
            StringBuilder sb = new StringBuilder();
            
            String str = sc.nextLine();
            int K = sc.nextInt();
            sc.nextLine();

            int min = Integer.MAX_VALUE;
            int max = Integer.MIN_VALUE;

            for(int j = 0; j < str.length(); j++) {
                char ch = str.charAt(j);
                if(!map.containsKey(ch)) {
                    map.put(ch, new ArrayList<>());
                }
                map.get(ch).add(j);
            }

            for(ArrayList<Integer> list : map.values()) {
                if(list.size() >= K) {
                    //sliding window
                    for (int idx = 0; idx <= list.size() - K; idx++) {
                        int len = list.get(idx + K - 1) - list.get(idx) + 1;
                        min = Math.min(min, len);
                        max = Math.max(max, len);
                    }
                }
            }

            if(max == Integer.MIN_VALUE || min == Integer.MAX_VALUE) {
                sb.append("-1\n");
            } else {
                sb.append(min).append(" ").append(max).append("\n");
            }
            System.out.print(sb.toString());
        }
    }
}