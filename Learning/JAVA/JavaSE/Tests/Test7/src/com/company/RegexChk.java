package com.company;
import java.util.regex.*;
//1.创建一个类 RegexChk，作为提供各种方法，实现对整数、手机号码、电子邮箱、邮政编码、身份证号码的有效性验证。

//3.
//Pattern pattern = Pattern.compile(reg);
//Matcher matcher = pattern.matcher(string);
//result = matcher.matches();
//其中，reg 为正则表达式，string 为待验证字符串对象。

public class RegexChk {
    String zheng;
    String phone;
    String email;
    String post;
    String indentification;

    public boolean IfZheng(){//验证整数时，能够同时校验正整数、负整数和 0
        Pattern patternzheng = Pattern.compile("^[0-9]*[1-9][0-9]*$");
        Pattern patternfu = Pattern.compile("^-[0-9]*[1-9][0-9]*$");
        Pattern patternzero = Pattern.compile("0*$");
        Matcher matcherzheng = patternzheng.matcher(zheng);
        Matcher matcherfu = patternfu.matcher(zheng);
        Matcher matcherzero=patternzero.matcher(zheng);
        if(matcherzheng.matches()){
            System.out.println("为正整数。");
            return true;
        }
        else if(matcherfu.matches()) {
            System.out.println("为负整数。");
            return true;
        }
        else if(matcherzero.matches()) {
            System.out.println("为0。");
            return true;
        }
        else{
            System.out.println("不是整数。");
            return false;
        }

    }

    public boolean IfPhone(){//验证手机号码时，必须以 1 开头，且由 11 位数字组成；
        Pattern pattern=Pattern.compile("[1]\\d{10}");
        Matcher matcher=pattern.matcher(phone);
        return matcher.matches();
    }

    public boolean IfEmail(){//验证电子邮箱时，用户名大于等于 3 个字符，@后域名由 1 个或 2 个点组成；
        Pattern pattern=Pattern.compile("[a-zA-Z0-9]{3,}@([a-z0-9A-Z]+?\\.){1,2}+[a-zA-Z]$");
        Matcher matcher=pattern.matcher(email);
        return matcher.matches();
    }

    public boolean IfPost(){//验证邮政编码时，必须满足 6 个数字长度；
        Pattern pattern=Pattern.compile("\\d{6}");
        Matcher matcher=pattern.matcher(post);
        return matcher.matches();
    }

    public boolean IfIndentification(){//验证身份证号码时，长度为 18 位，且最后一位为数字或 X；
        Pattern pattern=Pattern.compile("\\d{17}[0-9X]");
        Matcher matcher=pattern.matcher(indentification);
        return matcher.matches();
    }

}
