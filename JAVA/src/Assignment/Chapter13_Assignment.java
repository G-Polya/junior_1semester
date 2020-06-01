package Assignment;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class GameblingThread extends Thread
{
    boolean gambling_flag = false;       // 스레드의 작동여부 설정
    JLabel la[];
    JLabel result;
    public GameblingThread(JLabel la[], JLabel result)  // 생성자
    {
        this.la = la;
        this.result = result;
    }

    synchronized  public void waitforGambling()     // 스레드의 run()에서 호출
    {
        if(!gambling_flag)           // 마우스 클릭에 의해 gamebling이 true가 될때까지 기다림
        {
            try
            {
                this.wait();
            }
            catch(InterruptedException e)
            {
                return;
            }
        }
    }
    synchronized public void startGambling() // 마우스 클릭시 이벤트핸들러에서 사용
    {
        gambling_flag = true;        // 마우스 클릭으로 스레드가 게임을 진행하도록 지시
        this.notify();          // 대기중인 스레드를 깨움
    }

    public void run()
    {
        while(true)
        {
            waitforGambling();      // 마우스클릭이 일어나기를 기다린다.
            for(int i = 0; i <3;i++)
            {
                int x = (int)(Math.random() * 5);
                la[i].setText(Integer.toString(x)); // 레이블에 0~4의 숫자 출력
                try
                {
                    sleep(200);
                }
                catch(InterruptedException e)
                {
                    return;
                }
            }

            // 200ms간격으로 3번 sleep하면서 숫자를 출력
            gambling_flag = false;   // 다른 게임이 작동되도록 설정

            int x = Integer.parseInt(la[0].getText());
            int y = Integer.parseInt(la[1].getText());
            int z = Integer.parseInt(la[2].getText());
            if(x == y && y == z)
                result.setText("              축하합니다!!");
            else
                result.setText("               아쉽군요!!");
        }

    }
}

class GamePanel extends JPanel
{
    JLabel la[];
    JLabel result;
    GameblingThread g;
    public GamePanel(GameblingThread g, JLabel la[], JLabel result)
    {
        this.g = g;
        this.la = la;
        this.result = result;
        setLayout(null);
        for(int i = 0; i<3;i++)
        {
            la[i].setFont(new Font("Arial", Font.ITALIC, 40));
            la[i].setForeground(Color.YELLOW);
            JPanel pa = new JPanel();
            pa.add(la[i]);
            pa.setBackground(Color.MAGENTA);
            pa.setSize(100,50);
            pa.setLocation(110*(i+1), 80);
            add(pa);

            pa.requestFocus();
        }

        addMouseListener(new MouseAdapter()
        {
            public void mouseClicked(MouseEvent e)
            {
                g.startGambling();
            }
        });

        result.setFont(new Font("", Font.BOLD, 25));

        add(result);
        result.setSize(500,25);
        result.setLocation(50,200);
    }
}

public class Chapter13_Assignment extends JFrame
{
    JLabel la[] = new JLabel[3];
    JLabel result = new JLabel("마우스를 클릭할 때마다 게임합니다.");
    public Chapter13_Assignment()
    {
        setTitle("스레드를 가진 겜블링");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        la[0] = new JLabel(Integer.toString(0));
        la[1] = new JLabel(Integer.toString(0));
        la[2] = new JLabel(Integer.toString(0));

        GameblingThread g = new GameblingThread(la, result);
        g.start();  // thraed 시작
        setContentPane(new GamePanel(g,la,result));
        setSize(550,350);
        setVisible(true);
        getContentPane().setFocusable(true);
        getContentPane().requestFocus();


    }

    public static void main(String[] args)
    {
        new Chapter13_Assignment();
    }
}
