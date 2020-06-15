

public class WithJoin_test2
{
    public static void main(String[] args)
    {
        ThreadClass_s thread_k1 = new ThreadClass_s();
        thread_k1.setName("첫번쨰 Thread");
        thread_k1.start();
        try
        {
            thread_k1.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        ThreadClass_s thread_k2 = new ThreadClass_s();
        thread_k2.setName("두번째 Thread");
        thread_k2.start();
        try
        {
            thread_k2.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        System.out.println("프로그램 종료");
    }
}
