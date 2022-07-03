class Solution {
    public String decodeMessage(String key, String message) {
        HashMap<Character , Integer> map = new HashMap<>();
       
        int c = 97;
    
        for(int i=0;i<key.length();i++){
            char m = key.charAt(i);
            if(m == ' ') continue;
            if(map.containsKey(m)){
                continue;
            }
            else{
                map.put(m , c);
               c++;
            }
          }
        StringBuilder s = new StringBuilder();
        for(int j=0 ; j< message.length(); j++){
            if(message.charAt(j)==' '){
                s.append(" ");
                continue;
            }
            
            int g = map.get(message.charAt(j)) ;
            
            s.append((char)g);
            
            
        }
        return s.toString();
    }
}