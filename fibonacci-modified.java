import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int a, b, n;
        a = in.nextInt();
        b = in.nextInt();
        n = in.nextInt();
        
        BigInteger tn0, tn1, tn2;
        tn0 = new BigInteger("0");
        tn1 = new BigInteger(Integer.toString(a));
        tn2 = new BigInteger(Integer.toString(b));
        
        for(int i = 0; i < n - 2; i++) {
            tn0 = tn1;
            tn1 = tn2;
            
            tn2 = tn1.pow(2).add(tn0);
        }
        
        System.out.println(tn2);
    }
}