/*
实现用户从键盘上输入 3 个 1-100 的整数；每输入一次，检查当前输入是否为有效输入，直到有效次数为 3 结束程序，统计三次
有效输入和输出；要求能够给出无效ᨀ示和正确输入次数提示。 */
import java.util.InputMismatchException;
import java.util.Scanner;

public class E1 {
    public static void e1() {
        int flag = 3, count = 0;// count 记录合格次数
        int[] arr = new int[3];
        while(flag > 0){
            try{
                Scanner scanner = new Scanner(System.in); // 创建Scanner对象
                System.out.println("Input a number (range from 1-100): "); // 打印提示
                int age = scanner.nextInt(); // 读取一行输入并获取整数
                if(age < 1 || age > 100){
                    System.out.println("ERROR1：输入数据范围异常，请重新输入。");
                }
                else{
                    arr[count] = age;
                    count ++;
                    flag--;
                    System.out.println("已完成"+count+"次输入");
                }

            }catch (InputMismatchException e){
                System.out.println("ERROR2：输入的数据类型异常，请重新输入。");
            }
        }
        System.out.println("已完成所有输入, 输入的3个数字依次为：");
        for(int i = 0; i< 3;i++)
        {
            System.out.println(arr[i]);
        }

    }

}
