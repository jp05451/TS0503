#include < iostream >
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
				char firstName[25];
				char lastName[30];
				char phone[15];
} StRec;

class record
{
public:
				string firstName;
				string lastName;
				string phone;

				bool operator==(const record& input)
				{
								return firstName == input.firstName && lastName == input.lastName && phone == input.phone;
				}
};

bool operator==(const record& a,const  record& b)
{
				return a.firstName == b.firstName && a.lastName == b.lastName && a.phone == b.phone;
}

class table
{
public:
				void insert(string firstName__, string lastName__, string phone__);
				void erase(string firstName__, string lastName__, string phone__);
				void print();
				void search(string firstName__, string lastName__, string phone__);
				void check(string command);
private:
				vector<record> sturec;
};

int main()
{
				table stu;
				string command;
				while (cin >> command)
				{
								//cout << command<<" ";
								stu.check(command);
				}
				return 0;
}

bool test(string firstName__, string lastName__, string phone__)
{
				if (firstName__.length() > 25 || lastName__.length() > 30 || phone__.length() > 15)//length check
				{
								cout << "Input Error" << endl;
								return 0;
				}
				for (int i = 0; i < phone__.length(); i++)
				{
								if (!isdigit(phone__[i]))
								{
												cout << "Input Error" << endl;
												return  0;
								}
				}
				return 1;
}

void table ::check(string command)
{
				string firstName, lastName, phone;
								
				if (command == "insert")
				{
								cin >> firstName >> lastName >> phone;
								if (!test(firstName, lastName, phone))
												return ;
								insert(firstName, lastName, phone);

				}
				else if (command == "delete")
				{
								cin >> firstName >> lastName >> phone;
								if (!test(firstName, lastName, phone))
												return;
								erase(firstName, lastName, phone);
				}
				else if (command == "print")
				{
								print();
				}
				else if (command == "search")
				{
								cin >> firstName >> lastName >> phone;
								if (!test(firstName, lastName, phone))
												return;
								search(firstName, lastName, phone);
				}
				else
				{
								cout << "Input Error" << endl;
								return ;
				}
}

void table::insert(string firstName__, string lastName__, string phone__)
{
				if (sturec.size() >= 10)//check the end
								//error::structor.size>10(the number 11 data will come in cuz the size will = 10)
				{
								cout << "Insert Error" << endl;
								return ;
				}
				record temp;
				temp.firstName = firstName__;
				temp.lastName = lastName__;
				temp.phone = phone__;
				for (int i = 0; i < sturec.size(); i++)
				{
								if (temp == sturec[i])
								{
												cout << "Insert Error" << endl;
												return;
								}
				}
				sturec.push_back(temp);
}

void table::erase(string firstName__, string lastName__, string phone__)
{
				record temp;
	
				temp.firstName = firstName__;
				temp.lastName = lastName__;
				temp.phone = phone__;
				vector<record>::iterator index = find(sturec.begin(), sturec.end(), temp);
				if (index != sturec.end())
				{
								sturec.erase(index);
				}
				else
				{
								cout << "Delete Error" << endl;
				}
}

void table::print()
{
				if (!sturec.size() > 0)//check if is not empty
				{
								cout << "Print Error" << endl;
								return;
				}
				for (auto a : sturec)
				{
								cout << a.firstName << " " << a.lastName << " " << a.phone << endl;
				}
}

void table::search(string firstName__, string lastName__, string phone__)
{
				record temp;
				temp.firstName = firstName__;
				temp.lastName = lastName__;
				temp.phone = phone__;

				//find the place
				
				vector<record>::iterator index = find(sturec.begin(), sturec.end(), temp);
				if (index != sturec.end())
				{
								cout <<distance(sturec.begin(),index) << endl;
				}
				else
				{
								cout << "Search Error" << endl;
				}
}
