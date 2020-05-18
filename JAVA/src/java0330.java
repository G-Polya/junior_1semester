public class java0330
{
    public static void main(String[] args)
    {
//        out:
//            for(int i = 0; i<5 ;i++)
//            {
//                for(int j =0;j<5;j++)
//                {
//                    if( j == 3)
//                        continue out;
//                    System.out.println(i + " "+ j );
//                }
//                System.out.println("End of J");
//            }
//        all:
//        for(int i = 0; i<5;i++)
//        {
//            for(int j =0; j < 5; j++)
//            {
//                if(j == 3) break all;
//                System.out.println(i + " "+ j);
//            }
//            System.out.println("End of J");
//        }

        for(int i = 0; i < args.length;i++)
        {
            System.out.println(args[i] + " ");
        }
    }
}