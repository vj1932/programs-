import java.util.HashMap;
import java.util.Map;

public class Hashmap_test {

    private HashMap<Character, Integer> dic;

    public Hashmap_test(){
        dic = new HashMap<>();
    }

    public boolean chekAnagram(String str1, String str2) {
        if(str1.length() == str2.length()) {

            for (int i = 0; i < str1.length(); i++) {

                if(dic.containsKey(str1.charAt(i)) == true) {
                    int count = dic.get(str1.charAt(i));
                    dic.put(str1.charAt(i), count + 1);
                } else {
                    dic.put(str1.charAt(i), 1);                    
                }

                if(dic.containsKey(str2.charAt(i)) == true){
                    int count = dic.get(str2.charAt(i));
                    dic.put(str2.charAt(i),count+1);
                }
                else{
                    dic.put(str2.charAt(i), 1);
                }
            }

            for (Map.Entry<>) {
                
            }

        } else {
            return false;
        }
        System.out.println(dic);
        return true;
    }
    public static void main(String[] args) {
        Hashmap_test h1 = new Hashmap_test(); 

        h1.chekAnagram("Apple", "eppAl");
    }
}
