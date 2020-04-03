
public class BitStringOut 
{
	private static final int intSize = 32;
	private static final int byteSize = 8;
	
	public static String BitString(int value)
	{
		StringBuffer strBuf = new StringBuffer(intSize+12);
		for(int i = 0; i< intSize;i++)
		{
			int m = value >> (intSize - i - 1);
			if( (m & 1) == 1)
				//System.out.print("1");
				strBuf.append("1");
			else
				//System.out.print("0");
				strBuf.append("0");
			
			if((i+1) % 4== 0)
				if((i+1) %8 ==0 && (i+1)!=intSize)
					//System.out.print(" / ");
					strBuf.append(" / ");
				else
					//System.out.print(" ");
					strBuf.append(" ");
		}
		
		return strBuf.toString();
	}
	
	public static String BitString(Byte value)
	{
		StringBuffer strBuf = new StringBuffer(byteSize+12);
		for(int i = 0; i< byteSize;i++)
		{
			int m = value >> (byteSize - i - 1);
			if( (m & 1) == 1)
				//System.out.print("1");
				strBuf.append("1");
			else
				//System.out.print("0");
				strBuf.append("0");
			
			if((i+1) % 4== 0)
				if((i+1) %8 ==0 && (i+1)!=byteSize)
					//System.out.print(" / ");
					strBuf.append(" / ");
				else
					//System.out.print(" ");
					strBuf.append(" ");
		}
		
		return strBuf.toString();
	}
	
	public static void main(String[] args)
	{
		int aaa = 999;
		System.out.println("비트 문자열을 출력해보자.\n"+Integer.toBinaryString(aaa));
		
		System.out.println(BitString(aaa));
		System.out.println(BitString((byte)44));
	}

}
