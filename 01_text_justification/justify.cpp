#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// print the spaces needed for full justify
void printSpaces(int num)
{
    for (int i = 0; i < num; i++)
    {
        std::cout << " ";
    }
}

// given a text, create a dashed box and push all text to the right
// leave the extra spaces to the left.
std::vector<std::string> flush_right(std::vector<std::string> file, int width)
{
    int extraSpaces = width;
    bool enoughWords = false;
    std::vector<std::string> wordsInLine;
    std::vector<std::string> output; 
    for (int i = 0; i < file.size(); i++)
    {
        if (extraSpaces < file[i].length() || extraSpaces < 0)
        {
            extraSpaces += 1;
            enoughWords = true;
        }
        else
        {
            extraSpaces -= (file[i].length() + 1);
            wordsInLine.push_back(file[i]);
        }

        if (enoughWords)
        {
            std::cout << "| "; // chnaget to output file
            for (int j = 0; j < extraSpaces; j++)
            {
                std::cout << " ";
            } // change to output files
            for (int k = 0; k < wordsInLine.size(); k++)
            {
                std::cout << wordsInLine[k] << " ";
            }
            std::cout << "|" << std::endl;
            extraSpaces = width;
            enoughWords = false;
            wordsInLine.clear();
            i--;
        }
    }
    std::cout << "| ";
    for (int i = 0; i < extraSpaces + 1; i++)
    {
        std::cout << " ";
    }
    for (int w = 0; w < wordsInLine.size(); w++)
    {
        std::cout << wordsInLine[w] << " ";
    }
    std::cout << "|" << std::endl;

    return output;
}

// given a text, create a dashed box and push all text to the left
// leave the extra spaces to the right.
void flush_left(std::vector<std::string> file, int width)
{
    int extraSpaces = width;
    bool enoughWords = false;
    std::vector<std::string> wordsInLine;
    for (int i = 0; i < file.size(); i++)
    {

        if ((extraSpaces < file[i].length() || extraSpaces < 0))
        {
            extraSpaces += 1;
            enoughWords = true;
        }
        else
        {
            extraSpaces -= (file[i].length() + 1);
            wordsInLine.push_back(file[i]);
        }

        if (enoughWords)
        {
            std::cout << "| "; // chnaget to output file
            for (int k = 0; k < wordsInLine.size(); k++)
            {
                std::cout << wordsInLine[k] << " ";
            }
            for (int j = 0; j < extraSpaces; j++)
            {
                std::cout << " ";
            } // output
            std::cout << "|" << std::endl;
            extraSpaces = width;
            enoughWords = false;
            wordsInLine.clear();
            i--;
        }
    }
    std::cout << "| ";
    for (int w = 0; w < wordsInLine.size(); w++)
    {
        std::cout << wordsInLine[w] << " ";
    }
    for (int i = 0; i < extraSpaces + 1; i++)
    {
        std::cout << " ";
    }
    std::cout << "|" << std::endl;
}

//Evening space out extra spaces among the words on the line
//Bump more spaces to the words on the left, if spaces are not evenly distribuated
void fully_justify(std::vector<std::string> file, int width)
{
    int extraSpaces = width;
    bool enoughWords = false;
    std::vector<std::string> wordsInLine;
    for (int i = 0; i < file.size(); i++)
    {
        if (file[i].length() > width)
        {
            std::string firstStr = file[i].substr(0, width - 1) + "-";
            std::string secondStr = file[i].substr(width - 1);
            if(wordsInLine.size() >= 1){
            }
            else{
                std::cout << "| " << firstStr << " |" << std::endl;
                file[i] = secondStr;
            }
            //std::cout << "CUR SPACE: " << extraSpaces << std::endl;
        }
        if ((extraSpaces < file[i].length() || extraSpaces < 0) ) 
        {
            extraSpaces += 1;
            enoughWords = true;
        }
        else
        {
            extraSpaces -= (file[i].length() + 1);
            wordsInLine.push_back(file[i]);
        }
        //std::cout << "EXTRA: "<<extraSpaces << std::endl;
        if(wordsInLine.size() == 0){
            enoughWords = false;
            extraSpaces = width;
            wordsInLine.clear();
            i--;
        }
        if (enoughWords)
        {
            std::cout << "| ";
            for (int j = 0; j < wordsInLine.size(); j++)
            {
                std::cout << wordsInLine[j] << " ";
                if (j != (wordsInLine.size() - 1))
                {
                    printSpaces(extraSpaces / (wordsInLine.size() - 1));
                }
                for (int mod = 0; mod < (extraSpaces % (wordsInLine.size() - 1)); mod++)
                {
                    if ((wordsInLine[j] == wordsInLine[mod]) && (j <= mod))
                    { 
                        std::cout << " ";
                    }
                }
                if(wordsInLine.size() == 1){
                    printSpaces(extraSpaces-1);
                }
            }
            std::cout << "|" << std::endl;
            extraSpaces = width;
            enoughWords = false;
            wordsInLine.clear();
            i--;
        }
    }
    std::cout << "| ";

    for (int w = 0; w < wordsInLine.size(); w++)
    {
        std::cout << wordsInLine[w] << " ";
    }
    for (int i = 0; i < extraSpaces + 1; i++)
    {
        std::cout << " ";
    }
    std::cout << "|" << std::endl;
}

void printDashes(char *width)
{
    for (int i = 0; i < std::stoi(width) + 4; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl; // chnage all std to output file
}

//main function 
int main(int argc, char *argv[])
{
    std::string inFiles;
    std::vector<std::string> fileWords;
    // checks if user have inputted 4 inputs
    if (argc < 5)
    {
        std::cerr << "ERROR, please check if you have inputted everything correctly!";
        exit(1);
    }
    // opening the input file
    std::ifstream in_str(argv[1]);
    // checking if the input file can be opened, if not tell the user.
    if (!in_str.good())
    {
        std::cerr << "Can't Open " << argv[1] << " to read.\n";
        exit(1);
    }
    // while loop that add the words inside the input files into the vector
    while (in_str >> inFiles)
    {
        fileWords.push_back(inFiles);
    }
    in_str.close();

    printDashes(argv[3]);
    //checking if the output file can be opened
    std::ofstream out_str(argv[2]);
    if (!out_str.good())
    {
        std::cerr << "Can't open " << argv[2] << " to write.\n";
        exit(1);
    }

    //calls the nessecary function base on the how the user wants it organized
    if (std::string(argv[4]) == std::string("flush_right"))
    {
        flush_right(fileWords, std::stoi(argv[3]));
    }
    if (std::string(argv[4]) == std::string("flush_left"))
    {
        flush_left(fileWords, std::stoi(argv[3]));
    }
    if (std::string(argv[4]) == std::string("full_justify"))
    {
        fully_justify(fileWords, std::stoi(argv[3]));
    }
    printDashes(argv[3]);

    return 0;
}