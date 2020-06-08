package Assignment;


import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
 class TicTacToeCore
 {

    private int currentPlayerNum;
    private boolean isGameOver = false;
    private int[][] endStage;
    private int currentTurn = 1;

    public TicTacToeCore(int currentPlayerNum)
    {
        this.currentPlayerNum = currentPlayerNum;
    }

    public void changeTurn()
    {
        currentPlayerNum = (currentPlayerNum == 1) ? 2 : 1;
    }

    public int getCurrentPlayerNum()
    {
        return currentPlayerNum;
    }

    public void setCurrentPlayerNum(int currentPlayerNum)
    {
        this.currentPlayerNum = currentPlayerNum;
    }

    public int[][] getEndStage()
    {
        return endStage;
    }

    /**
     *
     * @param currentStage
     * @return -99: 게임종료됨, 1: 플레이어 1 승리, 2: 플레이어 2 승리, 0: 진행중, 99: 비김(draw)
     */
    public int inputCurrentStage(int[][] currentStage)
    {
        // 게임이 끝났다면 더 이상 진행하는 의미가 없으므로 판단 중단
        if(isGameOver) {
            return -99;
        }


        for(int i = 0; i < currentStage.length; i++)
        {
            String rowStr = "";
            String colStr = "";
            String diagStr1 = "";
            String diagStr2 = "";
            for(int j = 0; j < currentStage[i].length; j++)
            {
                rowStr += (currentStage[i][j] + "");
                colStr += (currentStage[j][i] + "");
            }
            for(int j = 0; j < currentStage.length; j++)
            {
                diagStr1 += currentStage[j][j];
                diagStr2 += currentStage[j][2 - j];
            }

            // 가로 판단

            if(isThisPlayerWin(2, rowStr, colStr, diagStr1, diagStr2))
            {
                isGameOver = true;
                endStage = currentStage;
                return 2;
            } else if(isThisPlayerWin(1, rowStr, colStr, diagStr1, diagStr2))
            {
                isGameOver = true;
                endStage = currentStage;
                return 1;
            } else if(currentTurn == 9)
            {
                return 99;
            }
            else
            {
                continue;
            }
        }
        currentTurn++;
        return 0;
    }

    private boolean isThisPlayerWin(int playerNum, String rowFrag, String colFrag, String diagFrag1, String diagFrag2)
    {
        String p = String.valueOf(playerNum);
        boolean result = false;
        String[] arr = {rowFrag, colFrag, diagFrag1, diagFrag2};
        for(int i = 0; i < arr.length; i++) {
            result = !arr[i].contains("0") && arr[i].equals(p + p + p);
            if (result)	return result;
        }
        return result;
    }

    public void resetGame(int currentPlayerNum)
    {
        this.isGameOver = false;
        this.currentPlayerNum = currentPlayerNum;
        this.endStage = null;
        this.currentTurn = 1;
    }

}

public class UI_Assignment1 extends JFrame
{

    private static final long serialVersionUID = 1L;

    JLabel title = new JLabel("TicTacToe | ");
    JLabel dispCurrentPlayer = new JLabel("Player 0");
    private int score1 = 0;
    private int score2 = 0;
    JLabel scoreLabel = new JLabel(" | " + score1 + " : " + score2);
    JButton startNewGame = new JButton("새 게임 시작");

    JPanel titleBar = new JPanel();
    JPanel nineRoom = new JPanel();

    private final int START_PLAYER = 1;
    private boolean isGameEnd = false;
    TicTacToeCore ttt = new TicTacToeCore(START_PLAYER);

    public UI_Assignment1()
    {
        super("TicTacToe");
        this.setSize(400,300);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        this.drawWindow();
        this.setVisible(true);

    }

    boolean player_flag = ttt.getCurrentPlayerNum() == 1 ? true : false;

    public void drawWindow()
    {
        titleBar.add(title);
        titleBar.add(dispCurrentPlayer);
        titleBar.add(scoreLabel);
        titleBar.add(startNewGame);

        dispCurrentPlayer.setText("Player " + START_PLAYER);
        add(titleBar, BorderLayout.NORTH);

        nineRoom.setLayout(new GridLayout(3,3));
        for(int i = 0; i < 9; i++)
        {
            JButton tempButton = new JButton("");
            tempButton.setFont(new Font("Impact", Font.PLAIN, 22));
            nineRoom.add(tempButton);
        }

        add(nineRoom, BorderLayout.CENTER);

        MouseListener ml = new MouseAdapter()
        {
            @Override
            public void mousePressed(MouseEvent e)
            {
                JButton tempButton = (JButton)e.getComponent();
                // System.out.println(ttt.getCurrentPlayerNum());
                if(isGameEnd)
                {
                    return;
                }
                if(tempButton.getText().equals("O") || tempButton.getText().equals("X"))
                {
                    JOptionPane.showMessageDialog(nineRoom, "이미 둔 곳입니다.");
                    return;
                }
                else if(ttt.getCurrentPlayerNum() == 1)
                {
                    tempButton.setText("O");
                    tempButton.add(new MyPanel());

                    dispCurrentPlayer.setText("Player " + 2);
                } else
                    {
                    tempButton.setText("X");
                    dispCurrentPlayer.setText("Player " + 1);
                }
                ttt.changeTurn();
                System.out.print("(" + e.getX() + ", " + e.getY() + ") ");

                int[][] ticArr = new int[3][3];
                for(int i = 0; i < ticArr.length; i++)
                {
                    for(int j = 0; j < ticArr[0].length; j++)
                    {
                        String pl = ((JButton)nineRoom.getComponent(j + i * 3)).getText();
                        if(pl.equals("O"))	ticArr[i][j] = 1;
                        else if(pl.equals("X"))	ticArr[i][j] = 2;
                        else	ticArr[i][j] = 0;
                    }
                }
                int result = ttt.inputCurrentStage(ticArr);
                System.out.println("result: " + result);
                if(result == 1 || result == 2)
                {
                    JOptionPane.showMessageDialog(nineRoom, "플레이어 " + result + "의 승리입니다.");
                    if(result == 1)
                    {
                        score1++;
                    }
                    else
                    {
                        score2++;
                    }
                    scoreLabel.setText(" | " + score1 + " : " + score2);
                    isGameEnd = true;
                }
                else if (result == 99)
                {
                    JOptionPane.showMessageDialog(nineRoom, "비겼습니다.");
                    isGameEnd = true;
                }

            }
        };

        for(Component c : nineRoom.getComponents())
        {
            c.addMouseListener(ml);
        }

        startNewGame.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                ttt.resetGame(START_PLAYER);
                isGameEnd = false;
                for(int i = 0; i < nineRoom.getComponents().length; i++)
                {
                    ((JButton)nineRoom.getComponent(i)).setText("");
                }

            }
        });

    }

    class MyPanel extends JPanel
    {
        public void paintComponent(Graphics g,JButton tempButton)
        {
            super.paintComponents(g);
            g.setColor(Color.BLACK);
            if(player_flag)
                g.fillOval(tempButton.getX(),tempButton.getY(),tempButton.getWidth(),tempButton.getHeight());
            else
            {
                g.drawLine(tempButton.getWidth(), tempButton.getHeight(), 0,0 );
                g.drawLine(0,0,tempButton.getWidth(), tempButton.getHeight());
            }

        }
    }


    public static void main(String[] args)
    {

        // 그래픽 전용 thread 사용하기
        SwingUtilities.invokeLater(new Thread()
        {
            public void run()
            {
                new UI_Assignment1();
            }
        });
    }

}