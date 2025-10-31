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

#include "HuffmanTree.hpp"

namespace fs = std::filesystem;

void validateReadFiles(const fs::path& hdrFile, const fs::path& codeFile);
void checkWriteFiles(const fs::path& decodeFile);
error_type readHeader(const fs::path& hdrFile, std::vector<std::pair<std::string, std::string> >& header);


// -- MAIN BEGINS --

int main(int argc, char *argv[]) {
    // -- input creation and validation stage --
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <Header filename>  <Code filename>\n";
        return 1;
    }

    fs::path dirPath(std::string("input_output")); //config for our directory
    std::string headFN = std::string(argv[1]);         //wanted to do this in the path declaration
    std::string codeFN = std::string(argv[2]);         //but the complier was crying for no reason

    fs::path headerFile(headFN); //.hdr file name
    fs::path codeFile(codeFN);   //.code file name
    fs::path headPath = dirPath / headerFile; //path to the .hdr file
    fs::path codePath = dirPath / codeFile; //path to the .code file
    std::string fileBaseName = codeFile.stem().string(); //base name of the files we are gonna create

    fs::path decodeFile(fileBaseName + ".tokens_decoded"); //name of the file we are gonna create
    fs::path decodePath = dirPath / decodeFile;      //where the decode file is going to be created

    validateReadFiles(headPath, codePath);  //check if the files are valid
    checkWriteFiles(decodePath); //check if we can write to the directory

    // ** input creation and validation done **

    // -- reading the header file and moving its contents to an appropriate container
    std::vector<std::pair<std::string, std::string>> header_pairs; //will hold the header pairs

    // read the file and write its content in header_pairs
    if ( error_type status; (status = readHeader(headPath, header_pairs)) != NO_ERROR)
        exitOnError(status, headPath.string());

    HuffmanTree decoder = HuffmanTree::buildFromHeader(header_pairs);

    // ** Huffman tree creation should be done here

    std::ifstream code_in(codePath);
    std::ofstream token_out(decodePath, std::ios::out | std::ios::trunc);
    if (error_type status = decoder.decode(code_in, token_out); status != NO_ERROR) {
        exitOnError(status, codePath.string());
    }
    code_in.close();
    token_out.close();






    // open the input .code file (call it code_stream) and .tokens_decoded files (out_stream)
    //auto decode_status = decoder.decode(code_stream, out_stream);




}
// ** MAIN END **





// -- Function definitions ahead --

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


/*
input needs to be a path to the header file not just the header file name
the vector of pairs will store the read files contents
we will return an error_type this means the function needs to be called in a specific manner, remember that.*/
error_type readHeader(const fs::path& hdrFile, std::vector<std::pair<std::string, std::string> >& header) {
    std::ifstream hFile(hdrFile); //open file
    if (!hFile.is_open()) {
        return UNABLE_TO_OPEN_FILE;
    }
    std::string line;             //string will hold one line at a time

    // the following code only works if the header file we recieved is formatted correctly
    while (std::getline(hFile, line)) {
        std::pair<std::string, std::string> pair;
        for (auto c : line) {
            if (isalpha(c))
                pair.first.push_back(c);
            if (isdigit(c))
                pair.second.push_back(c);
        }
        header.emplace_back(pair);
    }
    if (header.empty()) {
        std::cerr << "Error: Header file is empty\n";
        return ERR_TYPE_NOT_FOUND;
    }
    hFile.close();
    return NO_ERROR;
}


void checkWriteFiles(const fs::path& decodeFile) {
    std::cout << "checking write permissions\n"; //debug comment
    if (error_type status; (status = directoryExists(decodeFile.parent_path().string())) != NO_ERROR)
        exitOnError(status, decodeFile.parent_path().string());
    if (error_type status; (status = canOpenForWriting(decodeFile.string())) != NO_ERROR)
        exitOnError(status, decodeFile.filename().string());
    std::cout << "We can write\n"; //debug comments
}




// ** Function definition end **

