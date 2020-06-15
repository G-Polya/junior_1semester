class ThreadClass1 extends Thread
{
    public long sum;
    public long getSum()
    {
        return sum;
    }

    public void run()
    {
        for(int i = 1; i<=100;i++)
            sum+=i;
        System.out.println("sum in run() : "+sum);
    }
}

public class WithoutJoin_test1
{
    public static void main(String[] args)
    {
        ThreadClass1 sumThread_0 = new ThreadClass1();
        sumThread_0.start();

        System.out.println("sum in main() : "+sumThread_0.getSum());
        System.out.println("main() ends");
    }
}
