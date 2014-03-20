// next_permutation.cpp
// compile with: /EHsc
// Illustrates how to use the next_permutation function.
//
// Functions:
//    next_permutation : Change the order of the sequence to the
//                       next lexicograhic permutation.

// disable warning C4786: symbol greater than 255 character,
// okay to ignore
//#pragma warning(disable: 4786)
//
//
//  i)  123
//      132
//      213
//      231
//      321
//      312
//
//      312 is the order that minimises completion time
//
//  ii) see program below
//
//  iii) The order should be greatest to least in terms of the biking time plus the running time
//
//
//  iv)  Greedy Algorithm Proof
//
//  by swapping i and j i am proving the following
//  the max of i and j after the swap is less than or equal to the max of i and j before the swap
// 
//  Bi, j = biking time of i and j
//  Ri, j = running time of i and j 
//  Ti, j = time of i and j
//  ' = after the swap
//
//
//  Greedy Algorithm: Bi + Ri < Bj + Rj
//
//  [...n...] [i] [j] [...m...] before swap
//
//  [...n...] [j] [i] [...m...] after swap
//  
//  max(Ti', Tj') <= max(Ti, Tj)
//
//  case: Ti' > Tj'
//      Ti' <= max(Ti, Tj)
//      Sn + Sj + Si + Bi + Ri <= max(Ti,Tj)
//      Sn + Sj + Si + Bi + Ri <= Tj
//      Sn + Sj + Si + Bi + Ri <= Sn + Si + Sj + Bj + Rj
//      
//      Bi + Ri <= Bj + Rj (By greedy algorithm this is true).
//
//  case: Tj' > Ti'
//      Tj' <= max(Ti, Tj)
//      Sn + Sj + Bj + Rj <= max(Ti, Tj)
//      Sn + Sj + Bj + Rj <= Tj
//      Sn + Sj + Bj + Rj <= Sn + Si + Sj + Bi + Ri
//      
//      Bj + Rj <= Si + Bi + Ri  (By greedy algorithm this is true)
//      
//
//  case: Tj > Ti
//      Sn + Si + Sj + Bj + Rj > Sn + Si + Bi + Ri
//      Sj + Bj + Rj > Bi + Ri
//       => Sj + Bj + Rj > Bj + Rj
//       Bj + Rj > Bi + Ri (By greedy algortihm this is true).
//
//
//


// ii)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std ;

struct people
{
    int iID;
    int iBike;
    int iSwim;
    int iRun;
};

void init(vector<people> &people);
void printStruct(vector<people>::iterator *person);


const int VECTOR_SIZE = 10 ;

// Define a template class vector of strings
typedef vector<people> peopleVector ;

//Define an iterator for template class vector of strings
typedef peopleVector::iterator peopleVectorIt ;

vector<int> ID;

/*
void printStruct(vector<people>::iterator *person)
//ostream &operator<<(ostream &os, const people &person)
{
    cout<<"person" << person.iID << ":\n"
        << "Swimming: "<< person.iSwim << endl
        << "Biking: " << person.iBike << endl
        << "Running: " << person.iRun << endl;
    //return os;
}
*/

void init(vector<people> &people)
{
    people.resize(VECTOR_SIZE);
    
    people[0].iID = 1; people[0].iSwim = 20; people[0].iBike = 25; people[0].iRun = 20;
    people[1].iID = 2; people[1].iSwim = 35; people[1].iBike = 20; people[1].iRun = 15;
    people[2].iID = 3; people[2].iSwim = 40; people[2].iBike = 20; people[2].iRun = 30;
    people[3].iID = 4; people[3].iSwim = 25; people[3].iBike = 30; people[3].iRun = 25;
    people[4].iID = 5; people[4].iSwim = 22; people[4].iBike = 27; people[4].iRun = 18;
    people[5].iID = 6; people[5].iSwim = 37; people[5].iBike = 18; people[5].iRun = 17;
    people[6].iID = 7; people[6].iSwim = 42; people[6].iBike = 22; people[6].iRun = 28;
    people[7].iID = 8; people[7].iSwim = 27; people[7].iBike = 32; people[7].iRun = 24;
    people[8].iID = 9; people[8].iSwim = 31; people[8].iBike = 16; people[8].iRun = 18;
    people[9].iID = 10; people[9].iSwim = 36; people[9].iBike = 24; people[9].iRun = 26;

    for (int i = 0; i < VECTOR_SIZE; i++)
        ID.push_back(i);
    

    
   // printStruct(people[0]);
}


int main()
{

 

    peopleVector Pattern(VECTOR_SIZE) ;

    vector<int>:: iterator start, end, it ;
    init(Pattern);

    start = ID.begin() ;   // location of first
                                // element of Pattern

    end = ID.end() ;       // one past the location last
                                // element of Pattern

    //init(Pattern);


    cout << "\n\n" ;

    // Generate all possible permutations
    vector <int> fastest, temp; fastest.resize(VECTOR_SIZE);
    int iMemberTime = 0, Swim = 0, iBestTime = -1, iTeamTime = 0;

    cout<<"before calling next permutation.\n"<<endl;
    for (it = start; it != end; it++)
    {
        cout<<*it;

        Swim += Pattern[*it].iSwim;
        iMemberTime = Swim + Pattern[*it].iBike + Pattern[*it].iRun;

        if ( iTeamTime < iMemberTime )
        {
            iTeamTime = iMemberTime;
            iBestTime = iTeamTime;
        }

    }
    iTeamTime = 0;
    cout<<endl;

    cout << "After calling next_permutation:" << endl ;
    while ( next_permutation(start, end) )
    {
       	for(it = start; it != end; it++)
        {
 //cout<< Pattern[*it].iID;
           /* 
            temp.iID = Pattern[*it].iID;
            temp.iSwim = Pattern[*it].iSwim;
            temp.iBike = Pattern[*it].iBike;
            temp.iRun = Pattern[*it].iRun;
            */
            Swim += Pattern[*it].iSwim;
            iMemberTime = Swim + Pattern[*it].iBike + Pattern[*it].iRun;
            
            if (iTeamTime < iMemberTime)
            {
                iTeamTime = iMemberTime;
            }
        }

        if (iTeamTime < iBestTime)
        {
            iBestTime = iTeamTime;
            for (it = start; it != end; it++)
            {
                fastest[*it] = ID[*it];
            }
        }
 
        iTeamTime = 0;
        Swim = 0;

       // cout << endl ;
    }

    cout<<"The best time is: "<< iBestTime<<endl;
    cout<<"The best permutation is: ";
    for(int i = 0; i < fastest.size(); i++)
        cout<<fastest[i];
    cout<<".\n";

    return 0;
}
