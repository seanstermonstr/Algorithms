#include <iostream>
#include <vector>
using namespace std;

struct items{
    int ID;
    int value;
    int weight;
};

vector<items> itemList;
vector<int> knapSack;
vector<int> tempKnapSack;
int iMaxValue;
vector< vector<int> > map;

//int MAX_WEIGHT = 11;
//int ITEMS = 5;

void init();
//void printVector();
int opt(int n, int weight);

int main()
{

    int iCapacity = 0;
    int iTempWeight = 0;
    int iTempValue = 0;
    int iNumItems = 0;    
    char input;

    // gives the option of manual initilization etc.
    cout<<"Would you like to enter values maually?\n";
    cin>> input;
    if ( input == 'n' )
        init();
    else{
        cout << "How many items are there?\n";
        cin >> iNumItems;
        itemList.resize(iNumItems);
        
        cout << "What is the max capacity of the item sack?\n";
        cin >> iCapacity;

        map.resize( iNumItems + 1 );
    

        // Initializes the vector of vectors so the first row and column are initialized to zero and everything else is -1
        for ( int i = 0; i < iNumItems; i++ )
        {
            map[i].resize(iCapacity + i);
            for ( int j = 0; j <= iCapacity; j++ )
            {
                if ( i == 0 || j == 0)
                    map[i][j] = 0;
                else map[i][i] = -1;
            }
            cout << endl;
        }

        for ( int i = 0; i < iNumItems; i++ )
        {
            cout << "Item " << i << " value: ";
            cin >> iTempValue;
            itemList[i].value = iTempValue;

            cout << "Item " << i << " weight: ";
            cin >> iTempWeight;
            itemList[i].weight = iTempWeight;

            itemList[i].ID = i;
        }
    }

    iMaxValue = opt(iNumItems, iCapacity);

    cout << "The max value is: " << iMaxValue << endl
         << "The chosen items are: ";
    for ( int i = 0; i < knapSack.size(); i++ )
        cout << knapSack[i] << " ";

    char x;
    cin >> x;
    return 0;
}

/*
void printVector()
{
	for(int i = 0; i < Knapsack.size(); i++)
	{
		cout<<"Element "<< i <<": \n"
			<<"Weight: "<< Knapsack[i].weight << endl
			<<"Value: " << Knapsack[i].value << endl;
	}		
}
*/

void init()
{/*
    itemList.resize(MAX_WEIGHT + 1);
    for (int i = 0; i < ; i++)
    {
        itemList[i].push_back(-1);
    }
    
	//more initializations and such
	knapSack.resize(ITEMS);

	for (int i = 0; i < itemList.size(); i++)
		knapSack[i].count = 0;

	itemList[0].weight = 1;
	itemList[0].value = 1;
	itemList[1].weight = 2;
	itemList[1].value = 6;
	itemList[2].weight = 5;
	itemList[2].value = 18;
	itemList[3].weight = 6;
	itemList[3].value = 22;
	itemList[4].weight = 7;
	itemList[4].value = 28;

	cout<<"The default values are... \n";
	printVector();
    */
}

int opt(int n, int weight)
{
   
    if ( n == 0 || weight == 0 )
        return 0;
    else if ( itemList[n - 1].weight > weight )
        opt(n - 1, weight);
    else if ( itemList[n - 1].weight <= weight )
    {
        int iVal1 = 0;
        int iVal2 = 0;
        int iTestMax = 0;

        if (map[n - 1][weight] == -1)
        {
            iVal1 = opt( n - 1, weight );
            map[n - 1][weight] = iVal1;
        }
        else iVal1 = map[n - 1][weight];

        tempKnapSack.clear();
        // saves the past calculations into the map
        if ( map[n - 1][weight - itemList[n - 1].weight] == -1 )
        {
            iVal2 = itemList[n - 1].value + opt(n - 1, weight - itemList[n - 1].weight);
            map[n  - 1][weight - itemList[n - 1].weight] = iVal2;
        }
        else iVal2 = itemList[n - 1].value + map[n - 1][weight - itemList[n - 1].weight];

        tempKnapSack.push_back(itemList[n - 1].ID);

        for ( int i = 0; i < tempKnapSack.size(); i++)
            iTestMax += itemList[tempKnapSack[i] - 1].value;
        if ( iTestMax > iMaxValue )
        {
            iMaxValue = iTestMax;
            knapSack.clear();
            for ( int i = 0; i < tempKnapSack.size(); i++ )
                knapSack.push_back(tempKnapSack[i]);
        }

        //Last check to find the max 
        if ( iVal1 > iVal2)
            return iVal1;
        else return iVal2;
    }
}
