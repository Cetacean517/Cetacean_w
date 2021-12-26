public class sum_even {
    public static void sum(){
        /**输出0-20中的偶数，和这些偶数的和*/
    int sum = 0;
    for(int i = 0;i<21;i+=2)
    {
        System.out.print(i);
        System.out.print(' ');
        sum+=i;
    }
    System.out.println(sum);
    }
}
