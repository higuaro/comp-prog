import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.HashMap;

class p56 {
    public static boolean isPalindrome(String n) {
        int size = n.length();
        int half = size / 2;
        for (int i = 0; i < half; i++) { 
            if (n.charAt(i) != n.charAt(size - 1 - i)) {
                return false;
            }
        }
        return true;
    }
    
    public static String reverse(String w) { 
        return new StringBuilder(w).reverse().toString();
    }
    
    public static BigInteger reverseAndAdd(BigInteger n) {
        String r = reverse(n.toString());
        BigInteger n2 = new BigInteger(r, 10);
        return n.add(n2);
    }
    
    public static boolean isLychrel(BigInteger n, Map<String, Boolean> checked) {
        List<String> marked = new ArrayList<String>();
        boolean found = true;
        for (int i = 0; i < 50; i++) {
            BigInteger res = reverseAndAdd(n);
            
            if (checked.get(res) != null || isPalindrome(res.toString())) {
                found = false;
                marked.add(n.toString());
                break;
            } else {
                marked.add(n.toString());
                n = res;
            }
        }
        for (String number : marked) {
            checked.put(number, found);
        }
        
        return found;
    }    
    
    public static void main(String... args) {
        Map<String, Boolean> checked = new HashMap<String, Boolean>();

        int total = 0;
        for (int n = 10; n <= 10000; n++) {
            if (isLychrel(new BigInteger(Integer.toString(n)), checked)) {
                total++;
            }
        }
        System.out.println(total);
    }
}

