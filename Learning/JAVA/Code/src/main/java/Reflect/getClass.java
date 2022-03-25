package Reflect;

import Reflect.domain.Person;

public class getClass {
    /**
     * 获取Class对象的方法：
     * 1. Class.forName("全类名"): 将字节码文件加载进内存，返回Class对象
     * 2. 类名.class: 通过类名的属性class获取
     * 3. 对象.getClass():getClass()方法在Object类中定义。
     *
     * 结论：
     *  同一个字节码文件(*.class)在一次程序运行过程中，只会被加载一次，不论通过哪一种方式获取的Class的对象都是同一个
     */
    public static void main(String[] args) throws Exception {
//      1. Class.forName("全类名")
        Class cls1 = Class.forName("Reflect.domain.Person");
        System.out.println(cls1);
//      2. 类名.class: 通过类名的属性class获取
        Class cls2 = Person.class;
        System.out.println(cls2);
//      3. 对象.getClass():getClass()方法在Object类中定义。
        Person p = new Person();
        Class cls3 = p.getClass();
        System.out.println(cls3);

        System.out.println(cls1 == cls2);
        System.out.println(cls1 == cls3);
    }
}
