#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "log.hpp"
int main()
{
	pp::Logger::setLogLevel(pp::Log_level::INFO);//кастом логгер позволяет отключить все логи вместо того, чтобы их комментировать
	pp::Logger::setLog("log.txt");
	pp::Logger::Write("Hello world");
	pp::Logger::WriteInfo("This is info message");
	pp::Logger::WriteDebug("This is debug message");
	pp::Logger::WriteError("This is error message");
	system("pause");
}
