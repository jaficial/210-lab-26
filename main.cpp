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
    int data_results[TYPES][16][RESULTS];
    string temp_string;

    // main for loop
    for (int i = 0; i < TYPES; i++){
        if (i == 0){ // if i == 0, which represents the vector sets of data
            for (int j = 0; j < TRIALS; j++){ // trials for each type
                vector<string> vector_example;
                ifstream fin("codes.txt");
                auto start = chrono::high_resolution_clock::now();

                for (int k = 0; k < FILE_SIZE; k++){ // reading the file into the vector
                    getline(fin, temp_string);
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
                data_results[0][j][1] = vector_example_sort.count();

                // divider (erase later) ------------------------
                // inserting into the vector
                int vector_midpoint = vector_example.size() / 2;
                start = chrono::high_resolution_clock::now();
                vector_example.insert(vector_example.begin() + vector_midpoint, TEST_CODE);
                end = chrono::high_resolution_clock::now();
                auto vector_example_insert = duration_cast<microseconds>(end - start);
                data_results[0][j][2] = vector_example_insert.count();

                // divider (erase later) ------------------------
                // deleting the middle element
                start = chrono::high_resolution_clock::now();
                vector_example.erase(vector_example.begin() + vector_midpoint);
                end = chrono::high_resolution_clock::now();
                auto vector_example_delete = duration_cast<microseconds>(end - start);
                data_results[0][j][3] = vector_example_delete.count();
            }
        }

        if (i == 1) { // if i == 1, which represents the list sets of data
            for (int j = 0; j < TRIALS; j++){
                list<string> list_example;
                ifstream fin("codes.txt");
                auto start = chrono::high_resolution_clock::now();

                for (int k = 0; k < FILE_SIZE; k++){ // reading the file into the list
                    getline(fin, temp_string);
                    list_example.push_back(temp_string);
                }
                auto end = chrono::high_resolution_clock::now();
                auto list_example_read = duration_cast<microseconds>(end - start);
                fin.close();
                data_results[1][j][0] = list_example_read.count();

                // divider (erase later) ---------------------------
                // sorting the list
                start = chrono::high_resolution_clock::now();
                list_example.sort();
                end = chrono::high_resolution_clock::now();
                auto list_example_sort = duration_cast<microseconds>(end - start);
                data_results[1][j][1] = list_example_sort.count();

                // divider (erase later) -----------------------------
                // inserting into the list
                int list_midpoint = list_example.size() / 2;
                start = chrono::high_resolution_clock::now();
                auto list_iter_ins = list_example.begin();
                for (int iter = 0; iter < list_midpoint; iter++){
                    list_iter_ins++;
                }

                list_example.insert(list_iter_ins, TEST_CODE);
                end = chrono::high_resolution_clock::now();
                auto list_example_insert = duration_cast<microseconds>(end - start);
                data_results[1][j][2] = list_example_insert.count();

                // divider (erase later) -----------------------------
                // deleteing from the list
                start = chrono::high_resolution_clock::now();
                auto list_iter_del = list_example.begin();
                for (int iter = 0; iter < list_midpoint; iter++){
                    list_iter_del++;
                }

                list_example.erase(list_iter_del);
                end = chrono::high_resolution_clock::now();
                auto list_example_delete = duration_cast<microseconds>(end - start);
                data_results[1][j][3] = list_example_delete.count();


            }
        }
        if (i == 2) { // if i == 2, which represents the set sets of data
            for (int j = 0; j < TRIALS; j++){
                set<string> set_example;
                ifstream fin("codes.txt");
                auto start = chrono::high_resolution_clock::now();
                for (int k = 0; k < FILE_SIZE; k++){
                    getline(fin, temp_string);
                    set_example.insert(temp_string);
                }
                auto end = chrono::high_resolution_clock::now();
                auto set_example_read = duration_cast<microseconds>(end - start);
                fin.close();
                data_results[2][j][0] = set_example_read.count();

                // divider (erase later) -------------------------
                // Inserting into the set
                auto set_iter = set_example.begin();
                int set_midpoint = set_example.size() / 2;
                start = chrono::high_resolution_clock::now();
                for (int iter = 0; iter < set_midpoint; iter++){
                    set_iter++;
                }
                set_example.insert(set_iter, TEST_CODE);
                end = chrono::high_resolution_clock::now();
                auto set_example_insert = duration_cast<microseconds>(end - start);
                data_results[2][j][2] = set_example_insert.count();

                // divider (erase later) -------------------------
                // Deleting from the set
                auto set_iter_del = set_example.begin();
                start = chrono::high_resolution_clock::now();
                for (int iter = 0; iter < set_midpoint; iter++){
                    set_iter_del++;
                }
                set_example.erase(set_iter_del);
                end = chrono::high_resolution_clock::now();
                auto set_example_delete = duration_cast<microseconds>(end - start);
                data_results[2][j][3] = set_example_delete.count();
            }
        }
    }

    // for adding up all the times for each set of data 
    for (int i = 0; i < TYPES; i++){
        if (i == 0){ // adding up vector data
        data_results[0][15][0] = 0;
            for (int j = 0; j < TRIALS; j++){
                cout << data_results[0][15][0] << endl; 
                data_results[0][15][0] = data_results[0][15][0] + data_results[0][j][0]; // adds up all read values
                data_results[0][15][1] = data_results[0][15][1] + data_results[0][j][1]; // all sort values
                data_results[0][15][2] = data_results[0][15][2] + data_results[0][j][2]; // all insert values
                data_results[0][15][3] = data_results[0][15][3] + data_results[0][j][3]; // all delete values
            }
            data_results[0][15][0] = data_results[0][15][0] / 15; // vector average for read
            data_results[0][15][1] = data_results[0][15][1] / 15; // vector average for sort
            data_results[0][15][2] = data_results[0][15][2] / 15; // vector average for insert
            data_results[0][15][3] = data_results[0][15][3] / 15; // vector average for delete
            
        }

        if (i == 1){ // adding up list data
            for (int j = 0; j < TRIALS; j++){
                data_results[1][15][0] = data_results[1][15][0] + data_results[1][j][0]; // adds up all read values
                data_results[1][15][1] = data_results[1][15][1] + data_results[1][j][1]; // all sort values
                data_results[1][15][2] = data_results[1][15][2] + data_results[1][j][2]; // all insert values
                data_results[1][15][3] = data_results[1][15][3] + data_results[1][j][3]; // all delete values
            }
            data_results[1][15][0] = data_results[1][15][0] / 15; // list average for read
            data_results[1][15][1] = data_results[1][15][1] / 15; // list average for sort
            data_results[1][15][2] = data_results[1][15][2] / 15; // list average for insert
            data_results[1][15][3] = data_results[1][15][3] / 15; // list average for delete
        }

        if(i == 2){ // adding up set data
            for (int j = 0; j < TRIALS; j++){
                data_results[2][15][0] = data_results[2][15][0] + data_results[2][j][0]; // adds up all read values
                // sets are automatically sorted
                data_results[2][15][2] = data_results[2][15][2] + data_results[2][j][2]; // all insert values
                data_results[2][15][3] = data_results[2][15][3] + data_results[2][j][3]; // all delete values
            }
            data_results[2][15][0] = data_results[2][15][0] / 15; // set average for read
            // sets are already sorted
            data_results[2][15][2] = data_results[2][15][2] / 15; // set average for insert
            data_results[2][15][3] = data_results[2][15][3] / 15; // set average for delet
        }
    }
    int set_example_sort = 0;
    // The averages are held in the i and j positions in data_results[i][15][j]
    
    // output of the data
    // cout << "Number of simulations: 15" << endl;
    // cout << setw(10) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl;
    // cout << setw(10) << "Read" << setw(10) << data_results[0][15][0] << setw(10) << data_results[1][15][0] << setw(10) << data_results[2][15][0] << endl;
    // cout << setw(10) << "Sort" << setw(10) << data_results[0][15][1] << setw(10) << data_results[1][15][1] << setw(10) << set_example_sort << endl;
    // cout << setw(10) << "Insert" << setw(10) << data_results[0][15][2] << setw(10) << data_results[1][15][2] << setw(10) << data_results[2][15][3] << endl;
    // cout << setw(10) << "Delete" << setw(10) << data_results[0][15][3] << setw(10) << data_results[1][15][3] << setw(10) << data_results[2][15][3] << endl;

    return 0;
}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
