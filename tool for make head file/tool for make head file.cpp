// tool for make head file.cpp : 定义控制台应用程序的入口点。
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
	//string patht = "E://1项目//硕士毕业设计//TVL.txt";
	cout << "name: ";
	cin >> file_name;
	//cout >> "file path: ";
	
	ofstream outfile_h(file_name+".h");

	string name_space;
	cout << "name_space: ";
	cin >> name_space;

	outfile_h << "#ifndef " + file_name + "_H_ \n"
		+ "#define " + file_name + "_H_ \n \n"
		+ "namespace " + name_space 
		+ "\n { "
		+"\n }"


		+ "\n #endif";

	outfile_h.close();
	string include = "#include";//
	//string yubianyi = "stdafx";
	ofstream outfile_cpp(file_name + ".cpp");
	string output_normal;
	
	cout << "the type: 0:normal    1:template: ";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 0:
		output_normal = include + '"' + "stdafx" + ".h" + '"' + '\n'
			+ include + '"' + file_name + ".h" + '"' + '\n'
			+ '\n'
			+ "using namespace " + name_space + ";"
			+ '\n'
			;
		break;
	case 1:
		output_normal = include + '"' + "stdafx" + ".h" + '"' + '\n'
			+ include + '"' + file_name + ".h" + '"' + '\n'
			+ '\n'
			+ "namespace " + name_space + '\n' + "{"
			+ '\n'
			+ "}"
			;
		break;
	default:
		cout << "wrong" << endl;
		break;
	}
	
	outfile_cpp << output_normal;
	
	outfile_cpp.close();
	return 0;
}

