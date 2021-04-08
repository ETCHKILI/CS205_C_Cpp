#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#define MAX_NAME_SIZE 25
#define MAX_ARR_SIZE 800

const int kMaxNameSize = MAX_NAME_SIZE;
const int kMaxArrSize = MAX_ARR_SIZE;

struct City{
    std::string city_name;
    std::string province_name;
    std::string country_name;
    double latitude = 0;
    double longitude = 0;
};



void ReadCities(const std::string& source, std::vector<City>& cities);
void ConvertLineToCity(std::string& line, City& city);
void ShowException(int id);

int main() {
    std::vector<City> cities;
    try {
        ReadCities("world_cities.csv", cities);
    } catch (int exception_id) {
        ShowException(exception_id);
    }
}

// open file and take lines one by one and convert them as cities
// return exception_id
void ReadCities(const std::string& source, std::vector<City>& cities) {
    std::ifstream in_file("world_cities.csv", std::ios_base::in);
    if (!in_file) {
        throw 11; // exception_id: 11: when read city, cannot open file;
    }
    std::string tmp_line;

    int count = 0;
    while (std::getline(in_file, tmp_line)) {
        if (count >= kMaxArrSize) {
            throw 12; // exception_id: 12: when read city, over max arr size
        }
        City tmp_city;
        ConvertLineToCity(tmp_line, tmp_city);

        ++count;
        cities.push_back(tmp_city);
    }
}

// convert one line in the file(string) to city data
// return int exception_id
void ConvertLineToCity(std::string& line, City& city) {
    int col = 0; // count of column.
    int start = 0; // current index of start char for current column
    int end = 0; // current index of end char for current column
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == ',' || i == line.size() - 1) {
            if (i == line.size() - 1) {
                ++end;
            }
            if ( col >= 0 && col <=2 && (end - start > kMaxNameSize)) {
                throw 21; // exception_id: 2_1: when converting line to city, over max name size;
            }
            switch (col) {
                case 0:
                    city.city_name = line.substr(start, end - start);
                    break;
                case 1:
                    city.province_name = line.substr(start, end - start);
                    break;
                case 2:
                    city.country_name = line.substr(start, end - start);
                    break;
                case 3:
                    city.latitude = std::stod(line.substr(start, end - start));
                    break;
                case 4:
                    city.longitude = std::stod(line.substr(start, end - start));
                    break;
                default:
                    break;
            }
            ++col;
            start = i + 1;
        }
        ++end;
    }
}

// take an exception_id as argument
// output the exception message
void ShowException(int id) {
    switch (id) {
        case 11: {
            std::cout << "Cannot open the file!";
            break;
        }
        case 12: {
            std::cout << "The amount of cities exceed the limit(" << kMaxArrSize << ")!";
            break;
        }
        case 21: {
            std::cout << "The size of the name of one city exceed the limit" << kMaxNameSize << ")!";
            break;
        }
        default: {
            std::cout << "Unexpected exception, try again or contact us:)";
        }
    }
}