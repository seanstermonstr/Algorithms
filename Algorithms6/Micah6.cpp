#include <iostream>
#include <vector>

using namespace std;

int Opt(int n, int weight);

struct items{
	int weight;
	int value;
	int ID;
};

	vector<items> itemList;
	vector<int> knapSack;
	vector<int> tempKnapSack;
	int maxValue = 0;
	vector<vector<int>> map;

int main()
{
	int capacity = 0;
	int tempWeight = 0;
	int tempValue = 0;
	int numItems = 0;


	//Initializes the number of items the user can choose from.
	cout << "How many items are there: ";
	cin >> numItems;
	itemList.resize(numItems);

	//Initializes the capcity of the knap sack
	cout << "What is the maximum capacity of the knap sack: ";
	cin >> capacity;

	map.resize(numItems+1);
	//Initializes the ixw array so that the first row and column are initialized to 0 while every other entry is -1. 
	for (int i=0; i<=numItems; i++)
	{
		map[i].resize(capacity+1);
		for (int j=0; j<=capacity; j++)
		{
			if (i == 0 || j == 0)
				map[i][j] = 0;
			else
				map[i][j] = -1;
			cout << "(" << i << "," << j << ") ";
		}
		cout << endl;
	}

	//Initializes the items value and weight
	for (int i=0; i<numItems; i++)
	{
		cout << "Item " << i+1 << " value: ";
		cin >> tempValue;
		itemList[i].value = tempValue;

		cout << "Item " << i+1 << " weight: ";
		cin >> tempWeight;
		itemList[i].weight = tempWeight;

		itemList[i].ID = i+1;
	}

	maxValue = Opt(numItems, capacity);	//Callin the Opt function

	cout << "The maximum value is: " << maxValue << endl;
	cout << "The items choosen are: ";
	for (int i=0; i<knapSack.size(); i++)
	{
		cout << knapSack[i] << " ";
	}

	char x;
	cin >> x;
	return 0;
}

int Opt(int n, int weight)
{
	//Case 1: Wi > W			
	if (n == 0 || weight == 0)
		return 0;

	else if (itemList[n-1].weight > weight)
		Opt(n-1, weight);

	else if (itemList[n-1].weight <= weight)
	{
		int val1 = 0;
		int val2 = 0;

		int testMax = 0;

		//Memorizes past calculations in a NxW map
		if (map[n-1][weight] == -1)
		{
			val1 = Opt(n-1, weight);
			map[n-1][weight] = val1;
		}
		else 
			val1 = map[n-1][weight];

		tempKnapSack.clear();
		//Memorizes past calculations in a NxW map
		if (map[n-1][weight - itemList[n-1].weight] == -1)
		{
			val2 = itemList[n-1].value + Opt(n-1, weight - itemList[n-1].weight);
			map[n-1][weight - itemList[n-1].weight] = val2;
		}
		else
			val2 = itemList[n-1].value + map[n-1][weight - itemList[n-1].weight];

		tempKnapSack.push_back(itemList[n-1].ID);
		
		for (int i=0; i<tempKnapSack.size(); i++)
			testMax += itemList[tempKnapSack[i]-1].value;
		if (testMax > maxValue)
		{
			maxValue = testMax;
			knapSack.clear();
			for (int i=0; i<tempKnapSack.size(); i++)
				knapSack.push_back(tempKnapSack[i]);
		}

		//Checks to find the max between (Opt(i-1, w), Opt(i-1, w-wi)
		if (val1 > val2)
			return val1;		
		else
			return val2;
	}
}
