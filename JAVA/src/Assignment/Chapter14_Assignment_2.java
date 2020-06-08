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

    private Clip[] audioClip = new Clip[4]; // 재생을 위한 클립객체

    String[] audio_path = {"audio/wolf.wav", "audio/dhol_drums.wav", "audio/sirenpolice.wav","audio/hiphop.wav"};   // 오디오파일 이름

    String playing_audio[] = new String[4];    // 체크박스에서 선택된 wav파일의 이름들


    public Chapter14_Assignment_2()
    {

        super("Audio Playing...");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container container = getContentPane();
        container.setLayout(null);


        JLabel top_label = new JLabel("체크된 곡만 순서대로 한번씩 연주합니다");   //
        top_label.setSize(400,20);
        top_label.setFont(new Font("굴림",Font.BOLD,15));
        top_label.setHorizontalAlignment(JLabel.CENTER);
        top_label.setVerticalAlignment(JLabel.TOP);

        container.add(top_label);

        JCheckBox[] checkBoxes = new JCheckBox[4]; // 체크박스 생성과 위치설정. container에 삽입
        for(int i = 0; i< checkBoxes.length; i++)
        {
            checkBoxes[i] = new JCheckBox(audio_path[i]);   //체크박스의 레이블은 audio_name이다.
            checkBoxes[i].setSize(400,20);
            checkBoxes[i].setLocation(120,50 + (i * 20));
            container.add(checkBoxes[i]);

        }

        // 액션리스너 객체생성. 익명클래스 이용. 버튼 이벤트처리
        ActionListener actionListener = new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                String command = e.getActionCommand();
                if(command == "music start")        // music start누를때 노래를 시작
                {
                    count = 0;
                    stop_flag = false;

                    for(int i = 0; i< checkBoxes.length; i++)   // 체크박스확인 후, 체크됬으면 selected_audio초기화.
                    {
                        if(checkBoxes[i].isSelected())
                        {
                            playing_audio[count] = checkBoxes[i].getText();
                            count++;    // 체크될때마다 count증가
                        }
                    }
                    loadAudio(0);
                }
                else if(command == "music end") // music end를 누르면 노래정지
                {
                    audioClip[playing].stop();
                    stop_flag = true;
                }
            }
        };

        // 시작, 정지 버튼 생성과 이벤트처리
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

    class MyLineListener implements LineListener
    {
        AudioInputStream soundStream;
        int index;
        MyLineListener(AudioInputStream soundStream, int index)
        {
            this.soundStream = soundStream;
            this.index = index;
        }

        @Override
        public void update(LineEvent event)
        {
            if(event.getType() == LineEvent.Type.STOP)  // clip.stop()이 호출되거나 재생이 끝났을떄
            {
                if(!stop_flag)
                {
                    try
                    {
                        soundStream.close(); // 오디오스트림 종료
                        loadAudio(index+1); // 다음 오디오파일 재생
                    }
                    catch (IOException err)
                    {
                        err.printStackTrace();
                    }
                }
            }
        }
    }

    public void loadAudio(int index)
    {
        if(index == count)  // index와  count가 같다 >> 끝까지 연주했다.
        {
            count = 0;  // 설정초기화
            int i = 0;
            while(i< playing_audio.length)
            {
                playing_audio[i] = "";
                audioClip[i].close();
                i++;
            }
        }
        else
        {
            try
            {
                File audios = new File(playing_audio[index]);   //오디오파일 경로명

                final AudioInputStream soundStream = AudioSystem.getAudioInputStream(audios); // 오디오 파일로부터

                audioClip[index] = AudioSystem.getClip();   // 비어있는 오디오클립만들기

                playing = index;

                audioClip[index].addLineListener(new MyLineListener(soundStream, index)); // LineEvent 처리

                audioClip[index].open(soundStream); //재생할 오디오스트림 열기
                audioClip[index].start();   //재생 시작

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
