public class UndergraduateException extends Exception{
    String message = "该大学生有成绩不在0-100范围内，产生错误。";

    public String warnMess(){
        return message;
    }
}
