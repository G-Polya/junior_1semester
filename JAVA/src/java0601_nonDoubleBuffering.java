import java.awt.Image;
import java.awt.Graphics;
import javax.swing.JFrame;

public class java0601_nonDoubleBuffering extends JFrame {
    private final int WIDTH = 500;
    private final int HEIGHT = 600;

    private boolean move_down = true;

    private final int x = 100;
    private final int y_MAX = 200;
    private final int y_MIN = 50;
    private int y1, y2;

    private Image img;
    private Graphics img_graphic;

    public java0601_nonDoubleBuffering() {
        setTitle("Non Double Buffering");
        setSize(WIDTH, HEIGHT);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
        setResizable(false);
        setLayout(null);

        y1 = y_MIN;
        y2 = y_MAX;
    }

    public void paint(Graphics g) {
        // Non double buffering
        paintComponents(g);
        g.drawLine(x, y1, x +350, y2);
        //g.drawImage(....,  x_coord, y_coord, null);
        g.drawString("non Double Buffer", 100, 500);

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
        new java0601_nonDoubleBuffering();
    }
}

