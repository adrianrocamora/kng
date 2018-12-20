class String{
public:
	//String(int n) {};	// allocate n bytes to the String object
	explicit String(int n) {};	// allocate n bytes to the String object
	String(const char *p){};	//initializes object with char *p
};

int main() {
	// The char 'x' will be explicitly converted to int and then will call the String(int) constructor.
	// This might not be what the developer intended. To prevent this we define the constructor as explicit
	String mystring = 'x';
}
