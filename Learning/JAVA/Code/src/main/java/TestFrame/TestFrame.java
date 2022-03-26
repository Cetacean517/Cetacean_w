package TestFrame;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Method;

/**
 * 简单的测试框架
 *
 * 主方法执行后，会自动执行被检查的方法（加了Check主机的方法），
 * 判断方法是否有异常，记录到bug.txt
 */
public class TestFrame {
    public static void main(String[] args) throws Exception {
//        1. 创建计数器对象
        Calculator calculator = new Calculator();
//        2. 获取字节码文件对象
        Class cls = calculator.getClass();
//        3. 获取所有方法
        Method[] methods = cls.getMethods();

        int num = 0; // 出现异常的次数
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter("bug.txt"));

        for (Method method:methods){
//            4. 判断方法上是否有Check注解
            if(method.isAnnotationPresent(Check.class)){
//                5. 有，则执行
                try{
                    method.invoke(calculator);
                } catch (Exception e){
//                    6. 捕获异常，记录到文件中
                    num++;
                    bufferedWriter.write(method.getName()+"方法出现异常");
                    bufferedWriter.newLine();
                    bufferedWriter.write("异常的名称"+ e.getCause().getClass().getSimpleName());
                    bufferedWriter.newLine();
                    bufferedWriter.write("异常的原因"+ e.getCause().getMessage());
                    bufferedWriter.newLine();
                    bufferedWriter.write("----------------------------");
                    bufferedWriter.newLine();
                }
            }
        }

        bufferedWriter.write("本次测试一共出现"+num+"次异常");
        bufferedWriter.flush();
        bufferedWriter.close();

    }
}
