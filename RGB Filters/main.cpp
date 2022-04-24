// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: GS filters.cpp
// Last Modification Date: 4/22/2022
// Author1 and ID and Group: Bassem Wael Mohamed - 20210085 - S10
// Author2 and ID and Group: Omar Osama - 20211067 - s9
// Author3 and ID and Group: Maria Mohamed Bassam - 20210786 - s9
// Teaching Assistant: ENG. Afaf
// Purpose: training on 3d array , make useful filters and take our grades
#include <iostream>
#include <cstring>
#include <iomanip>
#include <iomanip>
#include "bmplib.cpp"
#include <cmath>
using namespace std;
unsigned char image [SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char image_qua1[SIZE][SIZE][RGB];
unsigned char image_qua2[SIZE][SIZE][RGB];
unsigned char image_qua3[SIZE][SIZE][RGB];
unsigned char image_qua4[SIZE][SIZE][RGB];
char chose;
void save_qua1 ();
void save_qua2 ();
void save_qua3 ();
void save_qua4 ();
void read();
void menu();
void save();
char merge();
char lighten_darken();
char blur ();
char shrink();
char Black_and_white();
char invert_image();
char Flip();
char rotate_image();
char edges();
char enlarge_image();
char mirror();
char  shuffle();
void check();
char enlarge_image();
//______________________________________________________

int main(){
    cout << "hello in filter program type file name to see filters\n";
    read();
    menu();
}

void menu(){
    cout << "__________________________________________________________________" << endl;
    cout<<"Filter Number" <<setw(15) << "|" <<setw(28) << "Filter Name" << endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8)<<"1"<<setw(20)<<"|"<<setw(35)<< "Black and white Filter"<< endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8)<<"2"<<setw(20)<<"|"<<setw(29)<< "Invert Image"<< endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8)<<"3"<<setw(20)<<"|"<<setw(32)<< "Merge Image Filter"<< endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8)<<"4"<<setw(20)<<"|"<<setw(29)<< "Flip image"<< endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8)<<"5"<<setw(20)<<"|"<<setw(30)<< "Rotate Image"<< endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8)<<"6"<<setw(20)<<"|"<<setw(36)<< "Darken_lighten Image"<< endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8)<<"7"<<setw(20)<<"|"<<setw(36)<< "Detect Image Edges"<< endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8) << "8" << setw(20) << "|" << setw(33) << "Enlarge Image"<<endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8) << "9" << setw(20) << "|" << setw(33) << "Shrink Image"<<endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8) << "a" << setw(20) << "|" << setw(33) << "Mirror Image"<<endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8) << "b" << setw(20) << "|" << setw(33) << "Shuffle Image"<<endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8) << "c" << setw(20) << "|" << setw(33) << "Blur Image"<<endl;
    cout << "_________________________________________________________________" << endl;
    cout << setw(8)<<"S"<<setw(20)<<"|"<<setw(33)<< "Save New Image"<< endl;
    cout << "_________________________________________________________________" << endl << endl;
    cin >> chose;
    chose = toupper(chose);
    while (true){
        if (chose =='1')
        {
            Black_and_white();
            break;
        }
        else if (chose == '2'){
            invert_image();
            break;
        }
        else if (chose == '3'){
            merge();
            break;
        }
        else if (chose == '4'){
            Flip();
            break;
        }
        else if (chose == '5'){
            char file [100];
            rotate_image();
            break;
        }
        else if (chose == '6'){
            lighten_darken();
            break;
        }
        else if (chose == '7'){
            edges();
            break;
        }
        else if (chose == '8'){
            enlarge_image();
            break;
        }
        else if (chose=='9') {
            shrink();
            break;
        }
        else if (chose == 'A'){
            mirror();
            break;
        }
        else if (chose == 'B'){
            shuffle();
            break;
        }
        else if (chose == 'C'){
            blur();
            break;
        }
        else if (chose == 'S'){
            save();
            break;
        }
        cout << "wrong input please type number of filter or press \'S\' to save your image";
        cin >> chose;
        toupper(chose);
    }

}

void read(){
    char file [100];
    cout << "enter file name";
    cin >> file;
    strcat(file,".bmp");
    readRGBBMP(file,image);
}

void save(){
    char file [100];
    cout << "enter file name you like to save it with";
    cin >> file;
    strcat(file,".bmp");
    writeRGBBMP(file,image);
}

char Black_and_white(){

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if (image [i][j][0]< 127 && image [i][j][1]< 127 && image [i][j][2]< 127)
                image [i][j][0]=image [i][j][1]=image [i][j][2]=0;
            else
                image [i][j][0]=image [i][j][1]=image [i][j][2]= 255;
        }
    }
    check();
    return image[SIZE][SIZE][RGB];
}

char Flip(){
    int s = SIZE/2;
    int n;
    cout << "flip horizontally--->1" << endl << "flip vertically--->2" << endl;
    cout << "choose 1 or 2: ";
    cin >> n;
    if(n == 1)
    {
        for(int m = 0; m < RGB; m++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                int k = SIZE;
                for (int j = 0; j< s; j++)
                {
                    swap(image[i][k][m],image[i][j][m]);
                    k--;
                }
            }
        }
    }

    else if(n == 2)
    {
        for(int m = 0; m < RGB; m++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                int k = SIZE;
                for (int i = 0; i< s; i++)
                {
                    swap(image[k][j],image[i][j]);
                    k--;
                }
            }
        }
    }
    check();
    return image[SIZE][SIZE][RGB];
}

char edges (){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if (image [i][j][0]< 127 && image [i][j][1]< 127 && image [i][j][2]< 127)
                image [i][j][0]=image [i][j][1]=image [i][j][2]=0;
            else
                image [i][j][0]=image [i][j][1]=image [i][j][2]= 255;
        }
    }
    unsigned char detect[SIZE][SIZE][3];
    for(int k = 0; k < 3 ; k++){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                detect[i][j][k] = image[i][j][k];
            }
        }
    }
    for(int k = 0 ; k < 3 ; k++){
        for (int i = 1; i < SIZE - 1; i++) {
            for (int j = 1; j < SIZE - 1; j++) {
                int x = 2*detect[i][j-1][k] - 2*detect[i][j+1][k] + detect[i-1][j-1][k] - detect[i-1][j+1][k] + detect[i+1][j-1][k] - detect[i+1][j+1][k];
                int y = 2*detect[i+1][j][k] - 2*detect[i-1][j][k] + detect[i+1][j-1][k] - detect[i-1][j-1][k] + detect[i+1][j+1][k] - detect[i-1][j+1][k];

                if (abs(x) > 600 || abs(y) > 600) {
                    image[i][j][k] = 0;
                }
                else {
                    image[i][j][k] = 255;
                }
            }
        }
    }
    check();
    return image[SIZE][SIZE][RGB];
}


char mirror(){
    int n;
    cout << "Upper 1/2 ---> 1" << endl << "Lower 1/2 ---> 2" << endl << "Right 1/2 ---> 3" << endl << "Left 1/2 ---> 4" <<endl;
    cout << "choose 1 , 2 , 3 or 4: ";
    cin >> n;
    if(n == 1)
    {
        int s = SIZE/2;

        for(int m = 0; m < RGB; m++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                int k = SIZE;
                for (int i = 0; i< s; i++)
                {
                    image[k][j][m]=image[i][j][m];
                    k--;
                }
            }
        }
    }
    else if(n == 2)
    {
        int s = SIZE/2;

        for(int m = 0; m < RGB; m++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                int k = SIZE;
                for (int i = 0; i< s; i++)
                {
                    image[i][j][m]=image[k][j][m];
                    k--;
                }
            }
        }
    }
    else if(n == 3)
    {
        int s = SIZE/2;

        for(int m = 0; m < RGB; m++)
        {
            for (int i = 0; i < SIZE; i++)
            {

                int k = SIZE;
                for (int j = 0; j < s; j++)
                {
                    image[i][j][m]=image[i][k][m];
                    k--;
                }
            }
        }
    }
    else if(n == 4)
    {
        int s = SIZE/2;

        for(int m = 0; m < RGB; m++)
        {
            for (int i = 0; i < SIZE; i++)
            {

                int k = SIZE;
                for (int j = 0; j < s; j++)
                {
                    image[i][k][m]=image[i][j][m];
                    k--;
                }
            }
        }
    }
    check();
    return image[SIZE][SIZE][RGB];
}


char merge(){
    char file[100];
    cout << "enter image 2 name";
    cin >> file;
    strcat(file,".bmp");
    readRGBBMP(file,image2);
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j][0]= (image[i][j][0] + image2[i][j][0])/2;
            image[i][j][1]= (image[i][j][1] + image2[i][j][1])/2;
            image[i][j][2]= (image[i][j][2] + image2[i][j][2])/2;

        }

    }
    check();
    return image[SIZE][SIZE][RGB];

}

char lighten_darken() {
    cout << "please if you want darken enter >>> 1 \n lighten >>> 2";
    char chose;
    cin >> chose;
    while (true) {
        if(chose == '1') {
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    image[i][j][0] = image[i][j][0] / 2;
                    image[i][j][1] = image[i][j][1] / 2;
                    image[i][j][2] = image[i][j][2] / 2;
                }

            }
            break;
        }
        else if (chose == '2'){
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    image[i][j][0] = (image[i][j][0] / 2)+127;
                    image[i][j][1] = (image[i][j][1] / 2)+127;
                    image[i][j][2] = (image[i][j][2] / 2)+127;
                }

            }
            break;
        }
        cout << "wrong input please press only 1 for darken filter \n 2 for lighten filter";
        cin >> chose;

    }
    check();
    return image[SIZE][SIZE][RGB];
}

char blur () {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {

            image[i][j][0]=(image[i][j][0]+image[i][j+1][0]+image[i][j-1][0]+image[i][j+2][0]+image[i][j-2][0]
                            +image[i+1][j][0]+ image[i+1][j+1][0]+image[i+1][j-1][0]+image[i+1][j+2][0]+image[i+1][j-2][0]
                            +image[i-1][j][0]+image[i-1][j+1][0]+image[i-1][j-1][0]+image[i-1][j+2][0]+image[i-1][j-2][0])/15;
            image[i][j][1] = (image[i][j][1]+image[i][j+1][1]+image[i][j-1][1]+image[i][j+2][1]+image[i][j-2][1]
                              +image[i+1][j][1]+ image[i+1][j+1][1]+image[i+1][j-1][1]+image[i+1][j+2][1]+image[i+1][j-2][1]
                              +image[i-1][j][1]+image[i-1][j+1][1]+image[i-1][j-1][1]+image[i-1][j+2][1]+image[i-1][j-2][1])/15;
            image[i][j][2]= (image[i][j][2]+image[i][j+1][2]+image[i][j-1][2]+image[i][j+2][2]+image[i][j-2][2]
                             +image[i+1][j][2]+ image[i+1][j+1][2]+image[i+1][j-1][2]+image[i+1][j+2][2]+image[i+1][j-2][2]
                             +image[i-1][j][2]+image[i-1][j+1][2]+image[i-1][j-1][2]+image[i-1][j+2][2]+image[i-1][j-2][2])/15;
        }

    }
    check();
    return image[SIZE][SIZE][RGB];

}
char shrink (){
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            for (int k = 0; k < RGB; ++k) {
                image2[i][j][k]=255;

            }

        }

    }
    char choose;
    cout << "if you want to make shrink \n 1- 1/2\n 2- 1/3 \n 3- 1/4 \n";
    cin >> choose;
    if(choose == '1'){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image2[i/2][j/2][0] =
                        (image[i][j][0] + image[i + 1][j][0] + image[i][j + 1][0] + image[i + 1][j + 1][0]) / 4;
                image2[i/2][j/2][1] =
                        (image[i][j][1] + image[i + 1][j][1] + image[i][j + 1][1] + image[i + 1][j + 1][1]) / 4;
                image2[i/2][j/2][2] =
                        (image[i][j][2] + image[i + 1][j][2] + image[i][j + 1][2] + image[i + 1][j + 1][2]) / 4;
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < RGB; ++k) {
                    image[i][j][k]=image2[i][j][k];
                }

            }

        }

    }
    else if (choose == '2'){

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {

                image2[i/3][j/3][0] =
                        (image[i][j][0] + image[i + 1][j][0] + image[i][j + 1][0] + image[i + 1][j + 1][0]) / 4;
                image2[i/3][j/3][1] =
                        (image[i][j][1] + image[i + 1][j][1] + image[i][j + 1][1] + image[i + 1][j + 1][1]) / 4;
                image2[i/3][j/3][2] =
                        (image[i][j][2] + image[i + 1][j][2] + image[i][j + 1][2] + image[i + 1][j + 1][2]) / 4;
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < RGB; ++k) {
                    image[i][j][k]=image2[i][j][k];
                }

            }

        }

    }
    else if (choose == '3'){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image2[i/4][j/4][0] = (image[i][j][0]+image[i+1][j][0]+image[i][j+1][0]+image[i+1][j+1][0])/4;
                image2[i/4][j/4][1] = (image[i][j][1]+image[i+1][j][1]+image[i][j+1][1]+image[i+1][j+1][1])/4;
                image2[i/4][j/4][2] = (image[i][j][2]+image[i+1][j][2]+image[i][j+1][2]+image[i+1][j+1][2])/4;
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < RGB; ++k) {
                    image[i][j][k]=image2[i][j][k];
                }

            }

        }
    }


    check();
    return image[SIZE][SIZE][RGB];
}

char rotate_image(){
    char deg_rotate;
    //choice the degree of rotate that the user wants
    cout << "input degree Rotate: \n"
            "if you want rotate the image by 90 degree input 1 , \n "
            "if you want rotate the image by 180 degree input 2 , \n "
            "if you want rotate the image by 270 degree input 3  \n" << endl;
    cin >> deg_rotate;
    // rotate image by 90 degrees
    if (deg_rotate == '1') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < 3; k++) {
                    image2[i][j][k] = image[SIZE - j][ i][k];

                }
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < RGB; ++k) {
                    image[i][j][k] = image2[i][j][k];

                }

            }

        }
    }
// rotate image by  180 degree
    else if(deg_rotate == '2'){
        for(int i = 0 ; i < SIZE ; i++){
            for(int j = 0 ; j <SIZE/2 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    swap(image[i][j][k], image[SIZE - i][SIZE - 1 -j][ k]);
                }
            }
        }
    }
        //rotate image by 270 degree
    else if (deg_rotate == '3'){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image2[i][j][0]  =  image[j][255 - i][0];
                    image2[i][j][1]  =  image[j][255 - i][1];
                    image2[i][j][2]  =  image[j][255 - i][2];

                }

            }
        }
        for (int i = 0 ; i < SIZE ; i++){
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image[i][j][k] = image2[i][j][k];

                }

            }
        }
    }
    check();
    return image[SIZE][SIZE][RGB];
}

char enlarge_image(){
    char qua;
    cout << "if you want enlarging the upper Quarter choice (1) \n "
            "if you want enlarging the lower Quarter choice (2) \n "
            "if you want enlarging the left Quarter choice (3)  \n  "
            "if you want enlarging the right Quarter choice (4) \n";
    cin >> qua;
    if (qua == '1') {
        for (int row = 0  ; row < SIZE  ; row++ ) {
            for (int col = 0 ; col < SIZE  ;col++){
                for (int k = 0; k <RGB ; ++k) {



                    image2[row][col][k] = image[row / 2][col / 2][k];
                }
            }
        }
    }
    else if (qua =='2'){
        for (int row=0 ; row < SIZE ; row++){
            for (int col = 0 ; col < SIZE ; col++){
                for (int k = 0; k <RGB ; ++k) {
                    /*equated the new image with the old image and divide the row of the old image by 2
                * and the column of the old image by 2 and worked (col / 2 ) + 128 to get the right upper quarter.
                */
                    image2[row][col][k] = image[row / 2][(col / 2) + 127][k];
                }
            }
        }
    }
    else if (qua == '3'){
        for(int row = 0; row < SIZE ; row++){
            for (int col = 0; col < SIZE ; col++){
                for (int k = 0; k <RGB ; ++k) {
                    /*equated the new image with the old image and divide the row of the old image by 2
                * and the column of the old image by 2 and worked (row / 2 ) +128 to get the left lower quarter.
                */
                    image2[row][col][k] = image[(row / 2) + 127][col / 2][k];
                }
            }
        }
    }
    else if (qua == '4'){
        for (int row = 0 ; row< SIZE ; row++ ){
            for(int col = 0 ; col <SIZE ;col++){
                for (int k = 0; k <RGB ; ++k) {
                    /*equated the new image with the old image and divide the row of the old image by 2
                 * and the column of the old image by 2
                 * and worked (row / 2 ) + 128 , (col / 2 ) + 128 to get the right lower quarter.
                 */
                    image2[row][col][k] = image[(row/2 ) + 127][(col/2 ) + 127][k];
                }
            }
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                image[i][j][k]=image2[i][j][k];

            }

        }

    }
    check();
    return image[SIZE][SIZE][RGB];
}

char shuffle() {
    char part1, part2, part3, part4;
    cout << "enter  any order you likes \n";
    cin >> part1 >> part2 >> part3 >> part4;
    save_qua1();
    save_qua2();
    save_qua3();
    save_qua4();
    // (if part1 )  in order to As entered by the user at the first part of the image
    if (part1 == '1') {

        // "r and c " two variable to save the quarter of the image and rearrange  the image.
        int x = 0, y = 0;
        for (int row = 0; row < SIZE / 2; row++) {
            for (int col = 0; col < SIZE / 2; col++) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua1[x][y++][k];

                }
            }
            x++;
            y = 0;
        }
    }
    if (part1 == '2') {
        int x = 0, y = 0;
        for (int row = 0; row < SIZE / 2; row++) {
            for (int col = 0; col < SIZE / 2; col++) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua2[x][y++][k];

                }
            }
            x++;
            y = 0;
        }
    }
    if (part1 == '3') {
        int x = 0, y = 0;
        for (int row = 0; row < SIZE / 2; row++) {
            for (int col = 0; col < SIZE / 2; col++) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua3[x][y++][k];

                }
            }
            x++;
            y = 0;
        }
    }
    if (part1 == '4') {
        int x = 0, y = 0;
        for (int row = 0; row < SIZE / 2; row++) {
            for (int col = 0; col < SIZE / 2; col++) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua4[x][y++][k];

                }
            }
            x++;
            y = 0;
        }
    }
    // (if part2 )  in order to As entered by the user at the second part of the image
    if (part2 == '1') {
        int x = 0, y = 0;
        for (int row = 0; row < SIZE / 2; row++) {
            for (int col = 128; col < SIZE; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua1[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    if (part2 == '2') {
        int x = 0, y = 0;
        for (int row = 0; row < SIZE / 2; row++) {
            for (int col = 128; col < SIZE; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua2[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    if (part2 == '3') {
        int x = 0, y = 0;
        for (int row = 0; row < SIZE / 2; row++) {
            for (int col = 128; col < SIZE; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua3[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    if (part2 == '4') {
        int x = 0, y = 0;
        for (int row = 0; row < SIZE / 2; row++) {
            for (int col = 128; col < SIZE; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua4[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    // (if part3 )  in order to As entered by the user at the third part of the image
    if (part3 == '1') {
        int x = 0, y = 0;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 0; col < SIZE / 2; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua1[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    if (part3 == '2') {
        int x = 0, y = 0;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 0; col < SIZE / 2; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua2[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    if (part3 == '3') {
        int x = 0, y = 0;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 0; col < SIZE / 2; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua3[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    if (part3 == '4') {
        int x = 0, y = 0;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 0; col < SIZE / 2; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua4[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    // (if part4 )  in order to As entered by the user at the fourth part of the image
    if (part4 == '1') {
        int x = 0, y = 0;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 128; col < SIZE; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua1[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    if (part4 == '2') {
        int x = 0, y = 0;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 128; col < SIZE; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua2[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    if (part4 == '3') {
        int x = 0, y = 0;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 128; col < SIZE; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua3[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }
    if (part4 == '4') {
        int x = 0, y = 0;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 128; col < SIZE; ++col) {
                for (int k = 0; k < RGB; ++k) {
                    image[row][col][k] = image_qua4[x][y++][k];
                }
            }
            x++;
            y = 0;
        }
    }

    // if the user input a char > '4'
    while (part1 > '4' || part2 > '4' || part3 > '4' || part4 > '4'){
        cout << "One of the values entered is not a valid.\n"
                "please enter a valid value: \n";
        cin >>part1 >> part2 >>part3 >> part4;
    }
    save_qua1();
    save_qua2();
    save_qua3();
    save_qua4();
    check();
    return image[SIZE][SIZE][RGB];
}
void save_qua1 (){

    // "r and c " two variable to save the quarter of the image and rearrange  the image
    int r = 0 , c = 0 ;
    for (int row = 0; row < SIZE/2; ++row) {
        for (int col = 0; col < SIZE / 2; ++col) {
            for (int k = 0; k < RGB; ++k) {

                image_qua1[r][c++][k] = image[row][col][k];
            }
        }
        r++;
        c = 0;
    }
}

//this function for the second quarter of the image
void save_qua2 () {

    // "r and c " two variable to save the quarter of the image and rearrange  the image
    int r = 0, c = 0;
    for (int row = 0; row < SIZE / 2; ++row) {
        for (int col = 128; col < SIZE; ++col) {
            for (int k = 0; k < RGB; ++k) {

                image_qua2[r][c++][k] = image[row][col][k];
            }
        }
        r++;
        c = 0;

    }
}

// this function for the third quarter of the image
void save_qua3 () {

    // "r and c " two variable to save the quarter of the image and rearrange  the image
    int r = 0, c = 0;
    for (int row = 128 ; row < SIZE ; ++row) {
        for (int col = 0; col < SIZE/2; ++col) {
            for (int k = 0; k < RGB; ++k) {
                image_qua3[r][c++][k] = image[row][col][k];
            }
        }
        r++;
        c = 0;

    }
}
// this function for the fourth quarter of the image
void save_qua4 (){

    // "r and c " two variable to save the quarter of the image and rearrange  the image
    int r = 0, c = 0;
    for (int row = 128 ; row < SIZE ; ++row) {
        for (int col = 128; col < SIZE; ++col) {
            for (int k = 0; k < RGB; ++k) {
                image_qua4[r][c++][k] = image[row][col][k];
            }
        }
        r++;
        c = 0;

    }
}


char invert_image(){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for(int k= 0 ; k <3; k++) {
                // to invert image
                image[i][j][k] = 255 - image[i][j][k];
            }

        }
    }
    check();
    return image[SIZE][SIZE][RGB];
}

void check()
{
    cout << "do you want to save your image press S to save Or type M to make more filters";
    cin >> chose;
    chose = toupper(chose);
    while(true){
        if (chose == 'S'){
            save();
            break;
        }
        else if (chose == 'M'){
            menu();
            break;
        }
        cout << "wrong input please press S key to save or M to show menu\n";
        cin >>
            chose;
        chose = toupper(chose);
    }
}
