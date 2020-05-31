package Assignment;
import java.awt.*;
import java.awt.event.*;
import java.util.Locale;
import javax.swing.*;

class Panel extends JPanel
{
    ImageIcon target = new ImageIcon("images/사과.jpg");
    ImageIcon background = new ImageIcon("images/Desert.png");
    Image target_image = target.getImage();
    Image background_image = background.getImage();

    boolean hide_and_show = true;
    JLabel targetLabel = new JLabel(target);

    Point previous;
    Point following;
    Point current;
    int initial_x = 100, initial_y = 100;

    public Panel()
    {
        JButton hs_Button = new JButton("Hide or Show");
        JRadioButton dragTarget = new JRadioButton("Drag Target");
        JRadioButton dragCircle = new JRadioButton("Drag Circle");

        targetLabel.setLocation(600,600);

        hs_Button.setLocation(0,20);
        hs_Button.setSize(100,80);
        add(hs_Button);


        ButtonGroup radioGroup = new ButtonGroup();
        radioGroup.add(dragTarget);
        radioGroup.add(dragCircle);

        add(dragTarget);
        add(dragCircle);
        add(targetLabel);

        hs_Button.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                hide_and_show = !hide_and_show;
                Panel.this.repaint();
            }
        });

        targetLabel.addMouseListener(new MouseAdapter()
        {
            public void mousePressed(MouseEvent e)
            {
                if(dragTarget.isSelected())
                    previous = e.getPoint();
            }
        });

        targetLabel.addMouseMotionListener(new MouseMotionAdapter()
        {
            @Override
            public void mouseDragged(MouseEvent e)
            {
                if(dragTarget.isSelected())
                {
                    following = e.getPoint();
                    Component component = (JComponent)(e.getSource());
                    current = component.getLocation();

                    component.setLocation(current.x + following.x-previous.x, current.y+following.y-previous.y);
                    component.getParent().repaint();
                }
            }
        });

        addMouseMotionListener(new MouseMotionAdapter()
        {
            public void mouseDragged(MouseEvent e)
            {
                if(dragCircle.isSelected() && (e.getX() <= initial_x + 25  && e.getX() >= initial_x-25) && (e.getY() <= initial_y+25 && e.getY() >= initial_y-25)  )
                {
                    initial_x = e.getX();
                    initial_y = e.getY();
                    repaint();
                }
            }
        });

    }

    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);

        if(hide_and_show)
            g.drawImage(background_image,0,0,getWidth(),getHeight(),this);

        g.setColor(Color.GREEN);
        g.fillOval(initial_x-25,initial_y-25,50,50);
    }

}

public class Chapter12_Assignment extends JFrame
{
    public Chapter12_Assignment()
    {
        super("이미지 그리기 연습");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setContentPane(new Panel());
        setSize(1000,1000);
        setVisible(true);
    }


    public static void main(String[] args)
    {
        new Chapter12_Assignment();
    }
}
