class Animal {
public:
	virtual void move() = 0;
	virtual void say() = 0;
};

#include <iostream>
class Rabbit : public Animal {
public:
	virtual void move() override {
		std::cout << "jump\n";
	}
	
	virtual void say() override {
		std::cout << "fff\n";
	}
};

class Bird : public Animal {
	virtual void move() override {
		std::cout << "fly";
	}
};

class Sparrow : public Bird {
	void say() override final {
		std::cout << "chirp";
	}
};

class Linux : public Bird {
	void say() override final {
		std::cout << "Pi";
	}
	void move() override final {
		std::cout << "rolling & fun";
	}
};

int main(){
	std::cout << "=Happy Animal=\n";
	int choice;
	std::cout << "your choice: \n\t1. Rabbit,\n\t2. Sparrow,\n\t3. Pingi Linux\nChoice: ";
	std::cin >> choice;
	
	Animal* an = new Bird;
	switch (choice) 
	{
		/*case 1:
			an = new Rabbit;
		break;*/
		case 2:
			an = new Sparrow;
		break;
		case 3:
			an = new Linux;
		break;
		default:
			an = new Rabbit;
		break;
	}
	
	while(1) {
		an->say();
		an->move();
	}
}
