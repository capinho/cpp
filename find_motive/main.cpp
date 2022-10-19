//
//  main.cpp
//  findmotive
//
//  Created by pape ibrahima diawara on 26/09/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main(int argc, char *argv[])
{
    string path = argv[1];
    string pattern = argv[2];
    string line;
    string word;
    
    ifstream myfile(path);

    int word_count = 0;

    if (myfile.is_open())
    {
        while (myfile >> word)
        {
            if (word.find(pattern) !=std::string::npos)
            {
                ++word_count;
            }
        }
        myfile.close();
        cout << "The file " << path << " contains " << word_count << " words containing the motive " << pattern << "\n";
    }
    else 
    {
        cout << "The file " << path << " could not be opened.\n";
        return 1;
    }
    return 0;
}
