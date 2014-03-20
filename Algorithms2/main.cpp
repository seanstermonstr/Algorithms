//main.cpp
//Knapsack problem
#include <iostream>
#include <vector>
using namespace std;


// struct knapsack for holding all the values
struct knapsack
{
	int count;
	int value;
	int weight;
};

int LIMIT = 0;

//vector of knapsack structures
vector<knapsack> Knapsack;


void printVector()
{
	for(int i = 0; i < Knapsack.size(); i++)
	{
		cout<<"Element "<< i <<": \n"
			<<"Weight: "<< Knapsack[i].weight << endl
			<<"Value: " << Knapsack[i].value << endl;
	}	
}

bool increaseCounter()
{
	//does the binary counting
	for (int i = 0; i < Knapsack.size(); i++)
	{
		if (Knapsack[i].count == 0)
		{
			Knapsack[i].count = 1;
			return true;
		}
		else 
			Knapsack[i].count = 0;
	}
	return false;
}

void manuallySetValue()
{
	int Item;
	cout<<"How many Items should there be?";
	cin>>Item;
	Knapsack.resize(Item);

	cout<<"What should the weight limit be?\n";
	cin >> LIMIT;

	for (int i = 0; i < Knapsack.size(); i++)
	{
		Knapsack[i].count = 0; // sets the count element to 0
		// gets each element weight
		cout<<"Please enter the weight for item "<< i <<".\n";
		cin>> Knapsack[i].weight;

		// gets each element value
		cout<<"Please enter the value for item "<< i <<".\n";
		cin>> Knapsack[i].value;
	}
	cout<<"The values you entered are... \n";
	printVector();
}


void setValue()
{
	//more initializations and such
	int Item = 5;
	Knapsack.resize(Item);

	for (int i = 0; i < Knapsack.size(); i++)
		Knapsack[i].count = 0;

	Knapsack[0].weight = 1;
	Knapsack[0].value = 1;
	Knapsack[1].weight = 2;
	Knapsack[1].value = 6;
	Knapsack[2].weight = 5;
	Knapsack[2].value = 18;
	Knapsack[3].weight = 6;
	Knapsack[3].value = 22;
	Knapsack[4].weight = 7;
	Knapsack[4].value = 28;

	cout<<"The default values are... \n";
	printVector();
}

int main()
{
	//initializations and such
	int iBestValue = 0;		// for storing the best value of the stuff
	int iCurrentValue = 0;	// for storing the current value of the stuff at any given point
	int iCurrentWeight = 0;	// for storing the current weight of the stuff at any given point
	bool bWeightLimitReached = false;	// indicates if the weight limit has been reached
	char input; // receives input at program start
	bool loop = true;

	cout<<"Would you like to input your own weight/value combonations? [y/n]\n";
	cout<<"If not, the program will take default values.\n";
	while (loop)
	{
		cin>> input;
		switch(input)
		{
			case 'n':
			case 'N':
				setValue(); // init
				loop = false;

				break;
		
			case 'y':
			case 'Y':
		
				manuallySetValue();
				loop = false;

				break;
		
		default:
			cout<<"Invalid input please try again.\n";
		}
	}

	// runs through this loop at least once.
	do{
		// checks 1s and 0s in the vector
		for (int i = 0; Knapsack[i].count < Knapsack.size(); i++)
		{
			// if the vector has a 1
			if (Knapsack[i].count == 1) 
			{
				// the knapsack weight is added to the current
				iCurrentWeight += Knapsack[i].weight;
				// checks if the weight limit has been reached sets var to true
				if(iCurrentWeight > LIMIT)
				{
					bWeightLimitReached = true;
				}
				// knapsack value is added to current
				iCurrentValue += Knapsack[i].value;
			}
			// if the weight limit is reached it breaks out of the for loop
			//if (bWeightLimitReached)
			//	break;
		}

		for (int i = 0; i < Knapsack.size(); i++)
		{
			cout<< Knapsack[i].count <<" ";
		}
		cout<<endl;
		cout<<"The current value is "<< iCurrentValue<<".\n";
		if (bWeightLimitReached)
			cout<<"The weight limit has been reached.\n";
		else 
			cout<<"The weight limit has not been reached.\n";

		// if the for loop is finished and the weight limit has not been reached
		if (!bWeightLimitReached)
		{
			// checks if the current value is greater than the best value so far
			if (iCurrentValue > iBestValue)
			{
				// if so, current replaced best value
				iBestValue = iCurrentValue;
			}
		}

		// current weight and value are reset for next itteration
		iCurrentWeight = 0;
		iCurrentValue = 0;
		bWeightLimitReached = false;

		/*
		for (int i = 0; i < Knapsack.size(); i++)
		{
			cout<<Knapsack[i].count<<" ";
		}
		cout<<endl;
		*/

	}
	// runs through possible combinations
	while(increaseCounter());

	cout<<endl<<endl;
	cout<<"The best value that can be obtained is "<< iBestValue <<".\n";

	return 0;
}
