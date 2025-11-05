
> by Rishav Sharma,  SSU ID **007747214**
> [Github Repo](https://github.com/notBjorn/P4_DecodeHuffman)


## **Collaboration & Sources**
All the code in this project is mine. I did use lookup syntax for a specific for loop function but beyond that all the code in this project and no other outside help was used.

## **Implementation Details**
### `Main`
- Created paths for all the files that i need to read and write
- Created validation functions for the read files and write files to reduce clutter.
    - `validateReadFiles` takes in the path of the read files and checks weather the file directory exists and if the files themself exist. Then I checked if the first word of the header file was an alphabet or not and if the first word of the code file 0/1 or not.
    - `checkWriteFiles` did the same thing for the write files besides checking if the info in the files was valid or not
- Created a readHeader function in main that converted the header file data into a header pair which would be used as the input or creating the HuffMan Tree
    - `readHeader` opens the file from the path provided, checks if the file is open, reads a line and then deconstructs that line into a word and a code associated with that word uning the basic for loops and `isalplha` and `isdigit` functions. these words and codes/numbers are then pushed onto the vector of pairs. I then check whether the data was successfully written by checking whether the vector is empty or not.
- created a decoder object using the Huffman Tree classes buildFromHeader function
- after the huffman tree was constructed I gave the code data to the decode function from the huffman tree to create the tokens
- _Overall the structure of the main file was pretty simple after having worked on the Project 3_

### `Huffman Tree Class`
- `buildFromHeader` uses the helper function `buildTree` to create the huffman tree from the code and associated word provided in the vector of pairs the `buildFromHeader` is running a simpe for loop and passing over the `word` and the `code/address` to the `buildTree` function which does the actual job of creating the tree also using a simple for loop. I had to modify the `Treenode` class a little to have a setWord function but besides that the logic in the buildTree function is really straight forward. we look at the code one character at a time and if the `char` is 0 we create or switch to the left node and if it is 1 we do the same with right node and when we reach the end of the code we insert the word that is associated with that code. creating a tree.
- `decode` function is the opposite of the buildFromHeader where we are going down the tree one bit at at time and when we reach a node with no children i.e. the leaf we basically write the word at that node as well as a newline character. we then repeat the process until the end of the file has been reached.


## **Testing & Status**
**The program, to the best of my knowledge, is working perfectly**. Before I had the script I ran the code with diff command and my own tokens file and I found no difference and after running the scripts that the professor provided I still have found no differences. The process of writing and testing the code was pretty straightforward as I was already aware of most of the issues surrounding the project from my experience with Project 3.
