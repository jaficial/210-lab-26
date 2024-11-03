// COMSC-210 | Lab 26 | Jed Aficial
// github link: https://github.com/jaficial/210-lab-26

#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <algorithm> // used for "sort()"

using namespace std;
using namespace std::chrono;

const string TEST_CODE = "TESTCODE";
const int TYPES = 3;
const int TRIALS = 15;
const int RESULTS = 4;
const int FILE_SIZE = 20000;

/* first need to rewrite code into 2d array, then will be able to have 3d array to store data averages
      - first cube of array will represent the 3 tests (size of 3)
        - 0 = vector, 1 = list, 2 = sets
      - second cube of array will represent 15 trials for each of the 3 types (size of 45 total elements? )
      - third cube of array will hold the average of each set of trials (size of 4)
        - 0 = read, 1 = sort, 2 = insert, 3 = delete
*/

// currently rewriting my code to organize it in loops, and to achieve repeatability
int main() {
    // COLLECTING DATA FOR VECTORS
    int data_results[TYPES][TRIALS][RESULTS];
    string temp_string;

    // main for loop
    for (int i = 0; i < TYPES; i++){
        if (i == 0){ // if i == 0, which represents the vector
            for (int j = 0; j < TRIALS; j++){ // trials for each type
                vector<string> vector_example;
                ifstream fin("codes.txt");
                auto start = chrono::high_resolution_clock::now();

                for (int k = 0; k < FILE_SIZE; k++){ // reading into the file
                    getline(vector_example, temp_string);
                    vector_example.push_back(temp_string);
                }
                auto end = chrono::high_resolution_clock::now();
                auto vector_example_read = duration_cast<microseconds>(end - start);
                data_results[0][j][0] = vector_example_read.count(); 
                fin.close();

                // divider (erase later) ------------------------
                // sorting the vector
                start = chrono::high_resolution_clock::now();
                sort(vector_example.begin(), vector_example.end());
                end = chrono::high_resolution_clock::now();
                auto vector_example_sort = duration_cast<microseconds>(end - start);
                data_results[0][j][1];

                // divider (erase later) ------------------------
                // inserting into the vector
                start = chrono::high_resolution_clock::now();
                int vector_midpoint = vector_example.size() / 2;
                vector_example
            }
        }
        
    }


    // inserting "TESTCODE" into the middle of the vector
    int vector_midpoint = vector_example.size();
    vector_midpoint = (vector_midpoint / 2) - 1; // -1 since range is between 0-19999
    
    start = chrono::high_resolution_clock::now();
    vector_example.insert(vector_example.begin() + vector_midpoint, TEST_CODE);
    end = chrono::high_resolution_clock::now();
    auto vector_example_insert = duration_cast<microseconds>(end - start);

    // deleting the middle element from the vector
    start = chrono::high_resolution_clock::now();
    vector_example.erase(vector_example.begin() + vector_midpoint); // CITED from https://cplusplus.com/reference/vector/vector/erase/ to learn how to use ".erase()" function
    end = chrono::high_resolution_clock::now();
    auto vector_example_delete = duration_cast<microseconds>(end - start);

    // beginning collecting data for LISTS
    ifstream fin_list("codes.txt");
    list<string> list_example;

    // reading the file into the list
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 20000; i++){
        getline(fin_list, temp_string);
        list_example.push_back(temp_string);
    }
    end = chrono::high_resolution_clock::now();
    auto list_example_read = duration_cast<microseconds>(end - start);
    fin_list.close();

    // sorting the list
    start = chrono::high_resolution_clock::now();
    list_example.sort();
    end = chrono::high_resolution_clock::now();
    auto list_example_sort = duration_cast<microseconds>(end - start);

    // inserting "TESTCODE" into the middle of the list
    int list_midpoint = list_example.size();
    list_midpoint = list_midpoint / 2; // should be equal to 10000
    auto list_iter = list_example.begin(); // iterator to the beginning of the list
    for (int i = 0; i <= list_midpoint; i++){ 
        list_iter++; // traversing through the list, iterating with each iteration
    }

    start = chrono::high_resolution_clock::now(); 
    list_example.insert(list_iter, TEST_CODE); // inserts TEST_CODE at index list_iter - 1, which should be 10000 - 1 == 9999
    end = chrono::high_resolution_clock::now();
    auto list_example_insert = duration_cast<microseconds>(end - start);

    // deleting the middle element
    list_iter--; // since list.erase(iter) erases the element at the iter index, we need to delete the element at index 9999
    start = chrono::high_resolution_clock::now();
    list_example.erase(list_iter); // NOTE: .erase() takes in the iter of the element to be deleted as the parameter
    end = chrono::high_resolution_clock::now();
    auto list_example_delete = duration_cast<microseconds>(end - start);

    // beginning collecting data for SETS
    ifstream fin_set("codes.txt");
    set<string> set_example;
    // reading the file into the set
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 20000; i++){
        getline(fin_set, temp_string);
        set_example.insert(temp_string);
    }
    end = chrono::high_resolution_clock::now();
    auto set_example_read = duration_cast<microseconds>(end - start);
    fin_set.close();

    // sorting the set
    int set_example_sort = -1; // Sets are already sorted

    // Inserting "TESTCODE" into the middle of the set
    auto set_iter = set_example.begin(); // need to receive iterator starting at the beginning of the set, similar to lists
    int set_midpoint = set_example.size(); 
    set_midpoint = set_midpoint / 2;

    for(int i = 0; i < set_midpoint; i++){ // iterate through set, similar to how we must iterate through the list previously
        set_iter++;
    }
    start = chrono::high_resolution_clock::now();
    set_example.insert(set_iter, TEST_CODE); // .insert(iter(index), value of element to store)
    end = chrono::high_resolution_clock::now();
    auto set_example_insert = duration_cast<microseconds>(end - start);

    // Deleting the middle element of a set
    start = chrono::high_resolution_clock::now();
    set_example.erase(set_iter);
    end = chrono::high_resolution_clock::now();
    auto set_example_delete = duration_cast<microseconds>(end - start);
    
    // output of the data
    cout << setw(10) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    cout << setw(10) << "Read" << setw(10) << vector_example_read.count() << setw(10) << list_example_read.count() << setw(10) << set_example_read.count() << endl;
    cout << setw(10) << "Sort" << setw(10) << vector_example_sort.count() << setw(10) << list_example_sort.count() << setw(10) << set_example_sort << endl;
    cout << setw(10) << "Insert" << setw(10) << vector_example_insert.count() << setw(10) << list_example_insert.count() << setw(10) << set_example_insert.count() << endl;
    cout << setw(10) << "Delete" << setw(10) << vector_example_delete.count() << setw(10) << list_example_delete.count() << setw(10) << set_example_delete.count() << endl;

    return 0;
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
