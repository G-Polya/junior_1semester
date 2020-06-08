package Assignment;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.sound.sampled.*;

interface Test
{
    public void load_audio(int index);
}


public class Chapter14_Assignment_2 extends JFrame
{
    private int playing = 0;
    private int count = 0;
    private boolean stop_flag = false;

    private Clip[] audioClip = new Clip[4]; // 재생을 위한 클립객체

    String[] audio_name = {"audio/wolf.wav", "audio/dhol_drums.wav", "audio/sirenpolice.wav","audio/hiphop.wav"};   // 오디오파일 이름
    public Chapter14_Assignment_2()
    {

        super("Audio Playing...");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container container = getContentPane();
        container.setLayout(null);


        JLabel explain = new JLabel("체크된 곡만 순서대로 한번씩 연주합니다");   //
        explain.setSize(400,20);
        explain.setFont(new Font("굴림",Font.BOLD,15));
        explain.setHorizontalAlignment(JLabel.CENTER);
        explain.setVerticalAlignment(JLabel.TOP);

        container.add(explain);

        JCheckBox[] checkBoxes = new JCheckBox[4]; // 체크박스 생성과 위치설정. container에 삽입
        for(int i = 0; i< checkBoxes.length; i++)
        {
            checkBoxes[i] = new JCheckBox(audio_name[i]);
            checkBoxes[i].setSize(400,20);
            checkBoxes[i].setLocation(120,50 + (i * 20));
            container.add(checkBoxes[i]);

        }


        // 액션리스너 객체생성. 익명클래스 이용
        ActionListener actionListener = new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                switch (e.getActionCommand())
                {
                    case "music start":     // music
                        count = 0;
                        stop_flag = false;

                        for(int i = 0; i< checkBoxes.length; i++)
                        {
                            if(checkBoxes[i].isSelected())
                            {
                                selected_audio[count++] = checkBoxes[i].getText();
                            }
                        }
                        loadAudio(0);
                        break;

                    case "music end":
                        audioClip[playing].stop();
                        stop_flag = true;
                        break;
                }
            }
        };

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

    public void loadAudio(int index)
    {
        if(index == count)
        {
            count = 0;
            int i = 0;
            while(i<selected_audio.length)
            {
                selected_audio[i] = "";
                audioClip[i].close();
                i++;
            }
        }
        else
        {
            try
            {
                File audios = new File(selected_audio[index]);

                final AudioInputStream soundStream = AudioSystem.getAudioInputStream(audios);

                audioClip[index] = AudioSystem.getClip();

                playing = index;

                audioClip[index].addLineListener(new LineListener()
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
                                    soundStream.close();
                                    loadAudio(index+1);
                                }
                                catch (IOException err)
                                {
                                    err.printStackTrace();
                                }
                            }
                        }
                    }
                });

                audioClip[index].open(soundStream);
                audioClip[index].start();

            }
            catch(Exception e)
            {
                e.printStackTrace();
            }
        }

    }




    public static void main(String[] args)
    {
        new Chapter14_Assignment_2();
    }
}
