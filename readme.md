
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

### Output from scripts

```txt
rsharma@blue:~/P4_DecodeHuffman$ bash compile_and_test_project4.bash 
Compiling: g++ -std=c++20 -Wall HuffmanTree.cpp main.cpp utils.cpp -o p3_complete.x

Scanning for inputs in: input_output

==> Running: p3_complete.x on the_toil_of_trace_and_trail.hdr the_toil_of_trace_and_trail.code
Comparing: input_output/the_toil_of_trace_and_trail.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/the_toil_of_trace_and_trail.tokens

==> Running: p3_complete.x on the_dominant_primordial_beast.hdr the_dominant_primordial_beast.code
Comparing: input_output/the_dominant_primordial_beast.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/the_dominant_primordial_beast.tokens

==> Running: p3_complete.x on for_the_love_of_a_man.hdr for_the_love_of_a_man.code
Comparing: input_output/for_the_love_of_a_man.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/for_the_love_of_a_man.tokens

==> Running: p3_complete.x on who_has_won_to_mastership.hdr who_has_won_to_mastership.code
Comparing: input_output/who_has_won_to_mastership.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/who_has_won_to_mastership.tokens

==> Running: p3_complete.x on the_law_of_club_and_fang.hdr the_law_of_club_and_fang.code
Comparing: input_output/the_law_of_club_and_fang.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/the_law_of_club_and_fang.tokens

==> Running: p3_complete.x on into_the_primitive.hdr into_the_primitive.code
Comparing: input_output/into_the_primitive.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/into_the_primitive.tokens

==> Running: p3_complete.x on tableOfContents_TheCallOfWild.hdr tableOfContents_TheCallOfWild.code
Comparing: input_output/tableOfContents_TheCallOfWild.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/tableOfContents_TheCallOfWild.tokens

==> Running: p3_complete.x on the_sounding_of_the_call.hdr the_sounding_of_the_call.code
Comparing: input_output/the_sounding_of_the_call.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/the_sounding_of_the_call.tokens

==> Running: p3_complete.x on the_call_of_the_wild.hdr the_call_of_the_wild.code
Comparing: input_output/the_call_of_the_wild.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/the_call_of_the_wild.tokens

==> Running: p3_complete.x on lab08_input.hdr lab08_input.code
Comparing: input_output/lab08_input.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/lab08_input.tokens

==> Running: p3_complete.x on TheBells.hdr TheBells.code
Comparing: input_output/TheBells.tokens_decoded  and  /home/faculty/kooshesh/cs315_fall2025/project4/data/TheBells.tokens

Summary: 11 match(es), 0 diff(s).
```