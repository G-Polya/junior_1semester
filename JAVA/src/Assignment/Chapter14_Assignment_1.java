package Assignment;

import javax.swing.*;
import java.awt.*;

public class Chapter14_Assignment_1 extends JFrame
{
    public Chapter14_Assignment_1()
    {
        setTitle("탭팬 만들기 예제");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        JTabbedPane pane = createTabbedPane();      // 탭팬 생성
        c.add(pane, BorderLayout.CENTER);       // 탭팬을 컨텐트팬에 부착.
        setSize(250,250);
        setVisible(true);
    }

    private JTabbedPane createTabbedPane()
    {
        JTabbedPane pane = new JTabbedPane();           // 탭팬 객체 생성
        pane.addTab("tab1",new JLabel(new ImageIcon("images/사과.jpg")));         // 첫번째 탭 설정. ImageIcon 이미지레이블을 가지는 JLabel을 출력
        pane.addTab("tab2", new JLabel(new ImageIcon("images/Desert.png")));     // 두번째 탭 설정
        pane.addTab("tab3", new MyPanel());                                             // 세번째 탭 설정. 컴포넌트로 MyPanel을 받는다
        pane.addTab("tab4",new JLabel(new ImageIcon("images/학번이름.jpg")));     // 자신의 학번과 성명 사진을 tab4에 부착.

        return pane;
    }

    class MyPanel extends JPanel    // 3번째 탭의 컴포넌트로 사용될 패널
    {
        public MyPanel()
        {
            this.setBackground(Color.YELLOW);
        }

        public void paintComponent(Graphics g)
        {
            super.paintComponent(g);
            g.setColor(Color.RED);
            g.fillRect(10,10,50,50);
            g.setColor(Color.BLUE);
            g.fillOval(10,70,50,05);
            g.setColor(Color.BLACK);
            g.drawString("tab 3에 들어가는 JPanel 입니다. ",30,50);
        }
    }

    public static void main(String[] args)
    {
        new Chapter14_Assignment_1();
    }
}
