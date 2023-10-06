#include "XPM2.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include "Color.hpp"
#include "Image.hpp"

using namespace std;

namespace prog {
    Image* loadFromXPM2(const string& file) {    
        map<char, Color> colorMap;    // Initialize colorMap
        map<char, int> hexToDec = {    // Initialize hexToDec
            {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},
            {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12},
            {'D', 13}, {'E', 14}, {'F', 15}
        };

        ifstream in(file);    // Open file 
        string line;   
        int width, height, numColors, charsPerColor;
        getline(in, line);    
        getline(in, line);    
        istringstream iss(line);    
        iss >> width >> height >> numColors >> charsPerColor;    

        for (int i = 0; i < numColors; i++) {    
            getline(in, line);    
            char ch, hexPrefix;
            string hexCode;
            istringstream iss(line);    
            iss >> ch >> hexPrefix >> hexCode;    

            int red = hexToDec[toupper(hexCode[1])] * 16 + hexToDec[toupper(hexCode[2])];    // convert red color
            int green = hexToDec[toupper(hexCode[3])] * 16 + hexToDec[toupper(hexCode[4])];    // convert green color
            int blue = hexToDec[toupper(hexCode[5])] * 16 + hexToDec[toupper(hexCode[6])];    // convert blue color


            colorMap[ch] = Color(red, green, blue);    // Add the color to colorMap
        }

        Image* result = new Image(width, height);    // Create new image of given size
        for (int j = 0; j < height; j++) {    
            getline(in, line);    
            for (int i = 0; i < width; i++) {    
                result->at(i, j) = colorMap[line[i]];    // Assign color at (i,j)
            }
        }

        return result;    // Return the image
    }


    bool operator<(const Color& c1, const Color& c2) {
        return (c1.red() < c2.red()) || (c1.red() == c2.red() &&  c1.green() < c2.green()) || (c1.red() == c2.red() &&  c1.green() == c2.green() && c1.blue() < c2.blue());
    }

    void saveToXPM2(const std::string& file, const Image* image) {
        ofstream os(file);
        os << "! XPM2" << endl;
        int h = image->height();
        int w = image->width();
        // Vector that contains all the different colors present in the image
        vector<Color> image_colors;
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                Color pixel = image->at(x, y);
                // If that color wasn't found before add it to the vector
                if (find(image_colors.begin(), image_colors.end(), pixel) == image_colors.end()) {
                    image_colors.push_back((pixel));
                }
            }
        }
        size_t n = image_colors.size();
        os << w << " " << h << " " << n << " " << 1 << endl;
        // Map that associates each color to a representative symbol 
        map<Color,int> color_symbol;
        // Initial symbol (will be associated with the first color)
        int i = 0;
        map<int, char> DectoHex = {
            {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'},
            {7, '7'}, {8, '8'}, {9, '9'}, {10, 'A'}, {11, 'B'}, {12, 'C'},
            {13, 'D'}, {14, 'E'}, {15, 'F'}
        };
        for (Color cor : image_colors) {
            // to make the associations
            color_symbol[cor] = i;
            // strings that will represent the colors in hexadecimal (#rgb)
            string red; 
            red.push_back(DectoHex[cor.red() / 16]);  
            red.push_back(DectoHex[cor.red() % 16]);  
            string green; 
            red.push_back(DectoHex[cor.green() / 16]);  
            red.push_back(DectoHex[cor.green() % 16]); 
            string blue; 
            red.push_back(DectoHex[cor.blue() / 16]);  
            red.push_back(DectoHex[cor.blue() % 16]); 
            os << i << " " << "c" << " " << "#" << red << green << blue << endl;
            // to go to the next symbol
            i ++;
        }
        // to draw the image with the symbols associated with its colors
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                Color pixel = image->at(x, y);
                os << color_symbol[pixel]; 
            }
            os << endl;
        }
    }
}