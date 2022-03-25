package Annotation.MyAnnotation;

@AnnotationOrigin
@MyAnnotation(age = 18, value = 40, f1 = Flower.Rose, anno = @MyAnno2, str = {"aaa","bbb","ccc"})
public class Fair {
    @AnnotationOrigin
    public void fair(){};
}
