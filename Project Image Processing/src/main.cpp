#include "Header.h"
#include "Pixel.h"

vector<Header> headers;
int totalScore = 0;
int maxScore = 110;
int testCase = 1;
//int total = 0;

void openFile(string name){
    Header headerObject;
    ifstream file(name, ios_base::binary);
    if (file.is_open()) {
        file.read(&headerObject.idLength, sizeof(headerObject.idLength));
        file.read(&headerObject.colorMapType, sizeof(headerObject.colorMapType));
        file.read(&headerObject.dataTypeCode, sizeof(headerObject.dataTypeCode));
        file.read((char *) &headerObject.colorMapOrigin, sizeof(headerObject.colorMapOrigin));
        file.read((char *) &headerObject.colorMapLength, sizeof(headerObject.colorMapLength));
        file.read(&headerObject.colorMapDepth, sizeof(headerObject.colorMapDepth));
        file.read((char *) &headerObject.xOrigin, sizeof(headerObject.xOrigin));
        file.read((char *) &headerObject.yOrigin, sizeof(headerObject.yOrigin));
        file.read((char *) &headerObject.width, sizeof(headerObject.width));
        file.read((char *) &headerObject.height, sizeof(headerObject.height));
        file.read(&headerObject.bitsPerPixel, sizeof(headerObject.bitsPerPixel));
        file.read(&headerObject.imageDescriptor, sizeof(headerObject.imageDescriptor));
        headers.push_back(headerObject);

        for (int i = 0; i < headerObject.width * headerObject.height; i++) {
            Pixel pixel;
            file.read((char *) &pixel.blue, sizeof(pixel.blue));
            file.read((char *) &pixel.green, sizeof(pixel.green));
            file.read((char *) &pixel.red, sizeof(pixel.red));
            headers[headers.size() - 1].pixels.push_back(pixel);
        }
    }
    file.close();
}

void printHeader(Header printMe){
    for(int i = 0; printMe.height*printMe.width;i++){
        cout << (int)printMe.pixels[i].blue<< " ";
        cout << (int)printMe.pixels[i].green<< " ";
        cout << (int)printMe.pixels[i].red;
        cout << endl;
    }
}

void createFile (string name, Header headerOut){
ofstream outfile(name, ios_base::binary);

outfile.write(&headerOut.idLength, sizeof(headerOut.idLength));
outfile.write(&headerOut.colorMapType, sizeof(headerOut.colorMapType));
outfile.write(&headerOut.dataTypeCode, sizeof(headerOut.dataTypeCode));
outfile.write((char*)&headerOut.colorMapOrigin, sizeof(headerOut.colorMapOrigin));
outfile.write((char*)&headerOut.colorMapLength, sizeof(headerOut.colorMapLength));
outfile.write(&headerOut.colorMapDepth, sizeof(headerOut.colorMapDepth));
outfile.write((char*)&headerOut.xOrigin, sizeof(headerOut.xOrigin));
outfile.write((char*)&headerOut.yOrigin, sizeof(headerOut.yOrigin));
outfile.write((char*)&headerOut.width, sizeof(headerOut.width));
outfile.write((char*)&headerOut.height, sizeof(headerOut.height));
outfile.write(&headerOut.bitsPerPixel, sizeof(headerOut.bitsPerPixel));
outfile.write(&headerOut.imageDescriptor, sizeof(headerOut.imageDescriptor));
    for(int i = 0; i < headerOut.width*headerOut.height; i++){
        outfile.write((char*)&headerOut.pixels[i].blue, sizeof(headerOut.pixels[i].blue));
        outfile.write((char*)&headerOut.pixels[i].green, sizeof(headerOut.pixels[i].green));
        outfile.write((char*)&headerOut.pixels[i].red, sizeof(headerOut.pixels[i].red));
    }
}

Header multiply(Header a, Header b){
    Header headerOut;
    headerOut = headers[0];
    for(int i = 0; i < headers[0].width*headers[0].height; i++){
        float max = 255;
        float add = 0.5;
        float blue1 = a.pixels[i].blue/max;
        float blue2 = b.pixels[i].blue/max;

        float green1= a.pixels[i].green/max;
        float green2 = b.pixels[i].green/max;

        float red1 = a.pixels[i].red/max;
        float red2 = b.pixels[i].red/max;

        float blue = ((blue1 * blue2)*max) + add;
        float green = ((green1 * green2)*max) + add;
        float red = ((red1 * red2)*max) + add;

        headerOut.pixels[i].blue = (unsigned char)blue;
        headerOut.pixels[i].green = (unsigned char) green;
        headerOut.pixels[i].red = (unsigned char)red;
    }
    return headerOut;
}

Header subtract(Header a, Header b){
    Header headerOut;
    headerOut = headers[0];

    for(int i = 0; i < headers[0].width*headers[0].height; i++){
        int blue = (a.pixels[i].blue - b.pixels[i].blue);
        int green = (a.pixels[i].green - b.pixels[i].green);
        int red = (a.pixels[i].red - b.pixels[i].red);

        if(blue < 0){blue = 0;}
        if(green < 0){green = 0;}
        if(red < 0){red = 0;}

        headerOut.pixels[i].blue = (unsigned char)blue;
        headerOut.pixels[i].green = (unsigned char)green;
        headerOut.pixels[i].red = (unsigned char)red;
    }
    return headerOut;
}

Header screen(Header a, Header b){
    Header headerOut;
    headerOut = headers[0];

    for(int i = 0; i < headers[0].width*headers[0].height; i++){
        float max = 255;
        float add = 0.5;
        float blue1 = 1 - ((float)a.pixels[i].blue/max);
        float blue2 = 1 - ((float)b.pixels[i].blue/max);

        float green1= 1 - ((float)a.pixels[i].green/max);
        float green2 = 1 - ((float)b.pixels[i].green/max);

        float red1 = 1 - ((float)a.pixels[i].red/max);
        float red2 = 1-((float)b.pixels[i].red/max);

        float blue = ((1-((blue1) * (blue2)))*max) + add;
        float green = ((1-((green1) * (green2)))*max) + add;
        float red = ((1-((red1) * (red2)))*max) + add;

        headerOut.pixels[i].blue = (unsigned char)blue;
        headerOut.pixels[i].green = (unsigned char) green;
        headerOut.pixels[i].red = (unsigned char)red;
    }
    return headerOut;
}
Header overlay(Header a, Header b){
    Header headerOut;
    headerOut = headers[0];

    for(int i = 0; i < headers[0].width*headers[0].height; i++){
        float max = 255;
        float add = 0.5;
        float blue1 = a.pixels[i].blue/max;
        float blue2 = b.pixels[i].blue/max;

        float green1= a.pixels[i].green/max;
        float green2 = b.pixels[i].green/max;

        float red1 = a.pixels[i].red/max;
        float red2 = b.pixels[i].red/max;

        float blue;
        float green;
        float red;

        if (blue1 <= 0.5){
            blue = ((2*(blue1*blue2))*max)+add;
        }
        else{
            blue = ((1 - (2*((1-blue1)*(1-blue2))))*max)+add;
        }

        if (green1 <= 0.5){
            green = ((2*(green1*green2))*max)+add;
        }
        else{
            green = ((1 - (2*((1-green1)*(1-green2))))*max)+add;
        }

        if (red1 <= 0.5){
            red = ((2*(red1*red2))*max)+add;
        }
        else{
            red = ((1 - (2*((1-red1)*(1-red2))))*max)+add;
        }

        if(blue < 0){blue = 0;}
        if(green < 0){green = 0;}
        if(red < 0){red = 0;}

        headerOut.pixels[i].blue = (unsigned char)blue;
        headerOut.pixels[i].green = (unsigned char)green;
        headerOut.pixels[i].red = (unsigned char)red;
    }
    return headerOut;
}

Header add(Header a, int amountBlue, int amountGreen, int amountRed){
    Header headerOut;
    headerOut = headers[0];

    for(int i = 0; i < headers[0].width*headers[0].height;i++){
        int blue  = a.pixels[i].blue + amountBlue;
        int green = a.pixels[i].green + amountGreen;
        int red = a.pixels[i].red + amountRed;

        if(blue > 255){blue = 255;}
        if(green > 255){green = 255;}
        if(red > 255){red = 255;}

        headerOut.pixels[i].blue = (unsigned char)blue;
        headerOut.pixels[i].green = (unsigned char)green;
        headerOut.pixels[i].red = (unsigned char)red;
    }
    return headerOut;
}

Header scale(Header a, int blueAmount, int greenAmount, int redAmount){
    Header headerOut;
    headerOut = headers[0];

    for(int i = 0; i < headers[0].width*headers[0].height;i++){
        float max = 255;
        float add = 0.5;
        float blue1 = a.pixels[i].blue/max;
        float green1= a.pixels[i].green/max;
        float red1 = a.pixels[i].red/max;

        float blue;
        float green;
        float red;

        blue = (blue1 * blueAmount * max)+add;
        green = (green1 * greenAmount * max)+add;
        red = (red1 * redAmount * max)+add;

        if(blue > 255){blue = 255;}
        if(green > 255){green = 255;}
        if(red > 255){red = 255;}

        headerOut.pixels[i].blue = (unsigned char)blue;
        headerOut.pixels[i].green = (unsigned char)green;
        headerOut.pixels[i].red = (unsigned char)red;
    }
    return headerOut;
}

void extractBlue(Header a){
    Header headerBlue;
    headerBlue = a;

    for(int i = 0; i < headers[0].width*headers[0].height;i++){
        headerBlue.pixels[i].green = headerBlue.pixels[i].blue;
        headerBlue.pixels[i].red = headerBlue.pixels[i].blue;
    }
    createFile("output/part8_b.tga", headerBlue);

}
void extractGreen(Header a){
    Header headerGreen;
    headerGreen = a;

    for(int i = 0; i < headers[0].width*headers[0].height;i++){
        headerGreen.pixels[i].blue = headerGreen.pixels[i].green;
        headerGreen.pixels[i].red = headerGreen.pixels[i].green;
    }
    createFile("output/part8_g.tga", headerGreen);

}
void extractRed(Header a){
    Header headerRed;
    headerRed = a;

    for(int i = 0; i < headers[0].width*headers[0].height;i++){
        headerRed.pixels[i].green = headerRed.pixels[i].red;
        headerRed.pixels[i].blue = headerRed.pixels[i].red;
    }
    createFile("output/part8_r.tga", headerRed);

}
void combine(Header b, Header g, Header r){
    Header headerOut;
    headerOut = b;

    for(int i = 0; i < headerOut.width*headerOut.height; i++){
        headerOut.pixels[i].green = g.pixels[i].green;
        headerOut.pixels[i].red = r.pixels[i].red;
    }
    createFile("output/part9.tga", headerOut);
}

void flip(Header a){
    Header headerOut;
    headerOut = a;
    int max = (a.height*a.width)-1;
    for(int i = 0; i < headerOut.width*headerOut.height;i++){
        headerOut.pixels[i].blue = a.pixels[max-i].blue;
        headerOut.pixels[i].green = a.pixels[max-i].green;
        headerOut.pixels[i].red = a.pixels[max-i].red;
    }
    createFile("output/part10.tga", headerOut);
}

bool checker(string one, string two, int numberPixels){
    bool check = true;
    ifstream compare(one, ios_base::binary);
    ifstream comparer(two, ios_base::binary);

    char oneChar;
    char twoChar;

    for(int i = 0; i < numberPixels+18; i++){
        compare.get(oneChar);
        comparer.get(twoChar);

        if (oneChar != twoChar){
            check = false;
            break;
        }
    }
    return check;
}

void checkPassed(Header a, Header b){
    string check = "Works";
    for(int i = 0; i < a.width*a.height;i++){
        if(a.pixels[i].blue == b.pixels[i].blue){
            cout << "Correct " << (int)a.pixels[i].blue<< " ";
        }
        else {
            check = "Fails";
            cout << "Failure "<< (int)a.pixels[i].blue << " " <<(int)b.pixels[i].blue<< " ";
        }

        if(a.pixels[i].green == b.pixels[i].green){
            cout << "Correct " << (int)a.pixels[i].green << " ";
        }
        else {
            check = "Fails";
            cout << "Failure "<< (int)a.pixels[i].green << " " <<(int)b.pixels[i].green<< " ";
        }

        if(a.pixels[i].red == b.pixels[i].red){
            cout << "Correct "<< (int)a.pixels[i].red;
        }
        else {
            check = "Fails";
            cout << "Failure "<< (int)a.pixels[i].red << " " <<(int)b.pixels[i].red;
        }
        cout << endl;
    }
    cout << check;
}
void scoreCount(){
    openFile("output/part1.tga");//header 0
    openFile("examples/EXAMPLE_part1.tga");//header 1

    openFile("output/part2.tga");//header 2
    openFile("examples/EXAMPLE_part2.tga");//header 3

    openFile("output/part3.tga");//header 4
    openFile("examples/EXAMPLE_part3.tga");//header 5

    openFile("output/part4.tga");//header 6
    openFile("examples/EXAMPLE_part5.tga");//header 7

    openFile("output/part5.tga");//header 8
    openFile("examples/EXAMPLE_part6.tga");//header 9

    openFile("output/part6.tga");//header 10
    openFile("examples/EXAMPLE_part6.tga");//header 11

    openFile("output/part7.tga");//header 12
    openFile("examples/EXAMPLE_part7.tga");//header 13

    openFile("output/part8_b.tga");//header 14
    openFile("examples/EXAMPLE_part8b.tga");//header 15

    openFile("output/part8_g.tga");//header 16
    openFile("examples/EXAMPLE_part8_g.tga");//header 17

    openFile("output/part8_r.tga");//header 18
    openFile("examples/EXAMPLE_part8r.tga");//header 19

    openFile("output/part9.tga");//header 20
    openFile("examples/EXAMPLE_part9.tga");//header 21

    openFile("output/part10.tga");//header 22
    openFile("examples/EXAMPLE_part10.tga");//header 23

    if(checker("output/part1.tga","examples/EXAMPLE_part1.tga", headers[0].width*headers[0].height)){
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore <<"\n" <<  endl;
    }else testCase++;

    if(checker("output/part2.tga","examples/EXAMPLE_part2.tga", headers[2].width*headers[2].height)) {
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore << "\n" << endl;
    }else testCase++;

    if(checker("output/part3.tga","examples/EXAMPLE_part3.tga", headers[4].width*headers[4].height)) {
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore << "\n" << endl;
    }else testCase++;

    if(checker("output/part4.tga","examples/EXAMPLE_part4.tga", headers[6].width*headers[6].height)) {
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore << "\n" << endl;
    }

    if(checker("output/part5.tga","examples/EXAMPLE_part5.tga", headers[8].width*headers[8].height)) {
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore << "\n" << endl;
    }else testCase++;

    if(checker("output/part6.tga","examples/EXAMPLE_part6.tga", headers[10].width*headers[10].height)) {
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore << "\n" << endl;
    }

    if(checker("output/part7.tga","examples/EXAMPLE_part7.tga", headers[12].width*headers[12].height)) {
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore << "\n" << endl;
    }else testCase++;

    if(checker("output/part8_b.tga","examples/EXAMPLE_part8_b.tga", headers[14].width*headers[14].height) &&
    checker("output/part8_g.tga","examples/EXAMPLE_part8_g.tga", headers[16].width*headers[16].height) &&
    checker("output/part8_r.tga","examples/EXAMPLE_part8_r.tga", headers[18].width*headers[18].height)){
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore <<"\n" <<  endl;

    }else testCase++;

    if(checker("output/part9.tga","examples/EXAMPLE_part9.tga", headers[20].width*headers[20].height)) {
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore << "\n" << endl;
    }else testCase++;

    if(checker("output/part10.tga","examples/EXAMPLE_part10.tga", headers[22].width*headers[22].height)) {
        cout << "Test Case " << testCase << " Passed" << endl;
        testCase++;
        totalScore = totalScore + 11;
        cout << "Current Score: " << totalScore << "/" << maxScore << "\n" << endl;
    }else testCase++;
}

void testCase1(){
    openFile("input/pattern1.tga");
    openFile("input/layer1.tga");
    createFile("output/part1.tga", multiply(headers[0], headers[1]));
    headers.clear();
}

void testCase2(){
    openFile("input/car.tga");
    openFile("input/layer2.tga");
    createFile("output/part2.tga", subtract(headers[0], headers[1]));
    headers.clear();
}

void testCase3(){
    openFile("input/pattern2.tga");
    openFile("input/layer1.tga");
    Header multiplied;
    multiplied = multiply(headers[0], headers[1]);
    headers.clear();
    openFile("input/text.tga");
    createFile("output/part3.tga", screen(multiplied,headers[0]));
    headers.clear();
}

void testCase4(){
    openFile("input/circles.tga");
    openFile("input/layer2.tga");
    Header multiplied;
    multiplied = multiply(headers[0], headers[1]);
    headers.clear();
    openFile("input/pattern2.tga");
    createFile("output/part4.tga", subtract(multiplied, headers[0]));
    headers.clear();
}

void testCase5(){
    openFile("input/pattern1.tga");
    openFile("input/layer1.tga");
    createFile("output/part5.tga", overlay(headers[0], headers[1]));
    headers.clear();

}

void testCase6(){
    openFile("input/car.tga");
    createFile("output/part6.tga", add(headers[0], 0, 200, 0));
    headers.clear();

}

void testCase7(){
    openFile("input/car.tga");
    createFile("output/part7.tga", scale(headers[0], 0, 1 ,4));
    headers.clear();
}

void testCase8(){
    openFile("input/car.tga");
    extractBlue(headers[0]);
    extractGreen(headers[0]);
    extractRed(headers[0]);
    headers.clear();

}

void testCase9(){
    openFile("input/layer_blue.tga");
    openFile("input/layer_green.tga");
    openFile("input/layer_red.tga");
    combine(headers[0],headers[1],headers[2]);
    headers.clear();

}

void testCase10(){
    openFile("input/text2.tga");
    flip(headers[0]);
    headers.clear();
}

int main() {
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    testCase5();
    testCase6();
    testCase7();
    testCase8();
    testCase9();
    testCase10();
    scoreCount();
    return 0;
}
