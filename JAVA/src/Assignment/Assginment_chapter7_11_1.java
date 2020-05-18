package Assignment;

import java.util.*;

class Nation
{
	private String country;
	private String capital;

	//�⺻ ������
	Nation()
	{}
	
	// ������
	Nation(String country, String capital)
	{
		this.country = country;
		this.capital = capital;
	}
	
	public String getCountry()
	{
		return country;
	}
	public String getCapital()
	{
		return capital;
	}
	
	

}



public class Assginment_chapter7_11_1 
{
	
	
	public static void main(String[] args)
	{
		Vector<Nation> nations= new Vector<Nation>();
		nations.add(new Nation("�߽���","�߽��ڽ�Ƽ"));
		nations.add(new Nation("������","������"));
		nations.add(new Nation("������","�ĸ�"));
		nations.add(new Nation("����","����"));
		nations.add(new Nation("�׸���","���׳�"));
		nations.add(new Nation("����","������"));
		nations.add(new Nation("�Ϻ�","����"));
		nations.add(new Nation("�߱�","����¡"));
		nations.add(new Nation("���þ�","��ũ��"));
		
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
        				
        				
        				for(int i = 0; i<nations.size();i++)
        					if(nation.equals(nations.elementAt(i).getCountry()))
        					{
        						System.out.println(nation+"�� �̹� �ֽ��ϴ�!");
        						current_size--;
        						nations.remove(i);
        					}
        				
        				nations.add(new Nation(nation,capital));
        				
        				
        			}
        			break;
				case 2:
					List keys = new ArrayList();	// key�θ� �̷���� List(�����θ� �̷���� List)
					for(int i = 0; i<nations.size();i++)
						keys.add(nations.elementAt(i).getCountry());
					while(true)
					{
						Collections.shuffle(keys);// �����ϰ� ������ ���ؼ� ������
						Object key = keys.get(0);
            			System.out.print(key+"�� ������? ");
            			String answer = scanner.next();
            			
            			if(answer.equals("�׸�"))
            				break;
            			
            			for(int i = 0; i<nations.size();i++)	// nations�� ��� ���ҿ� ���Ͽ�
            			{
            				String temp_country = nations.elementAt(i).getCountry();	
            				if(temp_country.equals(key))		// �ش� �ε����� country�� key�� ����.
            				{
            					if(answer.equals(nations.elementAt(i).getCapital())) // �� key�� capital��  ������ �Է��� ���̴�.
        						{
            						System.out.println("����!");
            						continue;
        						}
            					else
            					{
            						System.out.println("�ƴմϴ�!");
            						continue;
            					}
            				}
            			}				       				
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
			catch(IndexOutOfBoundsException e)
			{
				System.out.println("����ִ� ���� �����ϴ�. �޴��� ���ư��ϴ�");
			}
		}
	}
	
}
