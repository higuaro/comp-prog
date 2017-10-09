import java.math.*;

public class p25 { 
    public static void main(String[] args) { 
        BigInteger fn_2 = new BigInteger("1");
        BigInteger fn_1 = new BigInteger("1");

        for (int i = 3; ; ++i) { 
            BigInteger fn = fn_1.add(fn_2);
            String number = fn.toString();

            if (number.length() >= 1000) {
                System.out.printf("The %dth term has %d digits", i, number.length());
                break;
            }

            fn_2 = fn_1;
            fn_1 = fn;
        }
    }   
}
