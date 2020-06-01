import java.awt.Graphics;
import java.awt.Image;
import javax.swing.JFrame;

public class java0601_DoubleBuffering extends JFrame {
    private final int WIDTH = 500;
    private final int HEIGHT = 600;

    private boolean move_down = true;

    private final int x = 100;
    private final int y_MAX = 200;
    private final int y_MIN = 50;
    private int y1, y2;
    private Image img;
    private Graphics img_graphic;

    public java0601_DoubleBuffering() {
        setTitle("Double Buffering");
        setSize(WIDTH, HEIGHT);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
        setResizable(false);
        setLayout(null);

        y1 = y_MIN;
        y2 = y_MAX;
    }

    public void paint(Graphics g) {
        //더블버퍼링 On
        img = createImage(WIDTH, HEIGHT);
        img_graphic = img.getGraphics();
        paintComponents(img_graphic);
        img_graphic.drawLine(x, y1, x +350, y2);
        //g.drawImage(....,  x_coord, y_coord, null);
        img_graphic.drawString("Double Buffering", 100, 500);
        g.drawImage(img, 0, 0, null); //위의 과정을 마친 이미지를 한번에 화면에 뿌림

        YposChange(); // Y좌표를 변경하는 메소드
        repaint(); //강제로 paint함수 호출
    }

    public void YposChange() {
        if (move_down) {
            y1++;
            y2--;
            if (y1 >= y_MAX) {
                move_down = !move_down;
            }
        }

        if (!move_down) {
            y1--;
            y2++;
            if (y1 <= y_MIN) {
                move_down = !move_down;
            }
        }
    }

    public static void main(String[] args) {
        new java0601_DoubleBuffering();
    }
}

