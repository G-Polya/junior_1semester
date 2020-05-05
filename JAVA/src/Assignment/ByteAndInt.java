package Assignment;

public class ByteAndInt 
{
	private static final int byteSize = 8;
	
	
	public static String BitString(int value)// byte형을 인수로 받는데 왜 이 함수가 호출됄까?
	{
		final int intSize = 32;			

	
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
	
	
	public static String BitString(byte value)
	{
		final int byteSize = 8;
		
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
					strBuf.append(" / ");
				else
					strBuf.append(" ");
		}
		
		return strBuf.toString();
	}
	
	public static byte[] intToByteArray(int data)
	{
		byte[] byteArray = new byte[4];
		byteArray[0] = (byte)(data>>24);
		byteArray[1] = (byte)(data>>16);
		byteArray[2] = (byte)(data>>8);
		byteArray[3] = (byte)(data);
					 
		return byteArray;	
	}
	
	public static int byteArrayToInt(byte bytes[]) 
	{
		return ((((int)bytes[0] & 0xff) << 24) |
				(((int)bytes[1] & 0xff) << 16) |
				(((int)bytes[2] & 0xff) << 8) |
				(((int)bytes[3] & 0xff)));
	} 



	 public static void main(String[] args) 
	 {
		System.out.println("Byte Array to Int");
		byte[] bytes = new byte[]{11,100,5,125};
		System.out.println("Input:");
		for(int i = 0; i < bytes.length;i++)
			System.out.println(bytes[i]+" is "+BitString(bytes[i]));
		int result = byteArrayToInt(bytes);
		System.out.println("Result: "+ result);
		System.out.println(BitString(result));
	
		System.out.println("=======================");
	
		System.out.println("Int to Byte Array");
		int num = result;
		byte[] result_array = intToByteArray(num);
		System.out.println("Input: "+ num+" is "+ BitString(num));
		System.out.println("Result:");
		for(int i = 0; i < result_array.length;i++)
			System.out.println(BitString(result_array[i])+"is "+result_array[i]);
		
		
	 }
}
