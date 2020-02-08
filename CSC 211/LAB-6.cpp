#include <iostream>
#include <string>
using namespace std;

class birthday {
public:
	birthday();
	birthday(int);
	int getamt() { return amt; }
	birthday(const birthday&);
	birthday & operator =(const birthday &);
	void display(int);
	~birthday();
private:
	string * name;
	int *mth, *day;
	int amt;
	
};
int main()
{
	birthday obj1, obj2(0);
	cout << endl;
	cout << "object 1: " << endl;
	obj1.display(1);
	cout << '\n' << endl;
	cout << "object 2: " << endl;
	obj2.display(1);
	
}
birthday::birthday() {
	cout << "How many friends do you have?: " << endl;
	cin >> amt;
	name = new string[amt];
	mth = new int[amt];
	day = new int[amt];
	cout << "Type the info of each friend in the format (name/month number/day):" << endl;
	for (int i = 0; i < amt; i++) {
		cin >> name[i] >> mth[i] >> day[i];
	}
}
birthday::birthday(int num) {
	amt = num;
	name = NULL;
	mth = NULL;
	day = NULL;
}

birthday::birthday(const birthday & obj)
{
	amt = obj.amt;
	name = new string[amt];
	day = new int[amt];
	mth = new int[amt];
	for (int i = 0; i < amt; i++) {
		name[i] = obj.name[i];
		day[i] = obj.day[i];
		mth[i] = obj.mth[i];
	}
}
birthday & birthday::operator=(const birthday & rhs){
	amt = rhs.amt;
	name = new string[amt];
	day = new int[amt];
	mth = new int[amt];
	for (int i = 0; i < amt; i++) {
		name[i] = rhs.name[i];
		day[i] = rhs.day[i];
		mth[i] = rhs.mth[i];
	}
	return * this;
}

void birthday::display(int num) {
	bool  birth = false; //when loops find someone in the array that has a birthday in that month, the boolean switches to true.
	cout << "birthdays in month " << num << endl;
	for (int i = 0; i < amt; i++) {
		if (mth[i] == num) {
			cout << name[i] << " on day " << day[i] << endl;
			birth = true;
		}
	}
	if (birth == false || amt == 0) {
		cout << "None this month" << endl;
	}
}
birthday::~birthday() {
	delete[] name;
	delete[] mth;
	delete[] day;
}