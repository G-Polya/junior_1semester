class ThreadClass_s extends Thread
{


    @Override
    public void run()
    {
        for(int i = 0; i < 10;i++)
            System.out.println(Thread.currentThread().getName()+ " : "+(i+1));
    }
}

public class WithoutJoin_test2
{
    public static void main(String[] args)
    {
        ThreadClass_s thread1 = new ThreadClass_s();
        thread1.setName("첫번쨰 Thread");
        thread1.start();

        ThreadClass_s thread2 = new ThreadClass_s();
        thread2.setName("두번째 Thread");
        thread2.start();

        System.out.println("프로그램 종료");
    }
}
