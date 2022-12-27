#include "file_interator.h"
#include <iostream>

int main() {
    string fileName = "D:\\My_project\\Data Structures and Algorithms Specialization\\algorithm_practice\\Course 2\\course2_2003291203\\week3_hash_tables\\2_hash_chains\\tests\\06";
    FileInteractor file = FileInteractor(fileName);
    std::cout << file.printVector(file.readLines()->toWords());
}