#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &vec){
    
    for(int k=1; k<vec.size(); k++){//select index of key(starting from the second element)
        int key = vec[k]; //record key
        int cmp = k - 1; //compare with all elements before key
        while(cmp >= 0 && vec[cmp] > key){ //if not out of range and element is larger than key
            vec[cmp+1] = vec[cmp]; //move this element backwards
            cmp--; //continue comparing with the previous element
        }
        /*the loop would be broken in either of the following cases:
         (1)out-of-range problem: key is smaller than all the other elements before it
         ->insert key into the front
         (2)the element compared is smaller->insert key into the position behind that element
         */
        vec[cmp+1] = key;
    }
}

int main(){
    
    vector<int> vec;
    const string inputFile = "input.txt";
    const string outputFile = "output.txt";

    //=====Read Input Sequence=====
    ifstream ReadFile(inputFile, ios::in);//declare input file
    //check if file exists
    if(!ReadFile.is_open()){
        cerr << "Input File not found.";
        exit(1);
    }
    
    int n = 0; //save how many numbers to sort
    ReadFile >> n; //read first line(numbers to sort)
    for(int i=0; i<n; i++){ //read the numbers and save them into vec
        int x;
        ReadFile >> x;
        vec.push_back(x);
    }
        
    //=====Do Quick Sort=====
    InsertionSort(vec);
    //=======================
    
    //=====Output Sorted Sequence=====
    ofstream WriteFile(outputFile, ios::out | ios::trunc);//declare output file
    //check if file exists
    if(!WriteFile.is_open()){
        cerr << "Output File not found.";
        exit(1);
    }

    WriteFile << n << '\n'; //write first line(total numbers)
    for(int i=0; i<n; i++){ //read the sorted numbers in vector and write into file
        WriteFile << vec[i] << '\n';
    }
    
    return 0;
}

