package Assignment;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Chapter10_Assignment extends JFrame {
    public Chapter10_Assignment() {
        super("+,- 키로 폰트 크기 조절");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        c.setBackground(Color.WHITE);

        JLabel label = new JLabel("Love Java");
        c.add(label);

        Font font = new Font("TimesRoman", Font.PLAIN, 14);

        label.setFont(font); // 14 픽셀 크기
        label.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if(e.getKeyCode() == 38) {		// 위쪽 누름
                    JLabel la = (JLabel)e.getSource();
                    Font f = la.getFont();
                    int size = f.getSize();
                    if(size > 24)
                    {
                        c.setBackground(Color.CYAN);
                        return;
                    }
                    else
                        c.setBackground(Color.WHITE);

                    la.setFont(new Font("TimesRoman", Font.PLAIN, size+1));
                }
                else if(e.getKeyCode() == 40) {		// 아래쪽 누름
                    JLabel la = (JLabel)e.getSource();
                    Font f = la.getFont();
                    int size = f.getSize();
                    if(size < 8)
                    {
                        c.setBackground(Color.YELLOW);
                        return;
                    }
                    else
                        c.setBackground(Color.WHITE);


                    la.setFont(new Font("TimesRoman", Font.PLAIN, size-1));
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
