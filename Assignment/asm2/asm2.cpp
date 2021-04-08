#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>


#define MAX_NAME_SIZE 25
#define MAX_ARR_SIZE 800

const int kMaxNameSize = MAX_NAME_SIZE;
const int kMaxArrSize = MAX_ARR_SIZE;
const int kEarthRadius_KM = 6371;

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
int Similarity_EditDistance(std::string str1, std::string str2);

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
        throw 10; // exception_id: 11: when read city, cannot open file;
    }
    std::string tmp_line;

    int count = 0;
    while (std::getline(in_file, tmp_line)) {
        if (count >= kMaxArrSize) {
            throw 11; // exception_id: 12: when read city, over max arr size
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
                throw 20; // exception_id: 2_1: when converting line to city, over max name size;
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
        case 10: {
            std::cout << "Cannot open the file!";
            break;
        }
        case 11: {
            std::cout << "The amount of cities exceed the limit(" << kMaxArrSize << ")!";
            break;
        }
        case 20: {
            std::cout << "The size of the name of one city exceed the limit" << kMaxNameSize << ")!";
            break;
        }
        default: {
            std::cout << "Unexpected exception, try again or contact us:)";
        }
    }
}

// return the similarity of two input string by calculating edit_distance
int Similarity_EditDistance(std::string str1, std::string str2) {
    int len1 = str1.size();
    int len2 = str2.size();

    int** p_distances = new int*[len1 + 1];
    for (int i = 0; i < len1 + 1; ++i) {
        p_distances[i] = new int[len2 + 1];
        p_distances[i][0] = i;
    }

    for (int i = 0; i < len2 + 1; ++i) {
        p_distances[0][i] = i;
    }

    for (int i = 1; i < len1 + 1; ++i) {
        for (int j = 1; j < len2 + 1; ++j) {
            p_distances[i][j] = std::min(p_distances[i-1][j]+1, p_distances[i][j-1]+1);
            p_distances[i][j] = std::min(p_distances[i][j], p_distances[i-1][j-1]+1 + (str1[i-1]==str2[j-1] ? 0:1));
        }
    }

    int result = p_distances[len1][len2];

    for (int i = 0; i < len1 + 1; ++i) {
        delete[] p_distances[i];
        p_distances = nullptr;
    }
    delete[] p_distances;
    p_distances = nullptr;

    return 1 - result/std::max(len1, len2);
}

void UserInterface() {
    std::string tmp;
    while ()
    std::cout << "Please input the name of the first city:\n";

}



double CalculateDistance(City &city1, City &city2) {

//    if (city1.latitude < -90 || city1.latitude > 90 || city1.longitude < -180 || city1.longitude > 180) {
//        std::cout << "Check your location data! (0 <= phi <= 180, -180 <= theta <= 180)\n";
//    }
//    if (city2.latitude < -90 || city2.latitude > 90 || city2.longitude < -180 || city2.longitude > 180) {
//        std::cout << "Check your location data! (0 <= phi <= 180, -180 <= theta <= 180)\n";
//    }

    double phi1 = (90 - city1.latitude) * M_PI / 180;
    double phi2 = (90 - city2.latitude) * M_PI / 180;
    double theta1 = (city1.longitude) * M_PI / 180;
    double theta2 = (city2.longitude) * M_PI / 180;

    return kEarthRadius_KM * acos(sin(phi1) * sin(phi2)
            * cos(theta1 - theta2)
            + cos(phi1) * cos(phi2));
}
