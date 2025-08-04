import java.util.Scanner;
public class simpleinterest{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        float principle=sc.nextFloat();
        float interest=sc.nextFloat();
        float time=sc.nextFloat();
        float si=(principle*time*interest)/100;
        System.out.println(si);

    }
}