package Assignment;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Chapter10_Assignment extends JFrame
{
    public Chapter10_Assignment()
    {
        super("위, 아래 방향키로 폰트 크기 조절");
        // Frame과 Pane설정
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        c.setBackground(Color.WHITE);

        JLabel label = new JLabel("Love Java"); //크기를 키울 대상
        c.add(label);

        Font font = new Font("TimesRoman", Font.PLAIN, 14);     // 폰트 설정. 처음 크기는 14
        // label.setFont(font);

        // KeyAdapter와 Listener를 활용한 이벤트 설정
        label.addKeyListener(new KeyAdapter()
        {
            @Override
            public void keyPressed(KeyEvent e)  // 키보드가 눌러지는 이벤트를 처리할 메소드
            {
                if(e.getKeyCode() == 38)    // 위쪽 방향키의 코드는 38이다
                {
                    JLabel la = (JLabel)e.getSource();  // 현재 label 객체 받아오기
                    Font f = la.getFont();
                    int size = f.getSize();
                    if(size >= 24)   // label의 크기가 24보다 크면
                    {
                        c.setBackground(Color.CYAN);    // 배경색을 하늘색으로 변경
                        return;
                    }
                    else
                        c.setBackground(Color.WHITE);  //아니면 그대로

                    la.setFont(new Font("TimesRoman", Font.PLAIN, size+1)); //위 방향키 입력마다 1씩 사이즈가 증가된다
                }
                else if(e.getKeyCode() == 40) 	// 아래쪽 코드는 40이다
                {
                    JLabel la = (JLabel)e.getSource();
                    Font f = la.getFont();
                    int size = f.getSize();
                    if(size <= 8)    // label의 크기가 8보다 작으면
                    {
                        c.setBackground(Color.YELLOW);  // 배경색을 노란색으로 변경
                        return;
                    }
                    else
                        c.setBackground(Color.WHITE);


                    la.setFont(new Font("TimesRoman", Font.PLAIN, size-1)); // 아래 방향키 입력마다 1씩 사이즈가 감소한다
                }
            }
        });



        setSize(300,150);
        setVisible(true);

        label.setFocusable(true); // 레이블이 포커스를 받을 수 있도록 지정
        label.requestFocus(); // 레이블에 키 입력 포커스 서정
    }
    static public void main(String [] args) {
        new Chapter10_Assignment();
    }
}
