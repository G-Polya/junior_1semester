package Assignment;
import java.awt.*;
import javax.swing.*;

//https://coding-restaurant.tistory.com/69

public class Chapter9_Assignment extends JFrame
{
    public Chapter9_Assignment()
    {
        setTitle("계산기 프레임");
        setSize(400,400);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        Container c = getContentPane();
        JPanel pn = new JPanel();
        JPanel ps = new JPanel();
        JPanel pc = new JPanel();

        pn.setBackground(Color.LIGHT_GRAY);
        pc.setLayout(new GridLayout(5,4));
        ps.setBackground(Color.YELLOW);

        c.add(pc);
        c.add(pn, BorderLayout.NORTH);
        c.add(ps,BorderLayout.SOUTH);

        JLabel l1 = new JLabel("수식 입력");
        JTextField tf1 = new JTextField(10);
        pn.add(l1);
        pn.add(tf1);

        JLabel l2 = new JLabel("계산 결과");
        JTextField tf2 = new JTextField(10);
        ps.add(l2);
        ps.add(tf2);

        for(int i = 0; i< 20;i++)
        {
            JButton b = new JButton();
            String[] operator = {"CE","Enter","+","-","x","/","제곱","세제곱","제곱근","세제곱근"};
            pc.add(b);
            if(i<10)
                b.setText(i+"");
            else
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
