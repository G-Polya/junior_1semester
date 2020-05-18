//2016112158 김희수
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


//referenceDNA를 생성하는 함수
void make_refDNA(string filename, int length)
{
	ofstream fout;		//파일객체 생성
	fout.open(filename, ios::app | ios::out);
	random_device rd;		 //시드값을 얻기 위한 random_device 생성

	mt19937 gen(rd());	// random_deivce를 통해 난수 생성 엔진을 초기화, 메르센 트위스터 알고리즘. rand가 사용했던 선형합동방식보다 좋은 난수열 생성

	uniform_int_distribution<int> distribution(0, 50000);	//0부터 99까지 균등하게 나타내는 난수열을 생성하기 위해 균등분포 정의
	for (int i = 0; i < length; i++)
	{
		if (distribution(gen) % 4 == 0)
			fout << 'A';
		else if (distribution(gen) % 4 == 1)
			fout << 'G';
		else if (distribution(gen) % 4 == 2)
			fout << 'T';
		else if (distribution(gen) % 4 == 3)
			fout << 'C';
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

void make_shortRead(int length, int n, string refDNA, string directory)
{
	ifstream fin;	// 읽기 파일 객체 생성
	fin.open(refDNA);
	string text;
	fin >> text;	// 읽어온 파일은 string객체에 저장

	random_device rd;	// 시드값을 얻기 위한 random_device 설정
	mt19937 gen(rd());

	uniform_int_distribution<int> dis(0, text.length() - length);		// 시작위지를 랜덤으로 설정

	uniform_int_distribution<int> sample(0, 4);	//20%확률로 뽑아올 인덱스

	for (int i = 0; i < n; i++)
	{
		ofstream fout;
		string short_Name = directory + "\\shortRead_" + to_string(i) + ".txt";	//shortRead디렉토리에 저장
		fout.open(short_Name);
		//std::cout << dis(gen) << endl;

		string temp = text.substr(dis(gen), length);	// 랜덤으로 뽑은 시작위치에서 length만큼의 서브스트링 반환

		string* splited_temp = new string[length / 5];		// 20%확률로 돌연변이가 일어나기 위해 temp를 잘라서 만든 string배열
		int size = length / 5;		// 예를 들어 length가 10이라면 splited_temp의 원소개수는 2개이다

		for (int i = 0; i < size; i++)
		{
			splited_temp[i] = temp.substr(i * (length / size), length / size);	// splited_temp에는 temp를 등분한 string이 저장됨 
		}

		//std::cout << temp << " " << splited_temp[0] << " " << splited_temp[1] << endl;

		for (int i = 0; i < size; i++)			//splited_temp의 모든 원소. 즉 temp가 등분되어 만들어진 string에 대하여
		{
			int index = sample(gen);		// 20%확률로 랜덤하게 돌연변이가 일어날 인덱스 설정

			if (splited_temp[i][index] == 'A')	// 돌연변이가 일어날 인덱스에 해당하는 문자가 A라면
			{
				char arr[3] = { 'G','C','T' };
				splited_temp[i][index] = shuffle(arr, 3);	// G,C,T 중에서 하나로 바뀜
			}
			else if (splited_temp[i][index] == 'G')
			{
				char arr[3] = { 'A','C','T' };
				splited_temp[i][index] = shuffle(arr, 3);

			}
			else if (splited_temp[i][index] == 'C')
			{
				char arr[3] = { 'A','G','T' };
				splited_temp[i][index] = shuffle(arr, 3);

			}
			else if (splited_temp[i][index] == 'T')
			{
				char arr[3] = { 'A','G','C' };
				splited_temp[i][index] = shuffle(arr, 3);

			}
		}

		string shortRead = concat(splited_temp, size);	//	돌연변이가 일어난 결과. shortRead

		//string* splited_Read = new string[size];
		//for (int i = 0; i < size; i++)
		//{
		//	splited_Read[i] = shortRead.substr(i * (length / size), length / size);
		//}

		//std::cout << shortRead << " " << splited_Read[0] << " " << splited_Read[1] << endl;
		//
		//std::cout << "============================" << endl;
		fout << shortRead << endl;
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


string trivial_Mapping(string refDNA, vector<string> shortReads, int threshold)
{
	try
	{
		string myDNA = refDNA;	// myDNA와 refDNA는 거의 비슷하다. 

		int number = 0;
		for (auto& shortRead : shortReads)		// 각각의 shortRead에 대해서
		{
			int index = brute_force_matching(refDNA, shortRead, threshold);		// 가정 mismatch가 적은 인덱스를 가져온다. 
			cout << number << " 번쨰 shortRead는 " << index << "부터 나타남" << endl;
			number++;
			for (int i = index; i < index + shortRead.length(); i++)
				myDNA[i] = shortRead[i - index];				// myDNA에서 index ~ (index+length)에 해당하는 부분을 shortRead로 바꿔준다.
		}
		return myDNA;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}


}

// refDNA와 myDNA를 비교하여 일치하는 정도를 반환하는 함수
tuple<double, int> compare_degree(string refDNA, string myDNA)
{
	double N = refDNA.size();
	double M = myDNA.size();

	int mismatches = 0;

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
	//make_refDNA("referenceDNA.txt", 500000);				// referenceDNA를 만들때 사용
	int k, n;
	cout << "shortRead의 길이 k를 입력해주세요 >> ";
	cin >> k;
	cout << "shortRead의 개수 n를 입력해주세요 >> ";
	cin >> n;
	make_shortRead(k, n, "referenceDNA.txt", to_string(k) + "_shortRead");	// shortRead들을 만들때 사용

	ifstream inDNA;
	inDNA.open("referenceDNA.txt");
	string refDNA;
	inDNA >> refDNA;

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
	string myDNA;

	for (int threshold = 15; threshold < 20; threshold++)
	{
		ofstream myDNA_out;	// myDNA.txt를 입력하기 위한 파일스트림
		string myDNA_name = to_string(k) + "_" + to_string(threshold) + "_myDNA.txt";
		myDNA_out.open(myDNA_name, ios::app | ios::out);

		ofstream information;	// 복원시간, 일치도, 불일치 개수를 입력하기 위한 파일 스트림
		string information_name = to_string(k) + "_information.txt";
		information.open(information_name, ios::app | ios::out);


		chrono::steady_clock::time_point start = chrono::steady_clock::now();
		myDNA = trivial_Mapping(refDNA, shortReads, threshold);	// myDNA 생성
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		auto elapsed_seconds = chrono::duration_cast<chrono::seconds>(end - start).count();
		auto elapsed_minutes = chrono::duration_cast<chrono::minutes>(end - start).count();

		myDNA_out << myDNA;	//myDNA를 파일에 입력. 
		myDNA_out.close();

		// threshold에 따른 복원시간, 일치도, 불일치 개수를 파일에 입력
		information << "threshold가 " << threshold << " 일 때 : " << endl;
		information << "복원 시간 : " << elapsed_seconds << " 초 (" << elapsed_minutes << " 분)" << endl;

		double degree = get<0>(compare_degree(refDNA, myDNA));
		int mismathces = get<1>(compare_degree(refDNA, myDNA));
		information << "myDNA와 refDNA의 일치하는 정도 : " << get<0>(compare_degree(refDNA, myDNA)) << endl;
		information << "불일치 개수 : " << get<1>(compare_degree(refDNA, myDNA)) << endl;
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


	return 0;
}