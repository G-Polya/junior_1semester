import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.*;

public class chapter11_Example1 extends JFrame
{
    private JButton btn =  new JButton("test button");
    public chapter11_Example1()
    {
        super("CheckBox Practice Frame");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout((new FlowLayout()));

        JCheckBox a = new JCheckBox("버튼 비활성화");
        JCheckBox b = new JCheckBox("버튼 감추기");
        c.add(a);
        c.add(b);
        c.add(btn);

        a.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e)
            {
                if(e.getStateChange() == ItemEvent.SELECTED)
                    btn.setEnabled(false);
                else
                    btn.setEnabled(true);
            }
        });

        b.addItemListener(new ItemListener()
        {
            @Override
            public void itemStateChanged(ItemEvent e)
            {
                if(e.getStateChange() == ItemEvent.SELECTED)
                    btn.setVisible(false);
                else
                    btn.setVisible(true);
            }
        });

        setSize(250,150);
        setVisible(true);
    }

    public static void main(String[] args)
    {
        new chapter11_Example1();
    }
}

