class ClassSealer {
private:
	friend class Sealed;
	ClassSealer() {}
};

class Sealed : private virtual ClassSealer{
};

//class Sealed final{
//};

class FailsToDerive : public Sealed{
};

int main() {
	Sealed sealedObject;
	FailsToDerive failingObject;
}
