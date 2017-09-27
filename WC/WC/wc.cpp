#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

int charCount(const char *fileAbsolutePath)
{
	if (fileAbsolutePath == NULL)
	{
		cerr << "The file path is empty\n";
		return 0;
	}
	std::ifstream read(fileAbsolutePath);
	if (!read.is_open())
	{
		cerr << "Can't open file: " << fileAbsolutePath << '\n';
		return 0;
	}
	size_t counter = 0;
	string buff;
	while (!read.eof())
	{
		std::getline(read, buff);
		counter += buff.size();
	}
	return counter;
}

inline bool isWordChar(char ch)
{
	return ch >= '0'&&ch <= '9' || ch >= 'A'&&ch <= 'Z' || ch >= 'a'&&ch <= 'z';
}

int wordCount(const char *fileAbsolutePath)
{
	if (fileAbsolutePath == NULL)
	{
		cerr << "The file path is empty\n";
		return 0;
	}
	std::ifstream read(fileAbsolutePath);
	if (!read.is_open())
	{
		cerr << "Can't open file: " << fileAbsolutePath << '.\n';
		return 0;
	}
	int counter = 0;
	bool prevFlag, tempFlag;
	string buff;
	while (!read.eof())
	{
		prevFlag = false;
		std::getline(read, buff);
		auto endIndex = std::min(buff.find("//"), buff.find("/*"));
		if (endIndex == string::npos)
			endIndex = buff.size();
		for (auto startIndex = (unsigned)0; startIndex < endIndex; ++startIndex)
		{
			tempFlag = isWordChar(buff[startIndex]);
			if (!prevFlag && tempFlag)
				++counter;
			prevFlag = tempFlag;
		}
		if (buff.find("/*") != string::npos)
		{
			while (buff.find("*/") == string::npos)
				std::getline(read, buff);
		}
	}
	return counter;
}

int lineCount(const char *fileAbsolutePath)
{
	if (fileAbsolutePath == NULL)
	{
		cerr << "The file path is empty\n";
		return 0;
	}
	std::ifstream read(fileAbsolutePath);
	if (!read.is_open())
	{
		cerr << "Can't open file: " << fileAbsolutePath << ',\n';
		return 0;
	}
	int counter = 0;
	string buff;
	while (!read.eof())
	{
		getline(read, buff);
		++counter;
	}
	return counter;
}

#ifdef WIN32
#include <direct.h>
#include <io.h>
#endif

int multiLineCount(const char *fileAbsolutePath, int &codeLineNum, int &blankLineNum, int &commentLineNum)
{
	if (fileAbsolutePath == NULL)
		return -1;
	codeLineNum = blankLineNum = commentLineNum = 0;
	string dir(fileAbsolutePath);
	auto findIndex = dir.find_last_of("/\\");
	if (findIndex == string::npos)
		findIndex = dir.size();
#ifdef WIN32
	_finddata_t file;
	long lf;
	if ((lf = _findfirst(fileAbsolutePath, &file)) == -1)
	{
		std::cerr << "Can't find the file.\n";
		return 1;
	}
	if (file.attrib & _A_SUBDIR)
	{
		std::cerr << "Can't count the lines of folder.\n";
		return 2;
	}
	_findclose(lf);
	std::ifstream read(dir.substr(0, findIndex).append("/") + file.name);
#endif
	if (!read.is_open())
	{
		std::cerr << "Open file failed.\n";
		return 0;
	}
	static char blankChar[] = { '(', ')', '{', '}', '\t', '\n', '\r', ' ', '\0' };
	string buff;
	while (!read.eof())
	{
		std::getline(read, buff);
		findIndex = std::min(buff.find("//"), buff.find("/*"));
		if (findIndex == string::npos)
			findIndex = buff.size();
		string temp = std::move(buff.substr(0, findIndex));
		if (std::count_if(temp.begin(), temp.end(), isWordChar) > 0)
			++codeLineNum;
		if ((findIndex = buff.find_first_not_of(blankChar)) == string::npos)
			++blankLineNum;
		else if (buff.find("//") != string::npos)
			++commentLineNum;
		else if (buff.find("/*") != string::npos)
		{
			findIndex = string::npos;
			while (!read.eof() && (findIndex = buff.find("*/") == string::npos))
			{
				++commentLineNum;
				std::getline(read, buff);
			}
			if (findIndex != string::npos)
				++commentLineNum;
		}
	}
	return 0;
}

#include <list>
#include <queue>

std::list<string> searchFiles(string absolutePath)
{
	std::list<string> filesAbsolutePath;
	std::queue<string> dirQueue;
	string dir = absolutePath.substr(0, absolutePath.find_last_of("/\\"));
	string file = absolutePath.substr(absolutePath.find_last_of("/\\") + 1);
	string name = file.substr(0, file.find_last_of('.'));
	string ext = file.substr(file.find_last_of('.') + 1);
	intptr_t hFile;
	_finddata_t fileInfo;
	do
	{
		hFile = _findfirst((dir + "/*").c_str(), &fileInfo);
		if (hFile == -1)
		{
			cerr << "Can't open the dir.\n";
			return filesAbsolutePath;
		}
		do
		{
			if (strcmp(fileInfo.name, ".") == 0 || strcmp(fileInfo.name, "..") == 0)
				continue;
			if (fileInfo.attrib & _A_SUBDIR)
				dirQueue.push(dir + '/' + fileInfo.name);
			else if (ext == "*" || ext == "")
				filesAbsolutePath.push_back(dir + '/' + fileInfo.name);
			else
			{
				file = fileInfo.name;
				if (ext == file.substr(file.find_last_of('.') + 1))
					filesAbsolutePath.push_back(dir + '/' + fileInfo.name);
			}
		} while (_findnext(hFile, &fileInfo) == 0);
		_findclose(hFile);
		dir = dirQueue.front();
		dirQueue.pop();
	} while (!dirQueue.empty());
	return filesAbsolutePath;
}

int filesCount(int argc, char *argv[])
{
	if (argc < 4)
	{
		cerr << "The parameters error!\n";
		return -1;
	}
	string argv2(argv[2]);
	std::list<string> filesAbsolutePath = std::move(searchFiles(argv[3]));
	if (argv2.compare("-c") == 0)
	{
		int charNum = 0, temp;
		for (auto beginIter = filesAbsolutePath.begin(); beginIter != filesAbsolutePath.end(); ++beginIter)
			charNum += (temp = charCount((*beginIter).c_str())) > 0 ? temp : 0;
		cout << "字符数：" << charNum << endl;
	}
	else if (argv2.compare("-w") == 0)
	{
		int wordNum = 0, temp;
		for (auto beginIter = filesAbsolutePath.begin(); beginIter != filesAbsolutePath.end(); ++beginIter)
			wordNum += (temp = wordCount((*beginIter).c_str())) > 0 ? temp : 0;
		cout << "单词数：" << wordNum << endl;
	}
	else if (argv2.compare("-l") == 0)
	{
		int lineNum = 0, temp;
		for (auto beginIter = filesAbsolutePath.begin(); beginIter != filesAbsolutePath.end(); ++beginIter)
			lineNum += (temp = lineCount((*beginIter).c_str())) > 0 ? temp : 0;
		cout << "行数：" << lineNum << endl;
	}
	else if (argv2.compare("-a") == 0)
	{
		int codeLineNum = 0, blankLineNum = 0, commentLineNum = 0;
		int codeTemp, blankTemp, commentTemp;
		for (auto beginIter = filesAbsolutePath.begin(); beginIter != filesAbsolutePath.end(); ++beginIter)
		{
			multiLineCount((*beginIter).c_str(), codeTemp, blankTemp, commentTemp);
			codeLineNum += codeTemp;
			blankLineNum += blankTemp;
			commentLineNum += commentTemp;
		}
		cout << "代码行数：" << codeLineNum << "\n空行数：" << blankLineNum << "\n注释行数：" << commentLineNum << endl;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 3 && !(argc == 2 && strcmp(argv[1], "-x") == 0))
	{
		std::cerr << "The parameters error!\n";
		return -1;
	}
	string argv1 = argv[1];
	if (argv1.compare("-c") == 0)
		cout << "字符数：" << charCount(argv[2]) << endl;
	else if (argv1.compare("-w") == 0)
		cout << "单词数：" << wordCount(argv[2]) << endl;
	else if (argv1.compare("-l") == 0)
		cout << "行数：" << lineCount(argv[2]) << endl;
	else if (argv1.compare("-s") == 0)
		filesCount(argc, argv);
	else if (argv1.compare("-a") == 0)
	{
		int codeLineNum, blankLineNum, commentLineNum;
		multiLineCount(argv[2], codeLineNum, blankLineNum, commentLineNum);
		cout << "代码行数：" << codeLineNum << "\n空行数：" << blankLineNum << "\n注释行数：" << commentLineNum << endl;
	}
	else if (argv1.compare("-x") == 0)
		system("wcgui");
	return 0;
}