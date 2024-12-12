class Marker {
public: // access modifier
	enum Color {
		RED = 31, GREEN = 32, BLACK = 30, PINK = 35
	};

	const int MAX_BUFF = 100;
	Color color;
	int capacity; // max count of chars
	int num_chars; // current count of chars
	char* buff; // text
	
	Marker();
	~Marker();
	void erase();
	bool write(char c);
	void see();
};
