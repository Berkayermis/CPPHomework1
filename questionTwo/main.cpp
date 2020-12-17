//---------------------------------------------------------------------
//
// Name:    Muhammed Berkay Ermiş
//
// Course:  Programming for Engineering, Fall, 2020
//
// Purpose: General description of what the program does. This should be generate
//          a card array which includes 10 integers itself and functions of this project
//          finds the maximum integer of each card and sorts them in ascending order
//
//---------------------------------------------------------------------

#include <iostream>

using namespace std;

//---------------------------------------------------------------------
//  Function prototypes
//---------------------------------------------------------------------
void sort(int[],int);
void swap(int&,int&);



int main() {

//---------------------------------------------------------------------
//  Some declaration here that include a card array,number of card and
//  a max element array with respect to the number of card
//---------------------------------------------------------------------
    int card[10];
    int numberOfCard;
    cout<<"How many card do you want to have: ";
    cin>>numberOfCard;
    int maxElements[numberOfCard];


//---------------------------------------------------------------------
//  This for loop takes the 10 elements for each card and writes there into the card array
//  After writing those elements,it sorts the card by using sort function and prints the all values
//  After sorting part, nested for loop finds the maximum element of this specific card and add this
//  maximum value into the maxElements array
//  After filling the maxElements array, this array is sorted itself to print the maximum elements
//  in ascending order between the all cards.
//---------------------------------------------------------------------
    for(int i=0; i<numberOfCard; i++){
        cout<<"Enter elements for card "<<i+1<<": "<<endl;
        for(int &k: card){
            cin>>k;
        }


        sort(card,10);   // sorting card itself
        cout<<"Card "<<i+1<<": ";
        for(int l:card){  // prints the card elements
            cout<<l<<" ";
        }
        cout<<endl;


        int max = card[0];  //finding the maximum element in the card
        for (int j=1; j<10; j++){
            if(card[j]>max){
                max = card[j];
            }
        }
        maxElements[i] = max;  //associating the maximum element into the maxElement array
    }

    for(int p=0; p<numberOfCard; p++){  //prints the maximum element for each card itself
        cout<<"Maximum integer is "<<maxElements[p]<<" for card "<<p+1<<endl;
    }
    cout<<endl;

    cout<<"Maximum integers of cards in ascending order by the maximum integers."<<endl;
    sort(maxElements,numberOfCard); //sorting the maxElements array which includes all maximum elements for each card
    for(int x:maxElements){
        cout<<x<<" ";
    }


}

//---------------------------------------------------------------------
//  swap function provides to swap each values by call-by-reference
//---------------------------------------------------------------------
void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

//---------------------------------------------------------------------
//  sort function takes an array and sorts this array with respect to its size
//---------------------------------------------------------------------
void sort(int card[],int n){
    for(int x=0; x<n-1; x++){
        for(int j=x+1; j<n; j++){
            if(card[j]<card[x]) {
                swap(card[x],card[j]);
            }
        }
    }

}
