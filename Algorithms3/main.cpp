//main.cpp

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;
//function prototypes
int inversionCount( vector<int> &list1,
				 	vector<int> &list2);
vector< vector<int> > preference;
void randomizeList(int amount, vector<int> &list);

// vector of vectors

int main()
{
	srand(time(NULL));
	int n = 400; // elements in each vector / amount
	int m = 100;// elements in big vector
	int inversions = -1;

	preference.resize(m);
	//cout<<preference.size();
	for (int i = 0; i < preference.size(); i++)
	{
		//cout<<i;
		randomizeList(n, preference[i]);
		for (int j = 0; j < preference[i].size(); j++)
			cout<< preference[i][j] <<" ";
		cout<<endl;
	}

	// outer for loop
	for(int i = 0; i < preference.size(); i++)
	{
		// inner for loop
		for (int j = 0; j < preference.size(); j++)
		{	
			int temp; // for storing the inversion count for each itteration
			temp = inversionCount(preference[i], preference[j]);
			cout<<"The number of inversions for Preference " << i 
			    << " and Preference "<< j << "  are " << temp<<endl; 
			if (i != j){

				if (inversions = -1)
					inversions = temp;
				if(temp < inversions)
					inversions = temp;
			}
		}
	}
//	cout<<"The lowest number of inversions were "<< inversions;
}


int inversionCount( vector<int> &list1,
					vector<int> &list2)
{
	int inversions = 0;
	for(int i = 0; i < list1.size() - 1; i++)
	{
		for(int j = i + 1; j < list1.size(); j++)
		{
			if( ((list1[i] < list1[j]) && (list2[i] > list2[j])) ||
			  ( ((list1[i] > list1[j]) && (list2[i] < list2[j])) ))
			{
				inversions++;
			}
		}
	}
//	cout<<"The number of inversions for this matchup are "<<inversions<<endl;
	return inversions;
}

void randomizeList(int amount, vector<int> &list)
{
	//cout<<"test";
	int num = 0;
	//temp vector for storing n ordered elements
	vector<int> temp; 

	// sets all elements in said vector to i
	for (int i = 0; i < amount; i++)
	{
		temp.push_back(i + 1);	
	}
	
	while (temp.size() != 0)  //for (int i = 0; i < list.size(); i++)
	{
		num = rand() % temp.size();
		list.push_back(temp[num]);
		temp.erase(temp.begin() + num);		
	}
}









