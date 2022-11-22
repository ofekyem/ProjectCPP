#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
bool isValid(string s) {
	bool a = find_if(s.begin(), s.end(), ::isdigit) != s.end();
	if (!a) {
		return false;
	} 

	int i = 0;
	int flag = 0;
	for (i = 0; i < s.length(); i++) {
		char c = s[i]; 
		if (c != ' ' && c != '.' && (c < '0' || c > '9')) {
			return false;
		}
		if (c == ' ' && flag==1) {
			flag = 0;
		}
		if (c == '.') {
			if (flag == 1) {
				return false;
			}
			flag = 1;
			if (i + 1 < s.length()) {
				if (s[i + 1] == ' ') {
					return false;
				}
			}
			else {
				return false;
			}
		}
	} 
	return true;
} 

int vectorLength(string s) {
	int i = 0;
	int lastDigitIndex = 0; 
	while (s[i] != '\0') {
		if (s[i] >= '0' && s[i] <= '9') {
			lastDigitIndex = i;
		} 
		i++;
	} 
	i = 0;
	int vl = 1;
	while (s[i] != s[lastDigitIndex]) {
		if (s[i] == ' ') {
			vl++;
		}
		i++;
	}
	return vl;
} 

double* createVectorFromString(string s,double *vector, int length) {
	int i = 0;
	char space[] = " ";
	char* token;

	token = strtok(&s[0], space);
	while (token != NULL)
	{
		string strWord(token);
		double number = stod(strWord);
		vector[i] = number;
		i++;
		token = strtok(NULL, space);
	}
	return vector;
}

void Euclideandistance(double* vec1, double* vec2, int lenght) {
	int i = 0;
	double sum = 0;
	for (i = 0; i < lenght; i++) {
		sum = (vec1[i] - vec2[i]) * (vec1[i] - vec2[i]) + sum;
	}
	cout << sqrt(sum) << endl;
}

void Taxicabgeometry(double* vec1, double* vec2, int lenght) {
	int i = 0;
	double sum = 0;
	for (i = 0; i < lenght; i++) {
		sum = abs(vec1[i] - vec2[i]) + sum;
	}
	cout << sum << endl;
}


void Chebyshevdistance(double* vec1, double* vec2, int lenght) {
	int i = 0;
	double sum = 0;
	double* arr = new double[lenght];

	for (i = 0; i < lenght; i++) {
		sum = vec1[i] - vec2[i];
		arr[i] = abs(sum);
		sum = 0;
	}
	double max = arr[0];
	for (i = 1; i < lenght; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	cout << max << endl;
	delete[] arr;
}

void Canberradistance(double* vec1, double* vec2, int lenght) {
	int i = 0;
	double sum = 0;
	double sum2 = 0;
	double sum3 = 0;
	double* arr = new double[lenght];

	for (i = 0; i < lenght; i++) {
		sum = abs(vec1[i] - vec2[i]);
		sum2 = abs(vec1[i]) + abs(vec2[i]);
		sum3 = sum / sum2 + sum3;
	}
	cout << sum3 << endl;
}

void Minkowskidistance(double* vec1, double* vec2, int lenght) {
	// for p=1
	int i = 0;
	double sum = 0;
	for (i = 0; i < lenght; i++) {
		sum = (vec1[i] - vec2[i]) * (vec1[i] - vec2[i]) + sum;
	}
	cout << sqrt(sum) << endl;
} 

int main()
{
	string v1, v2;
	getline(cin, v1);
	getline(cin, v2);
	if (!isValid(v1) || !isValid(v2)) {//if not valid input
		cout << "error";
		return 0;
	}
	int v1_length = vectorLength(v1);//length of vector
	int v2_length = vectorLength(v2);
	
	if (v1_length != v2_length) {//if not equal in length
		cout << "error";
		return 0;
	}
	double* vectorA = new double[v1_length];
	double* vectorB = new double[v2_length];
	vectorA = createVectorFromString(v1, vectorA, v1_length);//creates vector from string
	vectorB = createVectorFromString(v2, vectorB, v2_length);
	int a = vectorA[1]; 
	int b = vectorA[2];
	
	Euclideandistance(vectorA, vectorB, v1_length);
	Taxicabgeometry(vectorA, vectorB, v1_length);
	Chebyshevdistance(vectorA, vectorB, v1_length);
	Canberradistance(vectorA, vectorB, v1_length);
	Minkowskidistance(vectorA, vectorB, v1_length);
	// call distance functions
	//add text for new things
	return 0;
}
