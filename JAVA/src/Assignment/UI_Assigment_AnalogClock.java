package Assignment;

import java.awt.*;
import java.awt.event.*;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.TimeZone;
import javax.swing.*;

public class UI_Assigment_AnalogClock extends JPanel
{

    TimeZone clockTimeZone = TimeZone.getDefault();
    Calendar cal = (Calendar) Calendar.getInstance(clockTimeZone);
    ActionListener repaintListener = (ActionEvent e) ->
    {
        cal = (Calendar) Calendar.getInstance(clockTimeZone);
        repaint();
    };

    Timer clockTimer = new Timer(100, repaintListener);     // javax.swing.Timer // https://sjh836.tistory.com/36

    public UI_Assigment_AnalogClock()
    {
        clockTimer.start();
    }

    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        g.setColor(Color.BLUE);
        g.fillOval(40, 40, 220, 220);
        g.setColor(Color.WHITE);
        g.fillOval(50, 50, 200, 200);

        double second = cal.get(Calendar.SECOND);
        double minute = cal.get(Calendar.MINUTE);
        double hours = cal.get(Calendar.HOUR);

        // 눈금 표식
        for (int i = 0; i < 60; i++)
        {
            int length = 90;
            double rad = (i * 6) * (Math.PI) / 180;     // 표시될 각도

            //5분단위로 긴 눈금표식
            if (i % 5 == 0)
            {
                length = 82;
                g.setColor(Color.BLUE);
            }
            else
            {
                g.setColor(Color.GRAY);
            }

            // 눈금의 정확한 위치
            int x = 150 + (int) (95 * Math.cos(rad - (Math.PI / 2)));
            int y = 150 + (int) (95 * Math.sin(rad - (Math.PI / 2)));
            int x1 = 150 + (int) (length * Math.cos(rad - (Math.PI / 2)));
            int y1 = 150 + (int) (length * Math.sin(rad - (Math.PI / 2)));
            g.drawLine(x, y, x1, y1);
        }


        drawHands(g,hours,minute,second);

        SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss");
        g.setColor(Color.BLUE);
        g.setFont(new Font("Tahoma", Font.BOLD, 16));
        g.drawString(sdf.format(cal.getTime()), 120, 20);
        g.setFont(new Font("Arial", Font.BOLD, 10));

    }

    // 초침 분침 시침 각도
    public void drawHands(Graphics g, double hours, double minute, double second)
    {
        double rHours = ((hours + (minute / 60)) * 30) * (Math.PI) / 180;       // 시침 각도
        double rMinute = ((minute + (second / 60)) * 6) * (Math.PI) / 180;      // 분침 각도
        double rSecond = (second * 6) * (Math.PI) / 180;                        // 초침 각도

        g.setColor(Color.BLACK);
        g.drawLine(150, 150, 150 + (int) (50 * Math.cos(rHours - (Math.PI / 2))), 150 + (int) (50 * Math.sin(rHours - (Math.PI / 2))));         //시침 검정색
        g.drawLine(150, 150, 150 + (int) (70 * Math.cos(rMinute - (Math.PI / 2))), 150 + (int) (70 * Math.sin((rMinute - (Math.PI / 2)))));     // 분침 검정색
        g.setColor(Color.RED);
        g.drawLine(150, 150, 150 + (int) (100 * Math.cos(rSecond - (Math.PI / 2))), 150 + (int) (100 * Math.sin(rSecond - (Math.PI / 2))));     // 초침은 빨간색

    }

    public static void main(String[] args)
    {
        // Swing / AWT GUIs should be created & changed on the EDT ..
        Runnable r = () -> {
            JFrame frame = new JFrame("Analog Clock");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setPreferredSize(new Dimension(330, 330));
            UI_Assigment_AnalogClock analogClock = new UI_Assigment_AnalogClock();
            analogClock.setPreferredSize(new Dimension(320, 320));
            frame.setLayout(new BorderLayout());
            frame.getContentPane().add(analogClock, BorderLayout.CENTER);
            frame.pack();
            frame.setVisible(true);
        };
        // .. this is how we ensure that Runnable is on the EDT.
        SwingUtilities.invokeLater(r);
    }
}