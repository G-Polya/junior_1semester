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
	    	System.out.println("**** 수도 맞추기 게임을 시작합니다. ****");
	    	HashMap<String, String> nations = new HashMap<String, String>();

	    	nations.put("멕시코","멕시코시티");
	    	nations.put("스페인","리스본");
	    	nations.put("프랑스","파리");
	    	nations.put("영국","런던");
	    	nations.put("그리스","아테네");
	    	nations.put("독일","베를린");
	    	nations.put("일본","동경");
	    	nations.put("중국","베이징");
	    	nations.put("러시아","모스크바");
	    	
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
	        				
	        				for(String key : nations.keySet())
	        					if(nation.equals(key))		// 입력한 나라가 이미 있다
	        					{
	        						System.out.println(nation+"는 이미 있습니다!");
	        			    		current_size--;
	        					}
	        				
	        				nations.put(nation, capital);
	        			}
	        			break;
	        		case 2:
	        			List keys = new ArrayList(nations.keySet());		// key로만 이루어진 List(나라들로만 이루어짐 List)
	        			while(true)
	        			{
	        				Collections.shuffle(keys);		// 랜덤하게 나오기 위해서 섞어줌
	        				Object key = keys.get(0);
	            			System.out.print(key+"의 수도는? ");
	            			String answer = scanner.next();
	            			if(answer.equals("그만"))
	            				break;
	            			if(answer.equals(nations.get(key)))
	            				System.out.println("정답!");
	            			else
	            				System.out.println("아닙니다");		
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
	    		catch(IndexOutOfBoundsException e)	// 만약 HashMap에 원소가 없다면 예외처리한다.
	    		{
	    			System.out.println("들어있는 나라가 없습니다. 메뉴로 돌아갑니다");
	    		}
	    	}
	    	
	    }
}
