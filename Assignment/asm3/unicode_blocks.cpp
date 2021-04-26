// OS: Windows 10 (64)
//
// Compiler: g++ (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
//
// use these commands to compile it:
// gcc -c utf8.c
// g++ -o unicode_blocks utf8.o unicode_blocks.cpp
//


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

#include "utf8.c"

using std::string;
using std::vector;

struct Block {
    int begin = 0;
    int end = 0;
    string name;
};

// load file named string src, insert blocks into vector<Block> blocks
void LoadUnicodeFile(const string& src, vector<Block> &blocks);

// convert line to a Block
Block LineToBlock(string s);

// Read the file input by user, count the blocks
void ReadFileAndCount(const string& src, vector<Block> &blocks, int* bk_cnt);

// Search the code in blocks one by one
int Search(unsigned int code, vector<Block> &blocks);

// Output the error message, and exit.
void quit();

int main() {
    string src;
    std::cin >> src;
    vector<Block> blocks;
    LoadUnicodeFile("Blocks.txt", blocks);
    auto bk_cnt = new int[blocks.size()]{0};
    ReadFileAndCount(src, blocks, bk_cnt);

    string name_max;
    int max = 0;
    for (int i = 0; i < blocks.size(); ++i) {
        if (bk_cnt[i] > max) {
            max = bk_cnt[i];
            name_max = (blocks)[i].name;
        }
    }

    std::cout << name_max << '\n';

    std::cout << "press enter to quit.\n";
    std::cin.get();
    std::cin.get();
    return 0;
}


void LoadUnicodeFile(const string& src, vector<Block> &blocks) {
    std::ifstream in_file(src, std::ios_base::in);
    if (!in_file) {
        std::cout << "Blocks file missing, check \"Blocks.txt\" first\n";
        quit();
    }

    string tmp_line;

    while (std::getline(in_file, tmp_line)) {
        if (tmp_line.empty() || tmp_line[0] == '#') {
            continue;
        } else {
            blocks.push_back(LineToBlock(tmp_line));
        }
    }

    in_file.close();
}

Block LineToBlock(string s) {
    Block block;
    replace(s.begin(), s.end(), '.', ' ');
    replace(s.begin(), s.end(), ';', ' ');

    std::stringstream ss;
    ss << s;
    ss >> std::hex >> block.begin >> block.end;
    std::getline(ss, block.name);
    block.name.erase(0, block.name.find_first_not_of(' '));

    return block;
}

void ReadFileAndCount(const string& src, vector<Block> &blocks, int* bk_cnt) {
    std::ifstream in_file(src, std::ios_base::in);
    if (!in_file) {
        std::cout << "Test file missing!\n";
        quit();
    }

    string file_text;
    string tmp_line;
    int bytes_in_char;

    while(!in_file.eof()) {
        std::getline(in_file, tmp_line);
        file_text.append(tmp_line);
    }

    for (int i = 0; i < file_text.size(); i += bytes_in_char) {
        unsigned int code_point = utf8_to_codepoint(reinterpret_cast<const unsigned char *>(&file_text[i]), &bytes_in_char);
        bk_cnt[Search(code_point,blocks)]++;
    }

    in_file.close();
}

int Search(unsigned int code, vector<Block> &blocks) {
    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i].begin <= code && blocks[i].end >= code) {
            return i;
        }
    }
    return -1;
}

void quit() {
    std::cout << "press enter to quit.\n";
    std::cin.get();
    std::cin.get();
    exit(0);
}

