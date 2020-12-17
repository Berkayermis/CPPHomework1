//---------------------------------------------------------------------
//
// Name:    Muhammed Berkay Ermiş
//
// Course:  Programming for Engineers . 64170024, Fall , 2020
//
// Purpose: The aim of this project is determine an array and its row and column size by user,
//          collect the all elements into the array and sort the elements with respect to the rule which
//          the first row_size/2 row will consist the small values in ascending and the remaining rows
//          will consist the other values in descending order
//
//---------------------------------------------------------------------


#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//----------------------------------------------
//  Function prototypes
//----------------------------------------------
void sort(int* temp,int);
void ascending_descending(int** arr,int* temp,int,int,int);
void swap(int&,int&);
int readValue(ofstream &outfile,int **array,int* temp,int,int,int);
void printArray(int** arr,int,int);
void print_array_of_part(int** arr,int,int,int,int);


//----------------------------------------------
//  Main function includes all scenario by calling the related functions
//----------------------------------------------
int main() {

//----------------------------------------------
// Decleration of the m and n which are going to be the row number and column number respectively
// Those numbers are going to be taken by user
// There are 2 arrays which one is the 2-dimensional array and other one is 1-dimensional temporary array
//----------------------------------------------
    int m,n,count = 0;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    int** A = new int*[(m * n)];
    int temp[m*n];
    for(int i = 0; i <m*n; i++){
        A[i] = new int[m*n];
    }

//----------------------------------------------
//  This part asks the # of row and column to the user and it generates an two array with respect to
//  user's choices. One array consists the all elements in 2D and other one consists the all elements in 1D
//  to be sorted later itself
//----------------------------------------------

    cout << "Enter "<<(m * n)<<" entries: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>A[i][j];
            if(A[i][j]>0 && A[i][j]<95){
                count++;
            }
            else{
                cout<<"Try again"<<endl;
                j--;
            }
        }
    }


    for(int i=0; i<m; i++){
        for(int j=0;j<n;j++){
            int position = i*n + j;
            temp[position] = A[i][j];
        }
    }


//----------------------------------------------
//  The temp array is sorted here with respect to the total array size.
//  ascending_descent function applies the rule inside the A (array)
//  printArray prints the array
//  print_array_of_part prints the array with respect to specific range
//----------------------------------------------
    sort(temp,m*n);
    int firstRow = m/2;
    ascending_descending(A,temp,firstRow,m,n);
    printArray(A,m,n);
    cout<<endl;
    print_array_of_part(A,1,2,2,3);
    cout<<endl;


//-----------------------------------------
//
// Read value part includes an output file and in the readValue function it includes an input file itself
//
//-----------------------------------------
    ofstream ermis_OUT;
    ermis_OUT.open("ermis_OUT.txt");
    readValue(ermis_OUT,A,temp,firstRow,m,n);

// Delete operator deallocates memory from heap.
    for(int p=0; p<m*n; p++){
        delete[] A[p];
    }
    delete[] A;

}
//----------------------------------------------
//  sort function takes the 1D array temp and sorts this array in ascending order
//  with respect to x (array size) which is (m * n) for this project
//----------------------------------------------
void sort(int* temp,int x){
    for(int a=0; a<x-1; a++){
        for(int b=a+1; b<x; b++){
            if(temp[a]>temp[b]){
                swap(temp[a],temp[b]);
            }
        }
    }
}

//----------------------------------------------
//  ascending_descent function takes 5 parameters which are 2D main array (A) , 1D temporary array(temp)
//  firstRow which is row size / 2 to perform the project rule, rowSize and columnSize.
//  This function generates the 2D array according to the 1D temp array and it is seperated as
//  ascending order and descending order
//----------------------------------------------
void ascending_descending(int** A,int* temp,int firstRow,int rowSize,int columnSize){
    int index = 0;
    //ascending order part
    for(int i=0; i<firstRow; i++){
        for(int j=0; j<columnSize; j++){
            A[i][j] = temp[index];
            index++;
        }
    }
    //descending order part
    for(int a=rowSize-1; a>firstRow-1; a--){
        for(int b=columnSize-1; b>=0; b--){
            A[a][b] = temp[index];
            index++;
        }
    }
}

//----------------------------------------------
//  swap function takes the 2 call-by-reference values to swap them inside the array
//----------------------------------------------
void swap(int& a, int& b){
    int  temp = a;
    a = b;
    b = temp;
}

//----------------------------------------------
//  printArray function prints the 2D array
//----------------------------------------------
void printArray(int** A,int m,int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//----------------------------------------------
//  readValue function finds the input file which is the berkay_IN.txt in this case and it has some
//  condition to read this input file and write the content of this input file into the output file.
//  It checks the each line of this input file and checks the value in there whether it is between
//  0 and 95 but value is valid it adds the value into the array from the file and write the some statements
//  in the output file with outfile.
//  If the column size reaches the array column size which will be defined in the main function and size
//  is not equal the total array size,it augments the sizeRow by 1 and equalize the sizeColm to zero to
//  start from beginning.
//  After write the datas into the array, it fills the 1D temp array with the elements of 2D array and sort it.
//  After sorting part,ascending and descending order parts are generated again to apply the rule of this project
//----------------------------------------------
int readValue(ofstream &outfile,int **array,int* temp,int firstRow,int m,int n)
{

    ifstream berkay_IN("berkay_IN.txt");
    int size = 0;
    int sizeRow = 0,sizeColm = 0;
    //reading the output file
    if (berkay_IN.is_open())
    {
        string line;
        while ( getline (berkay_IN,line) )
        {
            stringstream geek(line);
            int value = 0;
            geek >> value;
            if(value>0 && value<95) //condition for valid numbers
                {
                array[sizeRow][sizeColm] = value;
                size++;
                outfile<<" the value "<<value<<" is added\n";
                if(sizeColm!=n && size!=(m*n)){
                    sizeColm++;
                }
                if(sizeColm==n && size!=(m*n)){
                    sizeRow++;
                    sizeColm = 0;
                }
                }
            else
                {
                outfile<<" the value "<<value<<" is not between 0 and 95\n"; //if the number is not in the range
                }
        }

        for(int i=0; i<m; i++){
            for(int j=0;j<n;j++){
                int position = i*n + j;
                temp[position] = array[i][j];
            }
        }
        sort(temp,size);
        ascending_descending(array,temp,firstRow,m,n);

        outfile<<"-----------------------------RESULT-----------------------------\n";
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                outfile<<array[i][j]<<" ";
            }
            outfile<<endl;
        }
    }
        berkay_IN.close();

    return size+1;
}


//----------------------------------------------
//  print_array_of_part function takes the starting row and column points and ending row and column points
//  to print that range
//----------------------------------------------
void print_array_of_part(int** A,int r1,int r2,int c1,int c2){
    cout<<"Show the array elements between "<<r1<<"-"<<r2<<" rows and "
    <<c1<<"-"<<c2<<" columns"<<endl;
    if(r1<=r2 && c1<=c2){
        for(int i=r1; i<r2+1; i++){
            for(int j=c1; j<c2+1; j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}