package Annotation.UserAnnotation;

import java.io.InputStream;
import java.lang.annotation.Annotation;
import java.lang.reflect.Method;
import java.util.Properties;

@AnnoUse(className = "Annotation.UserAnnotation.Demo1",methodName = "show1")
public class ReflectAnno {
    public static void main(String[] args) throws Exception {
        // 可以创建任意对象，可以执行任意方法
//        1. 解析注释
//        1.1 获取该类的字节码文件
        Class<ReflectAnno> reflectAnnoClass = ReflectAnno.class;
//        2. 获取上面的注解对象
//        在内存中生成了一个该注解的接口的子类实现对象
//        public class AnnoUseImple implements AnnoUse{
//            String className(){
//                return "Annotation.UserAnnotation.Demo1";
//            }
//            String methodName(){
//                return "show1";
//            }
//        }
        AnnoUse annotation = reflectAnnoClass.getAnnotation(AnnoUse.class);
        String className = annotation.className();
        String methodName = annotation.methodName();
//        System.out.println(className);
//        System.out.println(methodName);
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
