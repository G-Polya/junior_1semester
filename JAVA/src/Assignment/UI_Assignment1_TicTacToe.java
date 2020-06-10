package Assignment;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class UI_Assignment1_TicTacToe extends JFrame
{
    JButton buttons[] = new JButton[9];
    int player = 1;     //홀수면 (player 1에겐 ) O, 짝수면 (player 2에겐 ) X

    JPanel nineRoom = new JPanel(); // 버튼이 생성될 패널

    public UI_Assignment1_TicTacToe()
    {
        super("TIc Tac Toe");
        setSize(400,300);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        drawWindow();
        setVisible(true);
    }

    public void drawWindow()
    {
        nineRoom.setLayout(new GridLayout(3,3));

        for(int i = 0; i <= 8; i++)
        {
            buttons[i] = new JButton();
            buttons[i].setText("");
            buttons[i].addActionListener(new ButtonClicked());

            nineRoom.add(buttons[i]); // 버튼들을 패널에 추가
        }

        add(nineRoom, BorderLayout.CENTER);

    }


    public void resetButtons()
    {
        for(int i = 0; i <= 8; i++)
        {
            buttons[i].setText("");
        }
    }


    // 버튼이 클릭되면, 그 클릭은 ActionEvent를 발생. 이 이벤트는 ActionListener에 의해 처리된다
    private class ButtonClicked implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {

            JButton buttonClicked = (JButton)e.getSource(); // 클릭된 버튼 가져오기

            if(player %2 == 0)  // player 2의 차례
            {
                buttonClicked.setText("X");     // X 텍스트로 flag를 준다

                // 그림그리기
                JPanel myPanel = new JPanel()
                {
                    public void paintComponent(Graphics g)
                    {
                        super.paintComponent(g);
                        g.setColor(Color.BLACK);
                        g.drawLine(0,0,120,100);
                        g.drawLine(0,80,90,0);

                    }
                };
                buttonClicked.add(myPanel);
                buttonClicked.setEnabled(false);    // 다시 못누르게 비활성화

            }
            else    // player 1의 경우
            {
                buttonClicked.setText("O"); // O 텍스트로 flag를 준다

                JPanel myPanel = new JPanel()
                {
                    public void paintComponent(Graphics g)
                    {
                        super.paintComponent(g);
                        g.setColor(Color.BLACK);
                        //g.drawLine(0,0,120,100);
                        g.drawOval(10,0,75,75);
                    }
                };
                buttonClicked.add(myPanel);
                buttonClicked.setEnabled(false); // 다시 못누르게 비활성화

            }


            if(player %2 == 0)
            {
                if(checkForWin() == true)
                {
                    JOptionPane.showConfirmDialog(null, "Game Over. Player 1 wins");
                    resetButtons();
                }
            }
            else
            {
                if(checkForWin() == true)
                {
                    JOptionPane.showConfirmDialog(null, "Game Over. Player 2 wins");
                    resetButtons();
                }
            }


            player++;

        }


        public boolean checkForWin()        // 누가 승리했는지 체크
        {

            //수평 체크
            if( checkAdjacent(0,1) && checkAdjacent(1,2) )
                return true;
            else if( checkAdjacent(3,4) && checkAdjacent(4,5) )
                return true;
            else if ( checkAdjacent(6,7) && checkAdjacent(7,8))
                return true;

                //수직체크
            else if ( checkAdjacent(0,3) && checkAdjacent(3,6))
                return true;
            else if ( checkAdjacent(1,4) && checkAdjacent(4,7))
                return true;
            else if ( checkAdjacent(2,5) && checkAdjacent(5,8))
                return true;

                //대각선체크
            else if ( checkAdjacent(0,4) && checkAdjacent(4,8))
                return true;
            else if ( checkAdjacent(2,4) && checkAdjacent(4,6))
                return true;
            else
                return false;


        }

        // 인접한 버튼이 같은 표식인지 확인
        public boolean checkAdjacent(int a, int b)
        {
            if ( buttons[a].getText().equals(buttons[b].getText()) && !buttons[a].getText().equals("") )
                return true;
            else
                return false;
        }

    }

    public static void main(String[] args)
    {
        new UI_Assignment1_TicTacToe();
    }
}