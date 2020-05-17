
//2015112232�����

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class test {

	static String[] array;// ���ڿ� ���� �迭

	public static void makeDNA(int k, int n) {
		// ���� ������ 50���� ���ڿ� �ֱ�

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
		// ���� ���� ����
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
		// RNA ���鶧 20% Ȯ���� 2���� �ٸ��ɷ� �ٲ������.
		int miss_index1 = (int) (Math.random() * 10);
		int miss_index2 = (int) (Math.random() * 10);

		while (miss_index1 == miss_index2) { // ���� �ٸ� �ε��� ���� ������
			miss_index2 = (int) (Math.random() * 10);
		}

		char c = nucleic();

		while (array[miss_index1] == c) { // �ε��� �� �ٲٱ�
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
		// ���ڿ� �ڸ��� �迭�� �ֱ�
		// k:shortread�� ���ڰ���
		// n:���ڿ� ����

		array = new String[n]; // ���⼭�� ���� String�迭

		char[] array_char = new char[k];// ���Ͽ��� �ϳ��� �Է¹ް� string�迭�� �ִ´�.

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

			while ((singlech = fr.read()) != -1) { // k���ھ� �а� 20%Ȯ���� snp�߻�

				array_char[j] = (char) singlech;
				j++;

				if (j == k) {// �迭�ֱ�
					int num = (int) (Math.random() * 5);
					if (num == 0) { // 20% Ȯ��
						makeRNA(array_char); // �ٸ� ���⼭�� ����
					}

					array_index = (int) (Math.random() * n); // ��� �迭�� ������ ����

					while (isfull[array_index] == true) { // ���� ä���� �ε������ �ٽ� �������� �̴´�
						array_index = (int) (Math.random() * n);
					}

					array[array_index] = String.valueOf(array_char);
			arr		isfull[array_index] = true;// �� �ε��� string�� ä����

					j = 0;
				}
			}

			fr.close();
		} catch (Exception e) {
			System.out.println("shortread" + e);
		}
	}

	public static void matchDNA(int k, int n) {
		// R_DNA�� ��Ī���Ѽ� ���� ���⼭�� ���ϱ�
		char[] array_char = new char[k];

		boolean[] isuse = new boolean[n];// ����ߴ��� ����

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
			while ((singlech = fr.read()) != -1) {// k���� ���ھ� �����鼭 DNA��ġ�� ã�� �ִ´�.

				array_char[j] = (char) singlech;
				j++;
				if (j == k) {
					fw.write(submatchDNA(array_char, isuse));
					j = 0;
				}
			}
			long end = System.currentTimeMillis();
			System.out.println("�ɸ��� �ð�:"+(end-start)+"ms");

			fr.close();
			fw.close();
		} catch (FileNotFoundException e) {
			System.out.println("matchDNA: " + e);
		} catch (IOException e) {
			System.out.println("matchDNA: " + e);
		}

	}

	public static String submatchDNA(char[] c, boolean[] isuse) {
		// ��Ī ����
		int n = array.length;// ���ڿ� ����
		int mismatch = 0;
		char[] myDNA;

		try {

			for (int i = 0; i < n; i++) { // bruteforce ��
				mismatch = 0;
				myDNA = array[i].toCharArray();

				for (int j = 0; j < c.length; j++) { // mismatch ���� ����
					if (myDNA[j] != c[j]) {
						mismatch++;
					}
				}
				if ((mismatch <= 2) && (isuse[i] == false)) {// mismatch �����������ϰ� �������ʾҴٸ�
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
		System.out.print("shortRead ����(k): "); // k,n���� �Է�
		k = sc.nextInt();
		System.out.print("");
		System.out.print("shortRead ����(n): ");
		n = sc.nextInt();
		System.out.print("");

		makeDNA(k, n);
		shortread(k, n);
		matchDNA(k, n);

	}

}
