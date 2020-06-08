import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class test extends JFrame
{
	JButton buttons[] = new JButton[9];
	int alternate = 1;//if this number is a even, then put a X. If it's odd, then put an O

	JPanel nineRoom = new JPanel();

	public test()
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
			buttons[i].addActionListener(new buttonListener());

			nineRoom.add(buttons[i]); //adds this button to JPanel (note: no need for JPanel.add(...)
			//because this whole class is a JPanel already
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


	// when a button is clicked, it generates an ActionEvent. Thus, each button needs an ActionListener. When it is clicked, it goes to this listener class that I have created and goes to the actionPerformed method. There (and in this class), we decide what we want to do.
	private class buttonListener implements ActionListener
	{


		public void actionPerformed(ActionEvent e)
		{

			JButton buttonClicked = (JButton)e.getSource(); //get the particular button that was clicked



			if(alternate%2 == 0)
			{
				buttonClicked.setText("X");

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
				buttonClicked.setEnabled(false);

			}
			else
			{
				buttonClicked.setText("O");

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
				buttonClicked.setEnabled(false);

			}



			if(checkForWin() == true)
			{
				JOptionPane.showConfirmDialog(null, "Game Over.");
				resetButtons();
			}

			alternate++;

		}


		public boolean checkForWin()
		{
			/**   Reference: the button array is arranged like this as the board
			 *      0 | 1 | 2
			 *      3 | 4 | 5
			 *      6 | 7 | 8
			 */
			//horizontal win check
			if( checkAdjacent(0,1) && checkAdjacent(1,2) ) //no need to put " == true" because the default check is for true
				return true;
			else if( checkAdjacent(3,4) && checkAdjacent(4,5) )
				return true;
			else if ( checkAdjacent(6,7) && checkAdjacent(7,8))
				return true;

				//vertical win check
			else if ( checkAdjacent(0,3) && checkAdjacent(3,6))
				return true;
			else if ( checkAdjacent(1,4) && checkAdjacent(4,7))
				return true;
			else if ( checkAdjacent(2,5) && checkAdjacent(5,8))
				return true;

				//diagonal win check
			else if ( checkAdjacent(0,4) && checkAdjacent(4,8))
				return true;
			else if ( checkAdjacent(2,4) && checkAdjacent(4,6))
				return true;
			else
				return false;


		}

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
		new test();
//		JFrame window = new JFrame("Tic-Tac-Toe");
//		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//		window.getContentPane().add(new test());
//		window.setBounds(300,200,300,300);
//		window.setVisible(true);
	}
}