import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int max = 0;
    static String[] words;
    static int n;
    static int m;
    static HashSet<Character> unLearnedSet = new HashSet<>();
    static HashSet<Character> learned = new HashSet<>();
    static List<Character> unLearnedList;



    static void dfs(int startIndex, int k){
        if(k == m - 5){
            int count = 0;
            for(String word : words){
                boolean flag = true;
                for(char c : word.toCharArray()){
                    if(!learned.contains(c)){
                        flag = false;
                        break;
                    }
                }
                if(flag) count++;
            }
            max = Math.max(max, count);
            return;
        }

        for(int i = startIndex; i < unLearnedList.size(); i++){
            char c = unLearnedList.get(i);
            learned.add(c);
            dfs(i + 1, k + 1);
            learned.remove(c);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        if(m < 5){
            System.out.println(0);
            return;
        }
        if(m == 26){
            System.out.println(n);
            return;
        }

        learned.add('a');
        learned.add('c');
        learned.add('n');
        learned.add('i');
        learned.add('t');

        words = new String[n];
        for(int i = 0; i < n; i++) {
            String word = br.readLine();
            words[i] = word.substring(4,word.length()-4);
        }



        for(String word : words) {
            for(char c : word.toCharArray()) {
                if(!learned.contains(c)) {
                    unLearnedSet.add(c);
                }
            }
        }
        unLearnedList = new ArrayList<>(unLearnedSet);

        if (unLearnedList.size() <= m - 5) {
            System.out.println(n);
            return;
        }


        dfs(0, 0);

        System.out.println(max);

    }
}
