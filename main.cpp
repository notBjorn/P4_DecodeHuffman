#include <iostream>
#include <iomanip>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>


//#include "Scanner.hpp"
#include "utils.hpp"
//#include "BinSearchTree.hpp"
//#include "HuffmanTree.hpp"
#include <algorithm>

namespace fs = std::filesystem;

/* some functions from previous project
// function that I wiil use compare frequencies before writing the freq file
bool compareFrequency(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}


//function that will write the freq file with the correct format
void writeFreq(std::string filename, std::vector<std::pair<std::string, int> > freqList) {
    std::ofstream out(filename, std::ios::out | std::ios::trunc);

    if (!out.is_open()) {
        std::cerr << "Error: Unable to open file for writing: " << filename << "\n";
        return;
    }

    // Write each (word, count) pair: one per line as "word count"
    for (auto items: freqList) {
        out << std::setw(10) << items.second << ' ' << items.first << '\n';
        if (!out) {
            std::cerr << "Error: Failed while writing to " << filename << "\n";
            return;
        }
    }
    out.close();
}

 */

//check if files that we need to read work or not.
void validateReadFiles(const fs::path& hdrFile, const fs::path& codeFile) {
    std::cout << "Validating files\n"; //debug comment
    if (error_type status; (status = directoryExists(hdrFile.parent_path().string())) != NO_ERROR)
        exitOnError(status, hdrFile.parent_path().string());

    if (error_type status; (status = regularFileExistsAndIsAvailable(hdrFile.string())) != NO_ERROR)
        exitOnError(status, hdrFile.filename().string());

    if (error_type status; (status = regularFileExistsAndIsAvailable(codeFile.string())) != NO_ERROR)
        exitOnError(status, codeFile.filename().string());

    std::ifstream hFile(hdrFile);
    std::string word;
    while (std::getline(hFile, word)) {
        if (!isalpha(word[0])) {
            std::cerr << "Error: Header File is inappropriate\n";
        }
    }
    hFile.close();

    std::ifstream cFile(codeFile);
    char bit;
    cFile.get(bit);
    if (bit != '0' && bit != '1') {
        std::cerr << "Error: Code File is inappropriate\n";
    }
    cFile.close();
    std::cout << "Files are valid\n"; //debug comments
}

void checkWriteFiles(const fs::path& decodeFile) {
    std::cout << "checking write permissions\n"; //debug comment
    if (error_type status; (status = directoryExists(decodeFile.parent_path().string())) != NO_ERROR)
        exitOnError(status, decodeFile.parent_path().string());
    if (error_type status; (status = canOpenForWriting(decodeFile.string())) != NO_ERROR)
        exitOnError(status, decodeFile.filename().string());
    std::cout << "We can write\n"; //debug comments
}


// -- MAIN BEGINS --


int main(int argc, char *argv[]) {

    // -- input creation and validation stage --
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <Header filename>  <Code filename>\n";
        return 1;
    }

    fs::path dirPath(std::string("input_output"));//our directory
    std::string headFN = std::string(argv[1]);//wanted to do this in the path declaration
    std::string codeFN = std::string(argv[2]);//but the complier was crying for no reason

    fs::path headerFile(headFN); //.hdr file name
    fs::path codeFile(codeFN);   //.code file name
    fs::path headPath = dirPath / headerFile; //path to the .hdr file
    fs::path codePath = dirPath / codeFile; //path to the .code file
    std::string fileBaseName = codeFile.stem().string(); //base name of the files we are gonna create

    fs::path decodeFile(fileBaseName + ".tokens_decoded"); //name of the file we are gonna create
    fs::path decodePath = dirPath / decodeFile;      //where the decode file is going to be created

    validateReadFiles(headPath, codePath);
    checkWriteFiles(decodePath);

    // -- input creation and validation done



/* //this will be useful to reference when i write the decoded file
    std::ofstream writeHdr(hdr);
    if (error_type status; (status = HFtree.writeHeader(writeHdr)) != NO_ERROR)
        exitOnError(status, hdr.string());
    writeHdr.close();
*/
}