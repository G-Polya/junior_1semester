package Assignment;
import java.awt.*;
import javax.swing.*;


public class Chapter9_Assignment extends JFrame
{
    public Chapter9_Assignment()
    {
        setTitle("계산기 프레임");        //프로그램 제목
        setSize(400,400);   // 프로그램 가로세로 크기
        setDefaultCloseOperation(EXIT_ON_CLOSE);    // 종료메소드

        Container c = getContentPane();
        JPanel pn = new JPanel();       // 수식이 입력될 패널
        JPanel ps = new JPanel();       // 계산 결과가 출력될 패널
        JPanel pc = new JPanel();       // 계산 버튼이 들어갈 패널

        // 패널의 색과 위치 선정
        pn.setBackground(Color.LIGHT_GRAY);
        pc.setLayout(new GridLayout(5,4));  // 계산버튼이 들어갈 패널은 5 * 4 그리드로 나눠줌
        ps.setBackground(Color.YELLOW);

        // 컨테이너에 패널 추가
        c.add(pc);
        c.add(pn, BorderLayout.NORTH);
        c.add(ps,BorderLayout.SOUTH);

        // pn 패널의 내용 추가
        JLabel l1 = new JLabel("수식 입력");
        JTextField tf1 = new JTextField(10);
        pn.add(l1);
        pn.add(tf1);

        // ps 패널에 내용추가
        JLabel l2 = new JLabel("계산 결과");
        JTextField tf2 = new JTextField(10);
        ps.add(l2);
        ps.add(tf2);

        // pc 패널에 내용추가
       for(int i = 0; i< 20;i++)
        {
            JButton b = new JButton(); //버튼 생성. 총 20개의 버튼
            String[] operator = {"CE","Enter","+","-","x","/","제곱","세제곱","제곱근","세제곱근"}; // 버튼의 내용이 될 연산자
            pc.add(b);
            if(i<10)    // 0~9까지의 숫자버튼 생성
                b.setText(i+"");
            else        // 연산자 버튼
                b.setText(operator[i-10]);

            if(i>11)
                b.setOpaque(true);
        }
        setVisible(true);
    }

    public static void main(String[] args)
    {
        new Chapter9_Assignment();
    }
}
