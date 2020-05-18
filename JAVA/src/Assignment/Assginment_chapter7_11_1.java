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
		nations.add(new Nation("멕시코","멕시코시티"));
		nations.add(new Nation("스페인","리스본"));
		nations.add(new Nation("프랑스","파리"));
		nations.add(new Nation("영국","런던"));
		nations.add(new Nation("그리스","아테네"));
		nations.add(new Nation("독일","베를린"));
		nations.add(new Nation("일본","동경"));
		nations.add(new Nation("중국","베이징"));
		nations.add(new Nation("러시아","모스크바"));
		
		Scanner scanner = new Scanner(System.in);
		boolean flag = true;
		while(flag)
		{
			try
			{
				System.out.print("입력:1, 퀴즈:2, 종료:3 >> ");
				int menu = scanner.nextInt();
				switch(menu)
				{
				case 1:
					int current_size = nations.size(); // 현재 HashMap에 들어있는 나라 개수
        			System.out.println("현재 "+current_size+"개 나라와 수도가 입력되어 있습니다.");
        			while(true)
        			{
        				current_size++;
        				System.out.print("나라와 수도 입력"+current_size+">> ");	// 나라와 수도 입력
        				String nation = scanner.next();
        				if(nation.equals("그만"))
        					break;
        				String capital = scanner.next();
        				
        				
        				for(int i = 0; i<nations.size();i++)
        					if(nation.equals(nations.elementAt(i).getCountry()))
        					{
        						System.out.println(nation+"는 이미 있습니다!");
        						current_size--;
        						nations.remove(i);
        					}
        				
        				nations.add(new Nation(nation,capital));
        				
        				
        			}
        			break;
				case 2:
					List keys = new ArrayList();		// key로만 이루어진 List(나라들로만 이루어짐 List)
					for(int i = 0; i<nations.size();i++)
						keys.add(nations.elementAt(i).getCountry());
					while(true)
					{
						Collections.shuffle(keys);// 랜덤하게 나오기 위해서 섞어줌
						Object key = keys.get(0);
            			System.out.print(key+"의 수도는? ");
            			String answer = scanner.next();
            			
            			if(answer.equals("그만"))
            				break;
            			
            			for(int i = 0; i<nations.size();i++)
            			{
            				String temp_country = nations.elementAt(i).getCountry();	
            				if(temp_country.equals(key))
            				{
            					if(answer.equals(nations.elementAt(i).getCapital()))
        						{
            						System.out.println("정답!");
            						continue;
        						}
            					else
            					{
            						System.out.println("아닙니다");
            						continue;
            					}
            				}
            			}				       				
					}
					break;
				case 3:
					System.out.println("종료합니다");
					flag = false;
					break;
				default:
					System.out.println("잘못 입력하셨습니다. 메뉴로 돌아갑니다");
						
				}
			}
			catch(IndexOutOfBoundsException e)
			{
				System.out.println("들어있는 나라가 없습니다. 메뉴로 돌아갑니다");
			}
		}
	}
	
}
