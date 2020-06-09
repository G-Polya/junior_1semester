package Assignment;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



public class UI_Assignment_PictureTask extends JFrame implements ActionListener
{
    ImageIcon icon = new ImageIcon("images/사과.jpg");
    Image img = icon.getImage();
    JLabel imgLabel = new JLabel(icon);

    static final int[] flag = {0,1,2,3,4,5};
    int command = 0;

    JButton[] task_btns = {new JButton("정상"), new JButton("회전"), new JButton("이동"),
            new JButton("상하반전"), new JButton("좌우반전"), new JButton("크기변경")};

    public UI_Assignment_PictureTask()
    {
        super("Picture Task");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel task_panel = new JPanel();
        task_panel.setSize(1500, 30);

        add(task_panel);
        JPanel imgPanel = new JPanel();
        imgPanel.setLocation(0,40);
        imgPanel.add(imgLabel);
        add(imgPanel);
        

        for(int i = 0; i < task_btns.length;i++)
        {
            task_btns[i].setSize(100,30);
            task_btns[i].setLocation(80+(i*140),210);
            task_btns[i].addActionListener(this);
            task_panel.add(task_btns[i]);


        }




        setSize(1500,1000);
        setVisible(true);

    }


    @Override
    public void actionPerformed(ActionEvent e)
    {
        JButton b = (JButton)e.getSource();
        if(b == task_btns[0])
            command = flag[0];
        else if(b == task_btns[1])
            command = flag[1];
        else if(b == task_btns[2])
            command = flag[2];
        else if(b== task_btns[3])
            command = flag[3];
        else if(b == task_btns[4])
            command = flag[4];
        else if(b == task_btns[5])
            command = flag[5];
        repaint();
    }


    @Override
    public  void paint(Graphics g)
    {
        int img_width = img.getWidth(this);
        int img_height = img.getHeight(this);
        switch (command)
        {
            case 0: // 정상
                g.drawImage(img,0,0,this);
                break;
            case 3: // 상하반전

                break;
            case 4:// 좌우반전
                break;

            case 5:
                g.drawImage(img,0,0,img_width*2, img_height*2,0,0,img_width,img_height,this);
                break;


        }
    }


    public static void main(String[] args)
    {
        new UI_Assignment_PictureTask();
    }
}
