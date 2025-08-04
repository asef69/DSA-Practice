import java.util.Scanner;
public class lottery{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=0,divide;
            if(n>=100){
                sum+=n/100;
                divide=n/100;
                n=n-(divide*100);
            }
            if(n>=20){
                sum+=n/20;
                divide=n/20;
                n=n-(divide*20);
            }
            if(n>=10){
                sum+=n/10;
                divide=n/10;
                n=n-(divide*10);
            }
            if(n>=5){
                sum+=n/5;
                divide=n/5;
                n=n-(divide*5);
            }
            if(n>=1){
                sum+=n/1;
                divide=n/1;
                n=n-(divide*1);
            }
            System.out.println(sum);
        
    }
}