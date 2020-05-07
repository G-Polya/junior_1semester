package Assignment;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class Assignment_chapter7_11_2 
{
	   public static void main(String[] args)
	    {
	    	System.out.println("**** ���� ���߱� ������ �����մϴ�. ****");
	    	HashMap<String, String> nations = new HashMap<String, String>();

	    	nations.put("�߽���","�߽��ڽ�Ƽ");
	    	nations.put("������","������");
	    	nations.put("������","�ĸ�");
	    	nations.put("����","����");
	    	nations.put("�׸���","���׳�");
	    	nations.put("����","������");
	    	nations.put("�Ϻ�","����");
	    	nations.put("�߱�","����¡");
	    	nations.put("���þ�","��ũ��");
	    	
	    	Scanner scanner = new Scanner(System.in);
	    	boolean flag = true;
	    	while(flag)
	    	{
	    		try
	    		{
	    			System.out.print("�Է�:1, ����:2, ����:3 >> ");
	    	    	
	        		int menu = scanner.nextInt();
	        		switch(menu)
	        		{
	        		case 1:
	        			int current_size = nations.size(); // ���� HashMap�� ����ִ� ���� ����
	        			System.out.println("���� "+current_size+"�� ����� ������ �ԷµǾ� �ֽ��ϴ�.");
	        			while(true)
	        			{
	        				current_size++;	
	        				System.out.print("����� ���� �Է�"+current_size+">> ");	// ����� ���� �Է�
	        				String nation = scanner.next();
	        				if(nation.equals("�׸�"))
	        					break;
	        				String capital = scanner.next();
	        				
	        				for(String key : nations.keySet())
	        					if(nation.equals(key))		// �Է��� ���� �̹� �ִ�
	        					{
	        						System.out.println(nation+"�� �̹� �ֽ��ϴ�!");
	        			    		current_size--;
	        					}
	        				
	        				nations.put(nation, capital);
	        			}
	        			break;
	        		case 2:
	        			List keys = new ArrayList(nations.keySet());		// key�θ� �̷���� List(�����θ� �̷���� List)
	        			while(true)
	        			{
	        				Collections.shuffle(keys);		// �����ϰ� ������ ���ؼ� ������
	        				Object key = keys.get(0);
	            			System.out.print(key+"�� ������? ");
	            			String answer = scanner.next();
	            			if(answer.equals("�׸�"))
	            				break;
	            			if(answer.equals(nations.get(key)))
	            				System.out.println("����!");
	            			else
	            				System.out.println("�ƴմϴ�");		
	        			}
	        			break;
	        		case 3:
	        			System.out.println("�����մϴ�");
	        			flag = false;
	        			break;
	        			
	        		default:
	        			System.out.println("�߸� �Է��ϼ̽��ϴ�. �޴��� ���ư��ϴ�");
	        		}

	    		}
	    		catch(IndexOutOfBoundsException e)	// ���� HashMap�� ���Ұ� ���ٸ� ����ó���Ѵ�.
	    		{
	    			System.out.println("����ִ� ���� �����ϴ�. �޴��� ���ư��ϴ�");
	    		}
	    	}
	    	
	    }
}
