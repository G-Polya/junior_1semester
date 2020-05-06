package Assignment;

import java.util.HashMap;
import java.util.Scanner;
public class Assignment_20200505
{
    public static void main(String[] args)
    {
        HashMap<String, Integer> nations = new HashMap<String, Integer>();
        Scanner scanner = new Scanner(System.in);

        System.out.println("나라이름과 인구를 입력하세요.(예: Korea, 5000)");
        while(true)
        {
            System.out.println("나라 이름, 인구 >> ");
            String nation = scanner.next();
            if(nation.equals("stop"))
                break;
            int population = scanner.nextInt();
            nations.put(nation, population);
        }

        while(true)
        {
            System.out.println("인구 검색 >> ");
            String nation = scanner.next();

            Integer n = nations.get(nation);
            if (n == null)
                System.out.println("나라가 없습니다.");
            else
                System.out.println(nation+"의 인구는 "+n+"명 입니다");

        }
    }
}
