//2016112158 김희수
//refDNA >> myDNA(스닙20%, 복원전) >> shortRead >> myDNA(복원)
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
#include <functional>
using namespace std;

vector<int> random_numbers(int length)
{
	int temp, x, y;

	mt19937 random_engine((unsigned int)time(NULL));	//메르센 트위스터 난수엔진
	uniform_int_distribution<int> distribution(0, length);	// 균등분포

	vector<int> random;
	for (int i = 0; i < length; i++)
		random.push_back(i);

	for (int i = 0; i < length; i++)		// shuffle과정
	{
		x = distribution(random_engine);	// 인덱스를 랜덤하게 추출
		y = distribution(random_engine);

		if (x != y)		// 같지 않다면
		{
			temp = random[x];
			random[x] = random[y];
			random[y] = temp;
		}
	}

	// random객체는 0~50000가 무작위적으로 셔플된 객체
	return random;
}


//referenceDNA를 생성하는 함수
void make_refDNA(string filename, int length)
{
	ofstream fout;		//파일객체 생성
	fout.open(filename);

	vector<int> random = random_numbers(length);


	for (int i = 0; i < length; i++)
	{

		if (random[i] % 4 == 0)
			fout << 'A';

		else if (random[i] % 4 == 1)
			fout << 'G';

		else if (random[i] % 4 == 2)
			fout << 'C';
		else if (random[i] % 4 == 3)
			fout << 'T';
	}


	fout.close();
}


// 매개변수로 주어진 배열에서 임의의 원소를 랜덤하게 추출하는 함수
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

// string배열의 원소들을 이어붙인 string을 반환하는 함수 
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
string make_myDNA(string refDNA, double probability)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> sample(0, 4);
	int col = 100 / probability;
	int row = refDNA.length() / col;


	string* temp_myDNA = new string[row];
	for (int i = 0; i < row; i++)
	{
		temp_myDNA[i] = refDNA.substr(i * col, col);
	}


	for (int i = 0; i < row; i++)			//temp_myDNA의 모든 원소. 즉 refDNA가 등분되어 만들어진 string에 대하여
	{
		int index = sample(gen);		// 20%확률로 랜덤하게 돌연변이가 일어날 인덱스 설정

		if (temp_myDNA[i][index] == 'A')	// 돌연변이가 일어날 인덱스에 해당하는 문자가 A라면. 
		{
			char arr[3] = { 'G','C','T' };
			temp_myDNA[i][index] = shuffle(arr, 3);	// G,C,T 중에서 하나로 바뀜
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

void make_shortRead(int k, int n, string refDNA_path, string directory, double probability)
{
	ifstream fin;	// 읽기 파일 객체 생성
	fin.open(refDNA_path);
	string refDNA;
	fin >> refDNA;	// 읽어온 파일은 string객체에 저장

	random_device rd;	// 시드값을 얻기 위한 random_device 설정
	mt19937 gen(rd());

	string myDNA = make_myDNA(refDNA, probability);
	uniform_int_distribution<int> start_point(0, myDNA.length() - k);		// 시작위지를 랜덤으로 설정


	for (int i = 0; i < n; i++)
	{
		ofstream fout;
		string short_Name = directory + "\\shortRead_" + to_string(i) + ".txt";	//shortRead디렉토리에 저장
		fout.open(short_Name);


		string shortRead = myDNA.substr(start_point(gen), k);	// 랜덤으로 뽑은 시작위치에서 length만큼의 서브스트링 반환


		fout << shortRead;
		fout.close();
	}


}

//threshold를 적절히 주는게 관건이다.
// 너무 적은 수를 주면 string subscript out of range에러가 나타나고
// 너무 큰 수를 주면 myDNA와 refDNA가 거의 일치함
int brute_force_matching(string refDNA, string shortRead, int threshold)
{
	int i_sum;
	int M = shortRead.size();
	int N = refDNA.size();
	for (int i = 0; i <= N - M; i++)
	{
		int j;
		int mismatches = 0;		// 일치하지 않는 문자의 개수

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


tuple<string, string> trivial_Mapping(string refDNA, vector<string> shortReads, int threshold, double probablity)
{
	try
	{
		//string before_myDNA = make_myDNA(refDNA);	// myDNA와 refDNA는 거의 비슷하다. 
		string after_myDNA = make_myDNA(refDNA, probablity);
		string original = after_myDNA.substr(0, after_myDNA.length());

		int number = 0;
		for (auto& shortRead : shortReads)		// 각각의 shortRead에 대해서
		{
			int index = brute_force_matching(refDNA, shortRead, threshold);		// 가정 mismatch가 적은 인덱스를 가져온다. 
			cout << number << " 번째 shortRead는 " << index << "부터 나타남" << endl;
			number++;
			for (int i = index; i < index + shortRead.length(); i++)
				after_myDNA[i] = shortRead[i - index];				// myDNA에서 index ~ (index+length)에 해당하는 부분을 shortRead로 바꿔준다.
		}
		return make_tuple(original, after_myDNA);
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}


}

// refDNA와 myDNA를 비교하여 일치하는 정도를 반환하는 함수
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
	make_refDNA("referenceDNA.txt", 500000);				// referenceDNA를 만들때 사용
	int k, n;
	cout << "shortRead의 길이 k를 입력해주세요 >> ";
	cin >> k;
	cout << "shortRead의 개수 n를 입력해주세요 >> ";
	cin >> n;
	make_shortRead(k, n, "referenceDNA.txt", to_string(k) + "_shortRead", 7);	// shortRead들을 만들때 사용, probability는 20%

	ifstream refDNA_in;
	refDNA_in.open("referenceDNA.txt");
	string refDNA;
	refDNA_in >> refDNA;

	//myDNA를 만들 때 사용
	vector<string> shortReads;		//shortRead들을 저장할 vector
	for (int i = 0; i < n; i++)
	{
		ifstream fin;
		fin.open(to_string(k) + "_shortRead\\shortRead_" + to_string(i) + ".txt");
		string shortRead;
		fin >> shortRead;

		shortReads.push_back(shortRead);
	}



	cout << "myDNA : " << endl;
	string after_DNA;
	string original_myDNA;
	tuple<string, string> myDNA;
	for (int threshold = 5; threshold <= 20; threshold += 5)
	{
		ofstream afterDNA_out;	// myDNA.txt를 입력하기 위한 파일스트림
		string after_myDNA_name = to_string(k) + "_" + to_string(threshold) + "_myDNA.txt";
		afterDNA_out.open(after_myDNA_name, ios::app | ios::out);

		ofstream information;	// 복원시간, 일치도, 불일치 개수를 입력하기 위한 파일 스트림
		string information_name = to_string(k) + "_information.txt";
		information.open(information_name, ios::app | ios::out);


		chrono::steady_clock::time_point start = chrono::steady_clock::now();
		myDNA = trivial_Mapping(refDNA, shortReads, threshold, 20);
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		auto elapsed_seconds = chrono::duration_cast<chrono::seconds>(end - start).count();
		auto elapsed_minutes = chrono::duration_cast<chrono::minutes>(end - start).count();

		original_myDNA = get<0>(myDNA);
		after_DNA = get<1>(myDNA);

		afterDNA_out << after_DNA;	//myDNA를 파일에 입력. 
		afterDNA_out.close();

		// threshold에 따른 복원시간, 일치도, 불일치 개수를 파일에 입력
		information << "threshold가 " << threshold << " 일 때 : " << endl;
		information << "복원 시간 : " << elapsed_seconds << " 초 (" << elapsed_minutes << " 분)" << endl;
		information << "refDNA의 길이 : " << refDNA.length() << " myDNA의 길이 : " << after_DNA.length() << endl;

		double degree = get<0>(compare_degree(refDNA, after_DNA));
		int mismathces = get<1>(compare_degree(refDNA, after_DNA));
		information << "복원후 myDNA와 refDNA의 일치하는 정도 : " << get<0>(compare_degree(refDNA, after_DNA)) << endl;
		information << "복원후 myDNA와 복원전 myDNA가 일치하는 정도 : " << get<0>(compare_degree(after_DNA, original_myDNA)) << endl;
		information << endl;
		information << "복원후 myDNA와 refDNA불일치 개수 : " << get<1>(compare_degree(refDNA, after_DNA)) << endl;
		information << "복원후 myDNA와 복원전 myDNA의 불일치개수 : " << get<1>(compare_degree(after_DNA, original_myDNA)) << endl;

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