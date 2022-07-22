#include "Header.h"

//Exception
Exception::Exception(const string& text, const int& line, const string& source)
	: text(text), line(line), source(source) {
	ttime = time(NULL);
#pragma warning(suppress : 4996).
	tm* locTime = localtime(&ttime);
	dateTime = to_string(locTime->tm_hour);
	dateTime += ':';
	dateTime += to_string(locTime->tm_min);
	dateTime += ':';
	dateTime += to_string(locTime->tm_sec);
}
void Exception::saveData() const{
	ofstream data("errors.txt", ios::app);
	data.setf(ios::left);
	if (data.is_open()) {
		data << setw(7) << dateTime << "=> " << setw(7) << "Line: " << line << " " << setw(7) << "Source: " << source << " " << setw(7) << "Text: " << text << endl;
	}
	data.close();
}
void Exception::show()const {
	system("cls");
	cout << "Text: " << text << endl;
	system("pause");
}

//DatabaseException
DatabaseException::DatabaseException(const string& text, const int& line, const string& source)
	: Exception(text, line, source) {}

//InvalidArgumentException
InvalidArgumentException::InvalidArgumentException(const string& text, const int& line, const string& source)
	: Exception(text, line, source) {}