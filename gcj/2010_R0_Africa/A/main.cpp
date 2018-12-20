#include <stdio.h> 
#include <algorithm> 
using namespace std;

const int MAX_I = 2000;

struct Item 
{
	int price;
	int id;
};

bool compare(Item lhs, Item rhs) { return lhs.price < rhs.price;}

int main()
{
	int numEntries = 0;

	int credit; 
	Item items[MAX_I];

	int numItems;

	int idS;
	int idL;

	// The answer is 2 numbers
	// smaller number first!!!

	scanf("%d", &numEntries);
	for(int i = 0; i < numEntries; i++) {
		scanf("%d", &credit);
		scanf("%d", &numItems);
		for(int j = 0; j < numItems; j++) {
			items[j].id = j+1;
			scanf("%d", &items[j].price);
		}


		// Sort the list by ascending prices(opt)
		//sort(items, items+numItems, compare);

		// Find the index for which a price surpasses the credit 
		// and make this the maximum index to use(opt)
		//find_if();

		// brute force
		for(int j = 0; j < numItems; j++) {
			for(int k = j+1; k < numItems; k++) {
				if (items[j].price + items[k].price == credit) {
					idS = items[j].id;
					idL = items[k].id;
					break;
				}
			}
		}

		// Output
		printf("Case #%d: %d %d\n", 
				i+1, 
				idS,
				idL
				);
	}


	return 0;
}
