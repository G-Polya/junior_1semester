package Assignment;

import java.time.LocalTime;
import java.util.*;
import java.awt.*;
import javax.swing.*;

// 현재의 시 분 초에 대한 클래스
class ClockController
{
    public int getHour()//현재 시
    {
        return LocalTime.now().getHour();
    }

    public int getMinute() // 현재 분
    {
        return LocalTime.now().getMinute();
    }

    public int getSecond() // 현재 초
    {
        return LocalTime.now().getSecond();
    }

}

class ClockUpdate
{

    private UI ui;              // UI 작업을 위한 필드
    private java.util.Timer t;          // 시간 작업을 수행하기 위한 필드
    private ClockController cont;       // 현재 시간을 가져오기 위한 필드

    public ClockUpdate(UI _ui)      // ui를 파라미터로 받는 생성자
    {
        this.ui = _ui;
        this.cont = new ClockController();      // 현재시간 가져오기

        startTimer();       // 작업수행
    }

    private void startTimer()
    {
        t = new java.util.Timer();


        t.schedule(new TimerTask()
        {

            @Override
            public void run()       // 현재 시간에 맞게 설정하는 작업을 수행한다.
            {
                ui.updateHour(cont.getHour());
                ui.updateMinute(cont.getMinute());
                ui.updateSecond(cont.getSecond());
            }
        }, 0, 1000);
    }
}

final class Constants
{

    static final String APP_TITLE = "Digitaluhr";

    // 7개의 boolean으로 표현한 7 segment
    public static final boolean[][] CLOCKBIN =
            {
                    new boolean[] { true, true, true, true, true, true, false }, 			// 0
                    new boolean[] { false, true, true, false, false, false, false }, 		// 1
                    new boolean[] { true, true, false, true, true, false, true },			// 2
                    new boolean[] { true, true, true, true, false, false, true },			// 3
                    new boolean[] { false, true, true, false, false, true, true },			// 4
                    new boolean[] { true, false, true, true, false, true, true },			// 5
                    new boolean[] { true, false, true, true, true, true, true },			// 6
                    new boolean[] { true, true, true, false, false, false, false },		// 7
                    new boolean[] { true, true, true, true, true, true, true },			// 8
                    new boolean[] { true, true, true, true, false, true, true }			// 9
            };

    public static int getNthDigit(int number, int base, int n)  // hour, minute, second를 구분하기 위해 사용되는 메소드
    {
        return (int) ((number / Math.pow(base, n - 1)) % base);
    }
}


// 7 segment panel class
// 이 클래스의 객체하나가 digit하나를 의미하게 된다. 즉 7 segment가 모여서 digit하나를 의미
class SevenSegment extends JPanel
{
    private static final long serialVersionUID = -4980210296562972446L;

    // Segment의 경계를 구분
    private Rectangle[] rect =
    {
            new Rectangle(10,10,115,10),
            new Rectangle(125,20,10,115),
            new Rectangle(125,145,10,115),
            new Rectangle(10,260,115,10),
            new Rectangle(0,145,10,115),
            new Rectangle(0,20,10,115),
            new Rectangle(10,135,115,10)
    };

    private JPanel[] pnlSeg;    //digit하나를 의미.

    public JPanel getPanelSeg(int index)    //index에 해당하는 JPanel
    {
        return this.pnlSeg[index];
    }

    public SevenSegment()   // 생성자
    {
        super();
        initSegment(new Dimension(80,80), Color.DARK_GRAY);

    }

    public SevenSegment(Dimension dim, Color col)   // 생성자
    {
        super();
        initSegment(dim, col);
    }

    // Segment 초기화.
    private void initSegment(Dimension dim, Color col)
    {
        this.setName("HauptSegment");
        this.setBackground(Color.WHITE);
        this.setSize(dim);
        this.pnlSeg = new JPanel[7];    // 7개의 패널(segment)가 모여서 하나의 digit을 의미한다. 

        // 7 segment 설정
        for (int j = 0; j < 7; j++)
        {
            this.pnlSeg[j] = new JPanel();
            this.pnlSeg[j].setName("SegmentTeil #"+j);
            this.pnlSeg[j].setToolTipText(this.pnlSeg[j].getName());
            this.pnlSeg[j].setBounds(rect[j]);
            this.pnlSeg[j].setLayout(null);
        }

    }

    public Rectangle getRect(int index)
    {
        return rect[index];
    }
}

// 프레임이 되는 클래스
class UI extends JFrame
{
    private static final long serialVersionUID = -4621924450652779205L;
    private SevenSegment[] segment = new SevenSegment[8];   // digit하나를 표현하는 7segment 그룹의 배열.

    public UI()
    {
        this.setName("UI_Frame");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle(Constants.APP_TITLE);
        setSize(880, 320);
        setLocation(800, 600);
        setResizable(false);
        getContentPane().setBackground(Color.WHITE);
        FlowLayout layout = new FlowLayout();
        layout.setHgap(8);
        layout.setVgap(0);
        layout.setAlignment(FlowLayout.LEFT);
        setLayout(layout);
        setAlwaysOnTop(true);
        Dimension dim = new Dimension();

        // 시, 분, 초의 총 6개의 digit에 대한 설정.
        for (int i = 0; i < 6; i++)
        {
            dim.setSize(getSize().width/6.5f, 300);
            segment[i] = new SevenSegment(dim, Color.LIGHT_GRAY);
            segment[i].setName("Segment #"+i);
            segment[i].setPreferredSize(dim);
            segment[i].setLayout(null);

            // segment에 대한 처리
            for (int j = 0; j < 7; j++)
            {
                // 시는 RED로, 분은 CYAN으로, 초는 GREEN으로
                segment[i].getPanelSeg(j).setBackground((i < 2) ? Color.RED : (i < 4) ? Color.CYAN : (i < 6) ? Color.GREEN : Color.WHITE);
                segment[i].getPanelSeg(j).setBorder(BorderFactory.createLineBorder(Color.BLACK, 3));
                segment[i].add(segment[i].getPanelSeg(j));
            }
            getContentPane().add(segment[i]);
        }

    }


    // 현재 시에 맞게 segment 패널 재설정. boolean으로 표현한 7 segment를 디자인한다.
    public void updateHour(int hour) // 0 & 1
    {
        for (int i = 0; i < 7; i++)
        {
            segment[0].getPanelSeg(i).setVisible((Constants.CLOCKBIN[Constants.getNthDigit(hour, 10, 2)][i] == true) ? true : false);
            segment[1].getPanelSeg(i).setVisible((Constants.CLOCKBIN[Constants.getNthDigit(hour, 10, 1)][i] == true) ? true : false);
        }
    }

    //현재 분의 맞게 segment 패널 재설정
    public void updateMinute(int minute) // 2 & 3
    {
        for (int i = 0; i < 7; i++)
        {
            segment[2].getPanelSeg(i).setVisible((Constants.CLOCKBIN[Constants.getNthDigit(minute, 10, 2)][i] == true) ? true : false);
            segment[3].getPanelSeg(i).setVisible((Constants.CLOCKBIN[Constants.getNthDigit(minute, 10, 1)][i] == true) ? true : false);
        }
    }

    //현재 초에 맞게 segment 패널 재설정
    public void updateSecond(int second) // 4 & 5
    {
        for (int i = 0; i < 7; i++)
        {
            segment[4].getPanelSeg(i).setVisible((Constants.CLOCKBIN[Constants.getNthDigit(second, 10, 2)][i] == true) ? true : false);
            segment[5].getPanelSeg(i).setVisible((Constants.CLOCKBIN[Constants.getNthDigit(second, 10, 1)][i] == true) ? true : false);
        }
    }

}

public class UI_Assignment2_DigitalClock
{
    public static void main(String[] args)
    {
        UI ui = new UI();
        ui.setVisible(true);

        @SuppressWarnings("unused")
        ClockUpdate clockUpdate = new ClockUpdate(ui);

    }
}
