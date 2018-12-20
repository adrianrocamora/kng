class ClassSealer {
private:
	friend class Sealed;
	ClassSealer() {}
};

class Sealed : private virtual ClassSealer {
};

class FailsToDerive : public Sealed {
};

int main()
{
	Sealed seal;
	FailsToDerive failsToDerive;
}
