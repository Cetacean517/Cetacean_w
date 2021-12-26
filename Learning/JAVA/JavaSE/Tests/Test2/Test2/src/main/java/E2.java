/*输出 1-100 之内前 5 个能被 3 整除的数；*/
public class E2 {
    public static void e2() {
        int flag = 0;
        int num = 1;
        while(flag < 5){
            if(num % 3 == 0) {
                System.out.println("No." + (flag + 1) + " "+ num);
                flag++;
            }
            num++;
        }
    }
}
