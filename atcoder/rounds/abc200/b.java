import java.util.*;
import java.math.*;
public class Main {
  public static void main(String... args) throws Exception {
    var scan = new Scanner(System.in);
    var n = scan.nextInt();
    var k = scan.nextInt();
    var nn = new BigInteger(Long.toString(n));
    var _200 = new BigInteger("200");
    for (int i = 0; i < k; i++) {
      nn = nn.mod(_200).equals(BigInteger.ZERO)
        ?  nn.divide(_200)
        : new BigInteger(nn.toString() + "200");
    }
    System.out.println(nn.toString());
  }
}
