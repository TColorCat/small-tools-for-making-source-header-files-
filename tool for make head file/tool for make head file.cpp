// tool for make head file.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>  
#include <iomanip>  
#include <fstream>  
#include<vector>
#include<fstream>
#include<string>

//#include <sstream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	string file_name;
	//string patht = "E://1��Ŀ//˶ʿ��ҵ���//TVL.txt";
	cout << "name: ";
	cin >> file_name;
	//cout >> "file path: ";
	
	ofstream outfile_h(file_name+".h");

	string name_space;
	cout << "name_space: ";
	cin >> name_space;

	outfile_h << "#ifndef " + file_name + "_H_ \n"
		+ "#define " + file_name + "_H_ \n \n"
		+ "namespace " + name_space + "\n { "
		+

		+"\n }"


		+ "\n #endif";

	outfile_h.close();
	string include = "#include";
	string yubianyi = "stdafx";
	ofstream outfile_cpp(file_name + ".cpp");
	outfile_cpp <<
		include + '"' + yubianyi + ".h" + '"' + '\n'
		+ include + '"' + file_name + ".h" + '"' + '\n'
		+ '\n'
		+ "using namespace " + name_space + ";"
		+ '\n'
		;
	return 0;
}

