package Reflect;

import Reflect.domain.Person;

import java.lang.reflect.Field;

public class getFields {
    /**
     * Class 对象功能：
     * 1. 获取成员变量们
     *      Field[] getFields(): 获取所有public修饰的成员变量
     *      Field getField(String name): 获取指定名称的 public 修饰的成员变量
     *
     *      Field[] getDeclaredFields(): 获取所有的成员变量，不考虑修饰
     *      Field getDeclaredFields(String name):
     * 2. 获取构造方法们
     *      Constructor<?>[] getConstructors()
     *      Constructor<T>[] getConstructors(类<?>... parameterTypes)
     *      Constructor<?>[] getDeclaredConstructors()
     *      Constructor<T>[] getDeclaredConstructors(类<?>... parameterTypes)
     * 3. 获取成员方法们
     *      Method[] getMethods()
     *      Method[] getMethods(String name,类<?>... parameterTypes)
     *      Method[] getDeclaredMethods()
     *      Method[] getDeclaredMethods(String name,类<?>... parameterTypes)
     * 4. 获取类名
     *      String getName()
     */
    public static void main(String[] args) throws Exception {
    //  0. 获取Person的Class对象
        Class personClass = Person.class;
//  1. 获取成员变量
        // Field[] getFields()
        Field[] fields = personClass.getFields();
        for(Field field:fields){
            System.out.println(field);
        }
        System.out.println("-----------------");
        // Field getField(String name)
        Field a = personClass.getField("a");
        System.out.println(a);
        // 获取成员变量a的值
        Person p = new Person();
        Object value = a.get(p);
        System.out.println(value);
        // 设置成员变量a的值
        a.set(p,"Apple");
        System.out.println(p);

        // Field[] getDeclaredFields(): 获取所有的成员变量，不考虑修饰
        Field[] declaredFields = personClass.getDeclaredFields();
        for (Field field:
             declaredFields) {
            System.out.println(field);
        }
        // Field getDeclaredFields(String name):
        Field d = personClass.getDeclaredField("d");
        // 暴力反射: 对于private的属性，设置可以访问和修改
        d.setAccessible(true);
        Object value2 = d.get(p);
        System.out.println(value2);
        d.set(p,"Pineapple");
        System.out.println(p);
//        2. 获取构造方法们
//        3. 获取成员方法们
//        4.

    }

}
