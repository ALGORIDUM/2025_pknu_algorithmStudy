import java.util.*;

class Solution {
    
    static boolean checkWord(String begin, String word){
        int count = 0;
        for(int i = 0; i < word.length(); i++){
            if(begin.charAt(i) != word.charAt(i)) count++; 
        }
        return count == 1;
    }
    
    public int solution(String begin, String target, String[] words) {
        int count = 0;
        Queue<String> queue = new ArrayDeque<>();
        
        boolean[] visited = new boolean[words.length];
        
        for(int i = 0; i < words.length; i++){
            if(checkWord(begin,words[i])){
                queue.add(words[i]);
                visited[i] = true;
            }
        }
        count++;
        
        while(!queue.isEmpty()){
            for(int i = 0; i < queue.size(); i++){
                String word = queue.poll();
                
                if(word.equals(target)){
                    return count;
                }
                for(int j = 0; j < words.length; j++){
                    if(checkWord(word, words[j]) && !visited[j]){
                        queue.add(words[j]);
                        visited[j] = true;
                    }
                }
            }
            count++;
        }
        
        return 0;
    }
}