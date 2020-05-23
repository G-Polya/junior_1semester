package Assignment;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class Chapter11_Assignment extends JFrame
{
    int[] unit = {50000,100000,1000,500,100,50,10,1};
    private String[] str = {"금액","50,000원","10,000원","1,000원","500원","100원","50원","10원","1원"};
    private JLabel la = new JLabel();
    private JTextField[] tf = new JTextField[str.length];
    private JButton btn = new JButton("계산");    // 계산 버튼
    private JCheckBox[] checkbox = new JCheckBox[unit.length-1];    // 화폐 선택

    public Chapter11_Assignment()
    {
        setTitle("Money Change");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setBackground(Color.PINK);
        c.setLayout(null);

        // 금액을 입력할 부분. label과 TextField
        la = new JLabel(str[0]);    //"금액" 라벨
        la.setSize(40,20);
        la.setLocation(30,20);
        c.add(la);
        tf[0] = new JTextField(30); // 금액이 입력될 textfield
        tf[0].setSize(100,20);
        tf[0].setLocation(90,20);
        c.add(tf[0]);

        // 체크박스, JTextField, label생성
        for(int i = 1; i< str.length;i++)
        {
            // label
            la = new JLabel(str[i]);
            la.setHorizontalAlignment(JLabel.RIGHT);
            la.setSize(50,20);
            la.setLocation(50,50+(i*20));
            add(la);

            // JTextField
            tf[i] = new JTextField(30);
            tf[i].setHorizontalAlignment(JTextField.CENTER);
            tf[i].setSize(70,20);
            tf[i].setLocation(120,50+(i*20));
            add(tf[i]);

            // JCheckbox
            if(i < str.length-1)
            {
                checkbox[i-1] = new JCheckBox();
                checkbox[i-1].setBackground(Color.PINK);
                checkbox[i-1].setSize(20,20);
                checkbox[i-1].setLocation(210,50+(i*20));
                add(checkbox[i-1]);
            }
        }


        btn.setSize(70,20);
        btn.setLocation(200,20);

        btn.addActionListener(new ActionListener()  // 계산 버튼 이벤트 처리
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                String input = tf[0].getText(); //입력된 금액
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

                    if(!checkbox[i].isSelected())       // 체크된거 확인. 체크 안된거는 0으로. 체크된걸로만 거슬러준다
                    {
                        tf[i+1].setText("0");
                        continue;
                    }

                    m = money/unit[i];      // 화폐의 개수. 65,500원에서 천원짜리로 거슬렀으면 65개를 거슬러준다
                    tf[i+1].setText(Integer.toString(m));       // JTextField에 출력
                    if(m>0)
                        money = money % unit[i];    // 나머지 돈에 대한 처리를 위한 과정
                }
            }
        });

        add(btn);



        setSize(300,300);
        setVisible(true);
    }


    public static void main(String[] args)
    {
        new Chapter11_Assignment();
    }
}
