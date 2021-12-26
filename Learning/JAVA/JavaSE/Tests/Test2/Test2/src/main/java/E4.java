public class E4 {
    public static void e4() {
        int count= 0 ;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if ( i==1 && j==1 )
                    continue;
//                System.out.println("i: " + i + " j: " + j);
                count++;
            }
        }
        System.out.println(count);
    } }