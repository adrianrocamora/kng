class rule_of_five {
public:
	rule_of_five() = default;
	rule_of_five(const rule_of_five&) = default;
	rule_of_five(rule_of_five&&) = default;
	rule_of_five& operator=(const rule_of_five&) = default;
	rule_of_five& operator=(rule_of_five&&) = default;
	virtual ~rule_of_five() = default;
};

int main() {
	rule_of_five rof;
}
