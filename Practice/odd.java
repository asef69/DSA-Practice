import java.util.Scanner;
public class odd{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long  n=sc.nextLong();
        if(n%2==0) System.out.println("EVEN");
        else System.out.println("ODD");
    }
}