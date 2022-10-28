#include <iostream>
#include <string>
#include<algorithm>
#include<fstream>
#include<cstring>
#include<ios>
using namespace std;
ifstream myfile;
ofstream suffixArray("suffix array.txt", ios::out );
struct SUFFIX
{
	int index;
	char* suffix;

};
int func(struct SUFFIX a, struct SUFFIX b)
{
	return strcmp(a.suffix, b.suffix) < 0 ? 1 : 0;
}

int* buildsuffixarray(char* text, int num)
{
	struct SUFFIX* suffixes = new SUFFIX[num];


	for (int i = 0; i < num; i++)
	{
		suffixes[i].index = i;
		suffixes[i].suffix = (text + i);
	}
	sort(suffixes, suffixes + num, func);

	int* suffixarray = new int[num];
	for (int i = 0; i < num; i++)
	{
		suffixarray[i] = suffixes[i].index;
	}
	return suffixarray;
}

void printArr(int arr[], int num)
{
	for (int i = 0; i < num; i++)
		suffixArray << arr[i] << endl;;
		//convert to binarry formate
		//suffixArray.write(reinterpret_cast<const char*>(&num), sizeof(num));
}

int main()
{//add $sign at the end of the file
	ofstream append("chr07.fsa", ios::app);
	append << "$" << endl;
	append.close();
	//close the file
	//open the file 
	myfile.open("chr07.fsa");
	string read;
	string file_contents;
	//reading the file
	while (!myfile.eof())
	{ //read the file line by line 
		getline(myfile, read);
		if (read[0] == '>')
		{
			//skip the description 
		}
		else {
			//save the content of the fasta file in one string

			file_contents += read;
		}
	}
	
	int n = file_contents.length();
	cout << file_contents.length() << endl;
	char* text = new char[n+1];
#pragma warning(suppress : 4996)
	strcpy(text, file_contents.c_str());
	int* suffixarray = buildsuffixarray(text, n);
	suffixArray << "Following is suffix array for " << endl;
	printArr(suffixarray, n);
	
	system("pause");
}