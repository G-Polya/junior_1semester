import java.util.Scanner;

public class java0324
{
    public static void main(String[] args) throws java.util.InputMismatchException {
        int t = 5, y = 67;
        boolean res = (t++ > 6) && (y++ > 66);      // &&문에서(뒤에 것이 항상 참이지만) 앞이 거짓이라 연산종료하고 false반환.뒤의 연산을 수행하지 않는다
        System.out.println(res);
        System.out.println(t + " " + y);

        System.out.println();
        t = 5;
        y = 67;
        boolean out = (t++ > 4) || (++y > 66);      // 앞에것이 참이면 or문은 항상 참이라 연산종료하고 true리턴, 뒤의 연산을 수정하지 않는다
        System.out.println(out);
        System.out.println(t + " " + y);

        int aa = 8;
        int bb = -aa;
        bb = ~aa + 1;   // -8이 bb에 대입된다
        System.out.println();


        byte qqq = 20;

        byte www = -8;
        System.out.println((byte) (qqq >>> 2));

        // www는 byte(8bit)지만 >>>연산이 수행되면 int(32bit)로 확장된다
        // 그리고 마지막에 다시 byte로 바뀐다
        System.out.println((byte) (www >>> 2));

        // 0000 0000 0000 0000 0000 0000 0000 1000 : 8
        // 1111 1111 1111 1111 1111 1111 1111 0111 + 1 =
        // 1111 1111 1111 1111 1111 1111 1111 1000 : -8(2의 보수)
        // -8 >>> 2
        // 0011 1111 1111 1111 1111 1111 1111 1111 1110 ==> 1111 1110 : -2
    }
}
