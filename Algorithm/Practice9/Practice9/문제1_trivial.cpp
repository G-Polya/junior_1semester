//2016112158 �����
//refDNA >> myDNA(����20%, ������) >> shortRead >> myDNA(����)
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <tuple>
#include <iomanip>
#include <algorithm>
#include <chrono>
using namespace std;


//referenceDNA�� �����ϴ� �Լ�
void make_refDNA(string filename, int length)
{
	ofstream fout;		//���ϰ�ü ����
	fout.open(filename);

	random_device rd;		 //�õ尪�� ��� ���� random_device ����

	for (int i = 0; i < length; i++)
	{
		//uniform_int_distribution<int> distribution(0, 4);	//0���� 99���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ���� ����
		int rad = rand() % 4;
		if (rad % 4 == 0)
			fout << 'A';
		else if (rad % 4 == 1)
			fout << 'G';
		else if (rad % 4 == 2)
			fout << 'C';
		else if (rad % 4 == 3)
			fout << 'T';
	}
	fout.close();
}


// �Ű������� �־��� �迭���� ������ ���Ҹ� �����ϰ� �����ϴ� �Լ�
template <typename T>
T shuffle(T arr[], int num)
{
	srand((unsigned int)time(NULL));
	T temp;
	int rn;
	for (int i = 0; i < num - 1; i++)
	{
		rn = rand() % (num - i) + i;
		temp = arr[i];
		arr[i] = arr[rn];
		arr[rn] = temp;
	}

	return temp;
}

// string�迭�� ���ҵ��� �̾���� string�� ��ȯ�ϴ� �Լ� 
string concat(string strArr[], int size)
{
	string result;

	queue<string> q;
	for (int i = 0; i < size; i++)
		q.push(strArr[i]);

	while (!q.empty())
	{
		result += q.front();
		q.pop();
	}

	return result;
}

// 
string make_myDNA(string refDNA)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> sample(0, 4);
	int col = 5;
	int row = refDNA.length() / col;


	string* temp_myDNA = new string[row];
	for (int i = 0; i < row; i++)
	{
		temp_myDNA[i] = refDNA.substr(i * col, col);
	}


	for (int i = 0; i < row; i++)			//temp_myDNA�� ��� ����. �� refDNA�� ��еǾ� ������� string�� ���Ͽ�
	{
		int index = sample(gen);		// 20%Ȯ���� �����ϰ� �������̰� �Ͼ �ε��� ����

		if (temp_myDNA[i][index] == 'A')	// �������̰� �Ͼ �ε����� �ش��ϴ� ���ڰ� A���. 
		{
			char arr[3] = { 'G','C','T' };
			temp_myDNA[i][index] = shuffle(arr, 3);	// G,C,T �߿��� �ϳ��� �ٲ�
		}
		else if (temp_myDNA[i][index] == 'G')
		{
			char arr[3] = { 'A','C','T' };
			temp_myDNA[i][index] = shuffle(arr, 3);

		}
		else if (temp_myDNA[i][index] == 'C')
		{
			char arr[3] = { 'A','G','T' };
			temp_myDNA[i][index] = shuffle(arr, 3);

		}
		else if (temp_myDNA[i][index] == 'T')
		{
			char arr[3] = { 'A','G','C' };
			temp_myDNA[i][index] = shuffle(arr, 3);

		}
	}

	string myDNA = concat(temp_myDNA, row);
	return myDNA;
}

void make_shortRead(int k, int n, string refDNA_path, string directory)
{
	ifstream fin;	// �б� ���� ��ü ����
	fin.open(refDNA_path);
	string refDNA;
	fin >> refDNA;	// �о�� ������ string��ü�� ����

	random_device rd;	// �õ尪�� ��� ���� random_device ����
	mt19937 gen(rd());

	string myDNA = make_myDNA(refDNA);
	uniform_int_distribution<int> start_point(0, myDNA.length() - k);		// ���������� �������� ����


	for (int i = 0; i < n; i++)
	{
		ofstream fout;
		string short_Name = directory + "\\shortRead_" + to_string(i) + ".txt";	//shortRead���丮�� ����
		fout.open(short_Name);


		string shortRead = myDNA.substr(start_point(gen), k);	// �������� ���� ������ġ���� length��ŭ�� ���꽺Ʈ�� ��ȯ


		fout << shortRead;
		fout.close();
	}


}

//threshold�� ������ �ִ°� �����̴�.
// �ʹ� ���� ���� �ָ� string subscript out of range������ ��Ÿ����
// �ʹ� ū ���� �ָ� myDNA�� refDNA�� ���� ��ġ��
int brute_force_matching(string refDNA, string shortRead, int threshold)
{
	int i_sum;
	int M = shortRead.size();
	int N = refDNA.size();
	for (int i = 0; i <= N - M; i++)
	{
		int j;
		int mismatches = 0;		// ��ġ���� �ʴ� ������ ����

		for (j = 0; j < M; j++)
			if (shortRead[j] != refDNA[i + j])
			{
				mismatches++;
				continue;
			}

		if (mismatches < threshold)
		{
			return i;
		}

	}
}


string trivial_Mapping(string refDNA, vector<string> shortReads, int threshold)
{
	try
	{
		//string before_myDNA = make_myDNA(refDNA);	// myDNA�� refDNA�� ���� ����ϴ�. 
		string before_myDNA = make_myDNA(refDNA);

		int number = 0;
		for (auto& shortRead : shortReads)		// ������ shortRead�� ���ؼ�
		{
			int index = brute_force_matching(refDNA, shortRead, threshold);		// ���� mismatch�� ���� �ε����� �����´�. 
			cout << number << " ��° shortRead�� " << index << "���� ��Ÿ��" << endl;
			number++;
			for (int i = index; i < index + shortRead.length(); i++)
				before_myDNA[i] = shortRead[i - index];				// myDNA���� index ~ (index+length)�� �ش��ϴ� �κ��� shortRead�� �ٲ��ش�.
		}
		return before_myDNA;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}


}

// refDNA�� myDNA�� ���Ͽ� ��ġ�ϴ� ������ ��ȯ�ϴ� �Լ�
tuple<double, size_t> compare_degree(string refDNA, string myDNA)
{
	double N = refDNA.size();
	double M = myDNA.size();

	size_t mismatches = 0;

	for (int i = 0; i <= N - M; i++)
	{
		int j;
		for (j = 0; j < M; j++)
			if (myDNA[j] != refDNA[i + j])
			{
				mismatches++;
				continue;
			}
	}


	double result = (M - mismatches) / M * 100;

	return make_tuple(result, mismatches);
}




int main()
{
	//make_refDNA("referenceDNA.txt", 500000);				// referenceDNA�� ���鶧 ���
	int k, n;
	cout << "shortRead�� ���� k�� �Է����ּ��� >> ";
	cin >> k;
	cout << "shortRead�� ���� n�� �Է����ּ��� >> ";
	cin >> n;
	//make_shortRead(k, n, "referenceDNA.txt", to_string(k) + "_shortRead");	// shortRead���� ���鶧 ���

	ifstream refDNA_in;
	refDNA_in.open("referenceDNA.txt");
	string refDNA;
	refDNA_in >> refDNA;

	//myDNA�� ���� �� ���
	vector<string> shortReads;		//shortRead���� ������ vector
	for (int i = 0; i < n; i++)
	{
		ifstream fin;
		fin.open(to_string(k) + "_shortRead\\shortRead_" + to_string(i) + ".txt");
		string shortRead;
		fin >> shortRead;

		shortReads.push_back(shortRead);
	}



	cout << "myDNA : " << endl;
	string myDNA;

	for (int threshold = 5; threshold <= 20; threshold += 5)
	{
		ofstream myDNA_out;	// myDNA.txt�� �Է��ϱ� ���� ���Ͻ�Ʈ��
		string myDNA_name = to_string(k) + "_" + to_string(threshold) + "_myDNA.txt";
		myDNA_out.open(myDNA_name, ios::app | ios::out);

		ofstream information;	// �����ð�, ��ġ��, ����ġ ������ �Է��ϱ� ���� ���� ��Ʈ��
		string information_name = to_string(k) + "_information.txt";
		information.open(information_name, ios::app | ios::out);


		chrono::steady_clock::time_point start = chrono::steady_clock::now();
		myDNA = trivial_Mapping(refDNA, shortReads, threshold);	// myDNA ����
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		auto elapsed_seconds = chrono::duration_cast<chrono::seconds>(end - start).count();
		auto elapsed_minutes = chrono::duration_cast<chrono::minutes>(end - start).count();

		myDNA_out << myDNA;	//myDNA�� ���Ͽ� �Է�. 
		myDNA_out.close();

		// threshold�� ���� �����ð�, ��ġ��, ����ġ ������ ���Ͽ� �Է�
		information << "threshold�� " << threshold << " �� �� : " << endl;
		information << "���� �ð� : " << elapsed_seconds << " �� (" << elapsed_minutes << " ��)" << endl;

		double degree = get<0>(compare_degree(refDNA, myDNA));
		int mismathces = get<1>(compare_degree(refDNA, myDNA));
		information << "myDNA�� refDNA�� ��ġ�ϴ� ���� : " << get<0>(compare_degree(refDNA, myDNA)) << endl;
		information << "����ġ ���� : " << get<1>(compare_degree(refDNA, myDNA)) << endl;
		information << "============================" << endl;

		information.close();

	}



	// test_case
	/*string refDNA = "GCATGGATTCTCTTTGGACGAAAGTTTCCCAGACTGAGCGCACCACCAATAGTAAAAGAA";
	vector<string> shortReads = { "GCGTTGCTT","TTGTCTATGGCCG","CGAGAGATTCCTAGACT","CAGAGCGGACCACCA","AACAGTAGAACAA" };


	string myDNA;
	myDNA = trivial_Mapping(refDNA, shortReads, 4);
	cout << refDNA << endl;
	cout << myDNA << endl;
	cout << get_match_degree(refDNA, myDNA)<<" %" << endl;*/

}