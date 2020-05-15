package Assignment;

import java.util.StringTokenizer;
import java.util.Scanner;

public class ����6��ǽ� 
{
	
	public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);			// Scanner ��ü ����
        String input_str = "";		// input_str �ʱ�ȭ

        System.out.println("Input($�� �Է� ����) >> ");
        while(true)
        {
            String input = sc.nextLine();	// ���ڿ� ���پ� �Է�
            if(input.contentEquals("$"))	// while�� ���Ḧ ���� flag $	
                break;
            else
                input_str = input_str.concat(input+"\n");	//�ϼ��� ���ڿ�
            
        }
        
        StringTokenizer st = new StringTokenizer(input_str, " ={};\t\r\n,");	// input_str�� StringTokenizer�� ��ūȭ
        int index = 0, temp = 0;
        
        String[] tokens = new String[st.countTokens()]; // ��ū���� ���� �迭 tokens
        
        System.out.println("Output >> ");
        while(st.hasMoreTokens())
        	tokens[index++] = st.nextToken();		// �迭 �ʱ�ȭ.. ���� tokens���� input_str�� ��ūȭ�� ������ ��
        
        for(int i = 0; i< tokens.length;i++)
        {
        	try
        	{
        		temp = Integer.parseInt(tokens[i]);	// ��ū �߿��� ����("1", "6")�� ��ȯ�� ������ ���ڿ�("Example", "Example2")�� ��ȯ�� �ȵż� NumberFormatException �߻�
        	}
        	catch(NumberFormatException e)			
        	{
        		System.out.println(tokens[i]);		// ���� ���ͷ��� ������ ���鸸 ���
        	}
        }
    }
}
