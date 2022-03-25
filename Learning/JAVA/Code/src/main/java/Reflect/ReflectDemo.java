package Reflect;

import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.util.Properties;

public class ReflectDemo {
    public static void main(String[] args) throws Exception {
        // 可以创建任意对象，可以执行任意方法
        /**
         * 步骤：
         * 1. 将需要创建的对象的全类名和需要执行的方法定义在配置文件中
         * 2. 在程序中加载需要读取的配置文件
         * 3. 使用反射，加载类文件进内存
         * 4. 创建对象
         * 5. 执行方法
         */
        // 1. 加载配置文件
        // 1.1 创建Properties对象
        Properties properties = new Properties();
        // 1.2 加载配置文件，转换为一个集合
        // 1.2.1 获取class目录下的配置文件
        ClassLoader classLoader = ReflectDemo.class.getClassLoader();
        InputStream is = classLoader.getResourceAsStream("pro.properties");
        properties.load(is);

        // 2. 获取配置文件中定义的数据
        String className = properties.getProperty("className");
        String methodName = properties.getProperty("methodName");

        // 3. 加载该类进内存
        Class cls = Class.forName(className);
        // 4. 创建对象
        Object o = cls.newInstance();
        // 5. 运行方法
        Method method = cls.getMethod(methodName);
        // 6. 执行方法
        method.invoke(o);


    }
}
