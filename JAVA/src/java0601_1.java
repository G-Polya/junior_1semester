class ThreadA extends Thread
{
    private boolean stop = false;
    private boolean flag = true;
    private static final int DELAY_TIME = 500 ;

    public void setFlag(boolean flag)
    {
        this.flag=flag;
    }

    public void setStop(boolean stop)
    {
        this.stop=stop;
    }

    public void run()
    {
        while(!stop)
        {
            if(flag)
            {
                System.out.println("ThreadA is working..");
            }
            else
            {
                // flag가 false가 되면 다른 스레드에게 실행 양보
                Thread.yield();
            }
            try
            {
                Thread.sleep(DELAY_TIME);
            } catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}

class ThreadB extends Thread{
    private boolean stop = false;
    private boolean flag = true;
    private static final int DELAY_TIME = 500 ;

    public void setFlag(boolean flag)
    {
        this.flag=flag;
    }

    public void setStop(boolean stop)
    {
        this.stop=stop;
    }

    public void run()
    {
        while(!stop)
        {
            if(flag)
            {
                System.out.println("ThreadB is working..");
            }
            else
            {
                // flag가 false가 되면 다른 스레드에게 실행 양보
                Thread.yield();
            }
            try
            {
                Thread.sleep(DELAY_TIME);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}


public class java0601_1
{
    private static final int RUNNING_TIME = 2500;

    public static void main(String[] args)
    {
        ThreadA threadA = new ThreadA();
        ThreadB threadB = new ThreadB();

        // ThreadA, ThreadB start
        System.out.println("ThreadA and ThreadB : simultaneous start");
        threadA.start();
        threadB.start();

        try
        {
            Thread.sleep(RUNNING_TIME);
        } catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        // only ThreadB start
        System.out.println("Only ThreadB start");
        threadA.setFlag(false);     //threadA는 실행을 양보하고 실행대기 상태로 전환됨

        try
        {
            Thread.sleep(RUNNING_TIME);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        System.out.println("Only ThreadA start");
        threadA.setFlag(true);  // threadA를 다시 실행시킴
        threadB.setFlag(false); //threadB는 실행을 양보하고 실행대기 상태로 전환됨

        try
        {
            Thread.sleep(RUNNING_TIME);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        System.out.println("ThreadA and ThreadB are end");
        threadA.setStop(true);
        threadB.setStop(true);

        System.out.println("main() is end");
    }
}