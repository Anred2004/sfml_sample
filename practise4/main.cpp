#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
class Devices
{
public:
	virtual void poll()
	{
		cout << "Device name";
	}
};
class Chetchik : public Devices
{
public:
	void poll() override
	{
		cout << "Device Chetchik";
	}
};
class Signals : public Devices
{
public:
	void poll() override
	{
		cout << "Device Signals";
	}
};

class Warm : public Devices
{
public:
	void poll() override
	{
		cout << "Device Warm";
	}
};



int main()
{
	string line;
	vector<Devices*> Device;

	ifstream fail("pain.txt");
	if (fail.is_open())
	{
		while (getline(fail, line))
		{
			if ((line == "Mercury 230") || (line == "Neva MT314") || (line == "Enerymera CE308"))
			{
				Chetchik* a = new Chetchik();
				Device.push_back(a);
			}
			if ((line == "Reallab NL-16HV") || (line == "electropribor PRE-16") || (line == "energyservice EHMB-1-24"))
			{
				Signals* b = new Signals();
				Device.push_back(b);
			}
			if ((line == "Ouman S203") || (line == "Oven TPM232"))
			{
				Warm* c = new  Warm();
				Device.push_back(c);
			}
		}
	}
	fail.close();
	for (int i = 0; i < Device.size(); i++)
	{
		Device[i]->poll();
		cout << endl;
	}
}
