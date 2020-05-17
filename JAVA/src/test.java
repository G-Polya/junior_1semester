
//2015112232백근주

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class test {

	static String[] array;// 문자열 저장 배열

	public static void makeDNA(int k, int n) {
		// 파일 생성후 50만개 문자열 넣기

		try {
			File file = new File("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\refDNA.txt");
			FileWriter fw = new FileWriter(file);

			for (int i = 0; i < k * n; i++) {
				fw.write(nucleic());
			}

			fw.close();
		} catch (Exception e) {
			System.out.println("makeDNA: " + e);
		}

	}

	public static char nucleic() {
		// 랜덤 염기 생성
		int num = (int) (Math.random() * 4);
		switch (num) {
		case 0: // A
			return 'A';
		case 1: // T
			return 'T';
		case 2: // G
			return 'G';
		case 3: // C
			return 'C';
		}

		return 0;
	}

	public static void makeRNA(char[] array) {
		// RNA 만들때 20% 확률로 2개가 다른걸로 바뀌어진다.
		int miss_index1 = (int) (Math.random() * 10);
		int miss_index2 = (int) (Math.random() * 10);

		while (miss_index1 == miss_index2) { // 둘이 다른 인덱스 나올 때까지
			miss_index2 = (int) (Math.random() * 10);
		}

		char c = nucleic();

		while (array[miss_index1] == c) { // 인덱스 값 바꾸기
			c = nucleic();
		}
		array[miss_index1] = c;

		c = nucleic();
		while (array[miss_index2] == c) {
			c = nucleic();
		}
		array[miss_index2] = c;
	}

	public static void shortread(int k, int n) {
		// 문자열 자르고 배열에 넣기
		// k:shortread의 문자개수
		// n:문자열 갯수

		array = new String[n]; // 염기서열 저장 String배열

		char[] array_char = new char[k];// 파일에서 하나씩 입력받고 string배열에 넣는다.

		boolean[] isfull = new boolean[n];

		int array_index;

		for (int a = 0; a < n; a++) {
			isfull[a] = false;
		}

		try {
			File file = new File("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\refDNA.txt");
			FileReader fr = new FileReader(file);

			int singlech = 0;
			int j = 0;

			while ((singlech = fr.read()) != -1) { // k문자씩 읽고 20%확률로 snp발생

				array_char[j] = (char) singlech;
				j++;

				if (j == k) {// 배열넣기
					int num = (int) (Math.random() * 5);
					if (num == 0) { // 20% 확률
						makeRNA(array_char); // 다른 염기서열 생성
					}

					array_index = (int) (Math.random() * n); // 어디 배열에 넣을지 결정

					while (isfull[array_index] == true) { // 만일 채워진 인덱스라면 다시 랜덤값을 뽑는다
						array_index = (int) (Math.random() * n);
					}

					array[array_index] = String.valueOf(array_char);
			arr		isfull[array_index] = true;// 이 인덱스 string은 채워짐

					j = 0;
				}
			}

			fr.close();
		} catch (Exception e) {
			System.out.println("shortread" + e);
		}
	}

	public static void matchDNA(int k, int n) {
		// R_DNA와 매칭시켜서 나의 염기서열 구하기
		char[] array_char = new char[k];

		boolean[] isuse = new boolean[n];// 사용했는지 여부

		for (int a = 0; a < n; a++) {
			isuse[a] = false;
		}

		try {
			File file1 = new File("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\refDNA.txt");
			File file2 = new File("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\myDNA.txt");
			FileReader fr = new FileReader(file1);
			FileWriter fw = new FileWriter(file2);
			int singlech = 0;
			int j = 0;
			
			long start = System.currentTimeMillis();
			while ((singlech = fr.read()) != -1) {// k개의 문자씩 끊으면서 DNA위치를 찾아 넣는다.

				array_char[j] = (char) singlech;
				j++;
				if (j == k) {
					fw.write(submatchDNA(array_char, isuse));
					j = 0;
				}
			}
			long end = System.currentTimeMillis();
			System.out.println("걸리는 시간:"+(end-start)+"ms");

			fr.close();
			fw.close();
		} catch (FileNotFoundException e) {
			System.out.println("matchDNA: " + e);
		} catch (IOException e) {
			System.out.println("matchDNA: " + e);
		}

	}

	public static String submatchDNA(char[] c, boolean[] isuse) {
		// 매칭 연산
		int n = array.length;// 문자열 개수
		int mismatch = 0;
		char[] myDNA;

		try {

			for (int i = 0; i < n; i++) { // bruteforce 비교
				mismatch = 0;
				myDNA = array[i].toCharArray();

				for (int j = 0; j < c.length; j++) { // mismatch 개수 측정
					if (myDNA[j] != c[j]) {
						mismatch++;
					}
				}
				if ((mismatch <= 2) && (isuse[i] == false)) {// mismatch 조건을만족하고 사용되지않았다면
					isuse[i] = true;
					return array[i];
				}
			}

		} catch (Exception e) {
			System.out.println("submatchDNA" + e);
		}
		return null;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k, n;
		System.out.print("shortRead 길이(k): "); // k,n동적 입력
		k = sc.nextInt();
		System.out.print("");
		System.out.print("shortRead 개수(n): ");
		n = sc.nextInt();
		System.out.print("");

		makeDNA(k, n);
		shortread(k, n);
		matchDNA(k, n);

	}

}
