/**
 * @time 2022/7/20 20:51
 * @version 1.00
 * @author Cetacean Wang
 */
package Test;
import java.util.Scanner;
/*
* 1. 导包: import 包路径.类名称;S
* 2. 创建: 类名称 对象名 = new 类名称();
* 3. 使用: 对象名.成员方法名()s
* */
public class ScannerDemo {
    public static void main(String[] args) {
        // System.in 从键盘输入
        Scanner scanner = new Scanner(System.in);
        if(scanner.hasNextInt()){
            int num = scanner.nextInt();
            System.out.println("number: " + num);
        } else if (scanner.hasNextFloat()){
            float f = scanner.nextFloat();
            System.out.println("float: " + f);
        } else if (scanner.hasNext()){
            String str = scanner.next();
            System.out.println("string: " + str);
        }
    }
}
