package Assignment;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

//http://blog.naver.com/PostView.nhn?blogId=ouo7581&logNo=221466625634&parentCategoryNo=&categoryNo=62&viewDate=&isShowPopularPosts=true&from=search
public class Chapter11_Assignment extends JFrame
{
    int[] unit = {50000,100000,1000,500,100,50,10,1};
    private String[] str = {"금액","50,000원","10,000원","1,000원","500원","100원","50원","10원","1원"};
    private JLabel la = new JLabel();
    private JTextField[] tf = new JTextField[str.length];
    private JButton btn = new JButton("계산");
    private JCheckBox[] checkbox = new JCheckBox[unit.length-1];

    public Chapter11_Assignment()
    {
        setTitle("Money Change");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setBackground(Color.PINK);
        c.setLayout(null);

        la = new JLabel(str[0]);
        la.setSize(40,20);
        la.setLocation(30,20);
        c.add(la);

        tf[0] = new JTextField(30);
        tf[0].setSize(100,20);
        tf[0].setLocation(90,20);
        c.add(tf[0]);

        btn.setSize(70,20);
        btn.setLocation(200,20);

        btn.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                String input = tf[0].getText();
                if(input.length() == 0)
                    return;

                int money = Integer.parseInt(input);
                int m;

                for(int i = 0; i< unit.length;i++)
                {
                    if(i == unit.length-1) // 1원짜리 계산하는 경우. 즉, 마지막
                    {
                        m = money/unit[i];
                        tf[i+1].setText(Integer.toString(m));
                        break;
                    }

                    if(!checkbox[i].isSelected())       // 체크된거 확인
                    {
                        tf[i+1].setText("0");
                        continue;
                    }

                    m = money/unit[i];
                    tf[i+1].setText(Integer.toString(m));
                    if(m>0)
                        money = money % unit[i];
                }
            }
        });

        add(btn);

        for(int i = 1; i< str.length;i++)
        {
            la = new JLabel(str[i]);
            la.setHorizontalAlignment(JLabel.RIGHT);
            la.setSize(50,20);
            la.setLocation(50,50+(i*20));
            add(la);

            tf[i] = new JTextField(30);
            tf[i].setHorizontalAlignment(JTextField.CENTER);
            tf[i].setSize(70,20);
            tf[i].setLocation(120,50+(i*20));
            add(tf[i]);

            if(i < str.length-1)
            {
                checkbox[i-1] = new JCheckBox();
                checkbox[i-1].setBackground(Color.PINK);
                checkbox[i-1].setSize(20,20);
                checkbox[i-1].setLocation(210,50+(i*20));
                add(checkbox[i-1]);
            }
        }

        setSize(300,300);
        setVisible(true);
    }


    public static void main(String[] args)
    {
        new Chapter11_Assignment();
    }
}
