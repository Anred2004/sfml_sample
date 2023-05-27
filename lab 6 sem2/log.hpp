#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
namespace pp
{
	enum class Log_level
	{
		INFO,
		DEBUG,
		ERROR
	};
	class Logger
	{
	private:
		static ofstream m_out;
		static Log_level m_loglevel;
	public:
		static void setLogLevel(Log_level loglevel)
		{
			m_loglevel = loglevel;
		}
		static void setLog(const string& path)
		{
			m_out.open(path);
		}
		static void Write(const string& msg)
		{
			cout << msg << endl;
			m_out << msg << endl;
		}
		static void WriteInfo(const string& msg)
		{
			if (m_loglevel <= Log_level::INFO)
			{
				Write("[INFO] " + msg);
			}
			time_t now = std::time(0);
			char* dt = ctime(&now);
			cout << dt << endl;
		}
		static void WriteDebug(const string& msg)
		{
			if (m_loglevel <= Log_level::DEBUG)
			{
				Write("[DEBUG] " + msg);
				time_t now = std::time(0); 
				char* dt = ctime(&now);
				cout << dt << endl;
			}
		}
		static void WriteError(const string& msg)
		{
			if (m_loglevel <= Log_level::ERROR)
			{
				Write("[ERROR] " + msg);
				time_t now = std::time(0);
				char* dt = ctime(&now);
				cout << dt << endl;
			}
		}

	};
}
