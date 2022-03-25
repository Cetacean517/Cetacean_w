package Annotation.MyAnnotation;

import java.lang.annotation.*;

/**
 *  元注解：用于描述注解的注解
 *   @Target：描述注解能够作用的位置
 *      ElementType
 *          Type(类),Method(方法),FIELD(字段)
 *   @Retention：描述注解被保留的阶段
 *      RetentionPolicy.Runtime: 保留到class字节码文件中，并被JVM读取到
 *   @Documented:描述注解是否能被抽取到api文档
 *
 *   @Inherited:描述注解是否被子类继承
 */

@Target({ElementType.TYPE,ElementType.METHOD})
@Retention(RetentionPolicy.RUNTIME)
@Documented
@Inherited
public @interface AnnotationOrigin {
}
