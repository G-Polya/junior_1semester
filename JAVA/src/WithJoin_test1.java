public class WithJoin_test1
{
    public static void main(String[] args)
    {
        ThreadClass1 sumThread1 = new ThreadClass1();
        sumThread1.start();

        try
        {
            sumThread1.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
            return;
        }

        System.out.println("sum in main() : "+ sumThread1.getSum());
        System.out.println("main() ends");
    }
}
