package Assignment;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Panel extends JPanel
{
    ImageIcon target = new ImageIcon("images/사과.jpg");              // 사과
    ImageIcon background = new ImageIcon("images/Desert.png");      // 배경
    Image target_image = target.getImage();             // 사과이미지
    Image background_image = background.getImage();     // 배경이미지

    JLabel targetLabel = new JLabel(target);

    Point previous;

    int initial_x = 100, initial_y = 100;   // 초록원의 위치

    boolean show_flag = true;               // 배경을 보이게 or 안보이게


    public Panel()
    {
        JButton show_Button = new JButton("Hide or Show");          // 배경을 보이게 or 안보이게

        // Hide or Show버튼 설정
        show_Button.setLocation(0,20);
        show_Button.setSize(100,80);
        add(show_Button);

        // 라디오버튼 설정
        JRadioButton dragTarget = new JRadioButton("Drag Target");
        JRadioButton dragCircle = new JRadioButton("Drag Circle");

        ButtonGroup radioGroup = new ButtonGroup();
        radioGroup.add(dragTarget);
        radioGroup.add(dragCircle);

        targetLabel.setLocation(600,600);

        add(dragTarget);
        add(dragCircle);
        add(targetLabel);


        // hide or show 버튼 이벤트처리
        show_Button.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                show_flag = !show_flag;
                Panel.this.repaint();       // show_flag에 따라 componentPaint가 수행됨됨
           }
        });

        // 타겟라디오버튼 이벤트처리
        targetLabel.addMouseListener(new MouseAdapter()
        {
            public void mousePressed(MouseEvent e)
            {
                if(dragTarget.isSelected())
                    previous = e.getPoint();
            }
        });

        // 타겟 이미지 드래그 이벤트처리
        targetLabel.addMouseMotionListener(new MouseMotionAdapter()
        {
            @Override
            public void mouseDragged(MouseEvent e)
            {
                if(dragTarget.isSelected())
                {
                    Point  current = e.getPoint();
                    Component component = (JComponent)(e.getSource());
                    Point following = component.getLocation();    // 드래그 되는 위치의 좌표 저장

                    component.setLocation(following.x + current.x-previous.x, following.y+current.y-previous.y);
                    component.getParent().repaint();    // paintComponet호출
                }
            }
        });

        // Circle drag이벤트처리
        addMouseMotionListener(new MouseMotionAdapter()
        {
            public void mouseDragged(MouseEvent e)
            {
                // Circle drag 라디오버튼 체크, 클릭한 곳의 위치 체크
                if(dragCircle.isSelected() && (e.getX() <= initial_x + 25  && e.getX() >= initial_x-25) && (e.getY() <= initial_y+25 && e.getY() >= initial_y-25)  )
                {
                    // 위치 재설정해서 리페인트
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

        if(show_flag)
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
