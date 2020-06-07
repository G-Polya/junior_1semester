package Assignment;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.sound.sampled.*;



public class Chapter14_Assignment_2 extends JFrame
{
    private int playing = 0;
    private int count = 0;
    private boolean stop_flag = false;

    private Clip[] clip = new Clip[4]; // 재생을 위한 클립객체

    JCheckBox[] waves = new JCheckBox[4];
    String[] audio_name = {"audio/wolf.wav", "audio/dhol_drums.wav", "audio/sirenpolice.wav","audio/hiphop.wav"};
    public Chapter14_Assignment_2()
    {
        super("Audio Playing...");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container container = getContentPane();
        container.setLayout(null);

        JLabel message = new JLabel("체크된 곡만 순서대로 한번씩 연주합니다");
        message.setSize(400,20);
        message.setFont(new Font("굴림",Font.BOLD,15));
        message.setHorizontalAlignment(JLabel.CENTER);
        message.setVerticalAlignment(JLabel.TOP);

        container.add(message);

        for(int i =0; i<waves.length;i++)
        {
            waves[i] = new JCheckBox(audio_name[i]);
            waves[i].setSize(400,20);
            waves[i].setLocation(120,50 + (i * 20));
            container.add(waves[i]);

        }

        MyActionListener actionListener = new MyActionListener();

        JButton btn[] = {new JButton("music start"), new JButton("music end")};
        for(int i = 0; i < btn.length ;i++)
        {
            btn[i].setSize(100,30);
            btn[i].setLocation(80+(i*140),210);
            container.add(btn[i]);
            btn[i].addActionListener(actionListener);
        }


        setSize(500,400);
        setVisible(true);

    }

    String selected_audio[] = new String[4];

    public void manage_audio()
    {
        count = 0;
        stop_flag = false;

        for(int i =0;i<waves.length;i++)
        {
            if(waves[i].isSelected())
            {
                selected_audio[count++] = waves[i].getText();
            }
        }
        load_audio(0);
    }

    public void load_audio(int index)
    {
        if(index == count)
        {
            count = 0;
            for(int i = 0; i< selected_audio.length;i++)
            {
                selected_audio[i] = "";
                clip[i].close();
            }
        }
        else
        {
            try
            {
                File audioFile = new File(selected_audio[index]);

                final AudioInputStream audioStream = AudioSystem.getAudioInputStream(audioFile);

                clip[index] = AudioSystem.getClip();

                playing = index;

                clip[index].addLineListener(new LineListener()
                {
                    @Override
                    public void update(LineEvent event)
                    {
                        if(event.getType() == LineEvent.Type.STOP)
                        {
                            if(!stop_flag)
                            {
                                try
                                {
                                    audioStream.close();
                                    load_audio(index+1);
                                }
                                catch (IOException err)
                                {
                                    err.printStackTrace();
                                }
                            }
                        }
                    }
                });

                clip[index].open(audioStream);
                clip[index].start();

            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }
    }


    class MyActionListener implements ActionListener
    {
        @Override
        public void actionPerformed(ActionEvent e)
        {
            switch (e.getActionCommand())
            {
                case "music start":
                    manage_audio();
                    break;

                case "music end":
                    clip[playing].stop();
                    stop_flag = true;
                    break;
            }
        }
    }

    public static void main(String[] args)
    {
        new Chapter14_Assignment_2();
    }
}
