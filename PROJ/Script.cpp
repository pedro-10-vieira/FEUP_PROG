#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Script.hpp"
#include "PNG.hpp"
#include "XPM2.hpp"

using namespace std;

namespace prog {

    // Use to read color values from a script file.
    istream& operator>>(istream& input, Color& c) {
        int r, g, b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }

    Script::Script(const string& filename) :
            image(nullptr), input(filename) {

    }
    void Script::clear_image_if_any() {
        if (image != nullptr) {
            delete image;
            image = nullptr;
        }
    }
    Script::~Script() {
        clear_image_if_any();
    }

    void Script::run() {
        string command;
        while (input >> command) {
            cout << "Executing command '" << command << "' ..." << endl;
            if (command == "open") {
                open();
                continue;
            }
            if (command == "blank") {
                blank();
                continue;
            }
            if (command == "save") {
                save();
                continue;
            } 

            if(command == "invert"){
                invert();
                continue;
            }
            
            if(command == "to_gray_scale"){
                to_gray_scale();
                continue;
            }

            if(command == "crop"){
                crop();
                continue;
            }

            if(command == "rotate_left"){
                rotate_left();
                continue;
            }

            if(command == "rotate_right"){
                rotate_right();
                continue;
            }

            if(command == "h_mirror"){
                h_mirror();
                continue;
            }

            if(command == "v_mirror"){
                v_mirror();
                continue;
            }

            if(command == "add"){
                add();
                continue;
            }

            if(command == "fill"){
                fill();
                continue;
            }

            if(command == "replace"){
                replace();
                continue;
            }

            if(command == "median_filter"){
                median_filter();
                continue;
            }

            if(command == "xpm2_open"){
                xpm2_open();
                continue;
            }

            if (command == "xpm2_save"){
                xpm2_save();
                continue;
            }
        }
    }
    void Script::open() {
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromPNG(filename);
    }
    void Script::blank() {
        clear_image_if_any();
        int w, h;
        Color fill;
        input >> w >> h >> fill;
        image = new Image(w, h, fill);
    }
    void Script::save() {
        string filename;
        input >> filename;
        saveToPNG(filename, image);
    }

    void Script::invert() {
        //Transforms each individual pixel (r, g, b) to (255-r,255-g,255-b).
        if (image == nullptr) {    // Check if image is null 
            return;    // return
        }
        for (int i = 0; i < image->width(); i++) {    
            for (int j = 0; j < image->height(); j++) {    
                Color& c = image->at(i, j);    // Access pixel at location (i,j)
                c.red() = 255 - c.red();    
                c.green() = 255 - c.green();
                c.blue() = 255 - c.blue();  
            }
        }
    }

    void Script::to_gray_scale(){  
        //Transforms each individual pixel (r, g, b) to (v, v, v) where v = (r + g + b)/3. You should use integer division without rounding to compute v.  

        if (image == nullptr) {    // Check if image is empty or not
            return;
        }
        for (int i = 0; i < image->width(); i++) {    
            for (int j = 0; j < image->height(); j++) {    
                Color& c = image->at(i, j);
                int gray = (c.red() + c.green() + c.blue()) / 3;    
                c.red() = gray;    
                c.green() = gray;  
                c.blue() = gray;   
            }
        }
    }

    void Script::crop(){
        //Crop the image, reducing it to all pixels contained in the rectangle defined by top-left corner (x, y), width w, and height h.You may assume that the rectangle is always within the current image bounds.
        if (image == nullptr) {    // Check if image is empty or not
            return;
        }
        int x, y, w, h;
        input >> x >> y >> w >> h;    
        Image* newImage = new Image(w, h, Color(0, 0, 0));   
        for (int i = 0; i < w; i++) {    
            for (int j = 0; j < h; j++) {   
                Color& c = newImage->at(i, j);
                c = image->at(x + i, y + j);    // Assign the value of color of the pixel to the new image
            }
        }
        delete image;    
        image = newImage;    
    }

    void Script::rotate_left(){
        //Rotate image left by 90 degrees.
        if (image == nullptr) {    
            return;
        }
        Image* newImage = new Image(image->height(), image->width(), Color(0, 0, 0));    
        for (int i = 0; i < image->width(); i++) {    
            for (int j = 0; j < image->height(); j++) {   
                Color& c = newImage->at(j, image->width() - i - 1);   
                c = image->at(i, j);    // Set newImage pixel value as oldImage pixel value
            }
        }
        delete image;    
        image = newImage;
    }

    void Script::rotate_right(){
        //Rotate image right by 90 degrees.
        if (image == nullptr) {    // Check if image is null
            return;
        }
        Image* newImage = new Image(image->height(), image->width(), Color(0, 0, 0));    
        for (int i = 0; i < image->width(); i++) {    
            for (int j = 0; j < image->height(); j++) {    
                Color& c = newImage->at(image->height() - j - 1, i);    
                c = image->at(i, j);    
            }
        }
        delete image;    // Delete old image
        image = newImage;    // Update image pointer to newImage
    }

    void Script::h_mirror(){
        //Mirror image horizontally. Pixels (x, y) and (width() - 1 - x, y) for all 0 <= x < width() / 2 and 0 <= y < height().
        if (image == nullptr) {    // If image is null
            return;
        }
        Image* newImage = new Image(image->width(), image->height(), Color(0, 0, 0));    
        for (int i = 0; i < image->width(); i++) {    
            for (int j = 0; j < image->height(); j++) {    
                Color& c = newImage->at(i, j);    
                c = image->at(image->width() - i - 1, j);    // Horizontally mirror the image
            }
        }
        delete image;    
        image = newImage;    
    }

    void Script::v_mirror(){
        //Mirror image vertically. Pixels (x, y) and (x, height() - 1 - y) for all 0 <= x < width() and 0 <= y < height() / 2.
        if (image == nullptr) {    // if image is null
            return;
        }
        Image* newImage = new Image(image->width(), image->height(), Color(0, 0, 0));
        for (int i = 0; i < image->width(); i++) {    
            for (int j = 0; j < image->height(); j++) {    
                Color& c = newImage->at(i, j);    
                c = image->at(i, image->height() - j - 1);    // Vertically mirror the image
            }
        }
        delete image;   
        image = newImage;    
    }

    void Script::replace(){    
        // Replaces all (r1,  g1, b1) pixels by (r2,  g2, b2).
        int r1, g1, b1, r2, g2, b2;    
        input >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;    
        for(int i =0; i<image->width(); i++){    
            for(int j =0; j<image->height(); j++){    
                if(image->at(i,j).red() == r1 && image->at(i,j).green() == g1 && image->at(i,j).blue() == b1){    // If image[i][j] is equal to r1,g1,b1
                    image->at(i,j).red() = r2;   
                    image->at(i,j).green() = g2; 
                    image->at(i,j).blue() = b2;  
                }
            }
        }
    }

    void Script::add(){    
        string filename;    // variable to hold filename
        input >> filename;    
        Image* newImage = loadFromPNG(filename);    // Load the image from PNG file of given filename
        int r,g,b,x,y;    
        input >> r >> g >> b >> x >> y;    
        for(int i =0; i<newImage->width(); i++){    
            for(int j =0; j<newImage->height(); j++){   
                if(newImage->at(i,j).red() != r || newImage->at(i,j).green() != g || newImage->at(i,j).blue() != b){    // Check if the color of current pixel is not the same as given color
                    image->at(x+i,y+j).red() = newImage->at(i,j).red();    
                    image->at(x+i,y+j).green() = newImage->at(i,j).green();
                    image->at(x+i,y+j).blue() = newImage->at(i,j).blue();  
                }
            }
        }
        delete newImage;    // Delete the new image
    }

    void Script::xpm2_open(){
        //Read image stored in the XPM2 file format. This command should result in a call to Image *loadFromXPM2(const std::string &file) declared in XPM2.hpp. This function in turn needs to be implemented.
        string filename;
        input >> filename;
        Image* newImage = loadFromXPM2(filename); // take address of loadFromXPM2 function and store in newImage
        delete image;
        image = newImage;
    }


    void Script::fill(){    
        //Assign (r, g, b) to all pixels contained in rectangle defined by top-left corner (x, y), width w, and height h, i.e., all pixels (x', y') such that x <= x' < x + w and y <= y' < y + h. You may assume that the rectangle is always within the current image bounds.
        int  x, y, w, h,r, g, b;    
        input >>x >> y >> w >> h >> r >> g >> b ;    

        for(int i =0; i<w; i++){    
            for(int j =0; j<h; j++){   
                image->at(x+i,y+j).red() = r;    
                image->at(x+i,y+j).green() = g;  
                image->at(x+i,y+j).blue() = b;   
            }
        }
    }

    void Script::median_filter() {
        int ws;
        input >> ws;
        // To create a new temporary image
        Image* temp = new Image(image->width(), image->height());
        // To reach all image pixels
        for (int x = 0; x<image->width(); x++){
            for (int y = 0; y<image->height(); y++){
                vector<rgb_value> red, green, blue;
                // To reach all that pixel's neighbours, including that pixel itself
                for (int nx = max(0, x - ws / 2); nx <= min(image->width() - 1, x + ws / 2); nx++) {
                    for (int ny = max(0, y - ws / 2); ny <= min(image->height() - 1, y + ws /2); ny++) {
                        // We add to the vectors all tonalities of each rgb value of each color in the neighbourhood
                        red.push_back(image->at(nx, ny).red());
                        green.push_back(image->at(nx, ny).green());
                        blue.push_back(image->at(nx, ny).blue());
                    }
                }
                sort(red.begin(), red.end());
                sort(green.begin(), green.end());
                sort(blue.begin(), blue.end());
                // To find the median value of that sorted vectors in the cases of their size being odd or even
                if (red.size() % 2 != 0) {
                    temp->at(x,y).red() = red[red.size() / 2];
                }
                else {
                    temp->at(x,y).red() = (red[red.size() / 2] + red[red.size() / 2 - 1]) / 2;
                }
                if (green.size() % 2 != 0) {
                    temp->at(x,y).green() = green[green.size() / 2];
                }
                else {
                    temp->at(x,y).green() = (green[green.size() / 2] + green[green.size() / 2 - 1]) / 2;
                }
                if (blue.size() % 2 != 0) {
                    temp->at(x,y).blue() = blue[blue.size() / 2];
                }
                else {
                    temp->at(x,y).blue() = (blue[blue.size() / 2] + blue[blue.size() / 2 - 1]) / 2;
                }
            }
        }
        // To avoid memory leaks we delete the old image 
        delete image;
        // We make the temporary image the new main one
        image = temp;
    }

     void Script::xpm2_save() {
        // This command will result in a call to saveToXPM2, to save the final image in the XPM2 format
        string filename;
        input >> filename;
        saveToXPM2(filename, image);
    }
}