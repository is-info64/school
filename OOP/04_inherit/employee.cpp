#include <iostream>
#include <string>

class Employee {
public:
		Employee() { }
		
		Employee(std::string name, std::string dept)
			: name_(name), dept_(dept) { }
			
		void show_info() const {
			std::cout << "Employee: " << name_ << " " << dept_ << "\n";
		}
protected:
	std::string name_;
	std::string dept_;
};

class Manager : public Employee {
public:
	Manager(std::string name, std::string dept, int level) 
		: Employee(name, dept), level_(level) { }
	void show_info() const {
		std::cout << "Manager: " << "\n\t";
		Employee::show_info();
		std::cout << "\t\tlevel: " << level_ <<"\n";
	}
private:
	int level_;
};

int main () {
	Employee e_max("Maximus", "Storage");
	Manager e_yra("Yra", "Storage", 5);
	Employee e_yana("Yana", "Sale");
	//e_max.show_info();
	//e_yra.show_info();
	//e_yana.show_info();

	Employee emps[] = {e_max, e_yra, e_yana};
	for(int i = 0; i < 3; ++i) {
		emps[i].show_info();
	}
}
