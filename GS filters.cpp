// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: GS filters.cpp
// Last Modification Date: 4/22/2022
// Author1 and ID and Group: Bassem Wael Mohamed - 20210085 - S10
// Author2 and ID and Group: Omar Osama - 20211067 - s9
// Author3 and ID and Group: Maria Mohamed Bassam - 20210786 - s9
// Teaching Assistant: ENG. Afaf
// Purpose: training on 2d array , make useful filters and take our grades
#include <iostream>
#include <cstring>
#include <iomanip>
#include "bmplib.cpp"
using namespace std;
unsigned char image [SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image_qua1[SIZE][SIZE];
unsigned char image_qua2[SIZE][SIZE];
unsigned char image_qua3[SIZE][SIZE];
unsigned char image_qua4[SIZE][SIZE];
char chose;
void menu();
void check();
char Black_and_white();
char Flip();
char rotate_image();
char invert_image();
char merge();
char lighten_darken();
char edges();
char mirror();
char enlarge_image();
char blur();
char shrink();
char shuffle();
void save_qua1 ();
void save_qua2 ();
void save_qua3 ();
void save_qua4 ();
void read();
void save();

int main(){
    cout << "hello in filter program type file name to see filters\n";
    read();
    cout << "Hello in smaller Photoshop to do any filter just press its number\n\n";
    menu();

}
void menu(){
   cout << "______________________" << endl;
    cout<<"Filter Number" <<setw(15) << "|" <<setw(28) << "Filter Name" << endl;
    cout << "_______________________" << endl;
    cout << setw(8)<<"1"<<setw(20)<<"|"<<setw(35)<< "Black and White Filter"<< endl;
    cout << "_______________________" << endl;
    cout << setw(8)<<"2"<<setw(20)<<"|"<<setw(29)<< "Invert Image"<< endl;
    cout << "_______________________" << endl;
    cout << setw(8)<<"3"<<setw(20)<<"|"<<setw(32)<< "Merge Image Filter"<< endl;
    cout << "_______________________" << endl;
    cout << setw(8)<<"4"<<setw(20)<<"|"<<setw(29)<< "Flip Image"<< endl;
    cout << "_______________________" << endl;
    cout << setw(8)<<"5"<<setw(20)<<"|"<<setw(30)<< "Rotate Image"<< endl;
    cout << "_______________________" << endl;
    cout << setw(8)<<"6"<<setw(20)<<"|"<<setw(36)<< "Darken_lighten Image"<< endl;
    cout << "_______________________" << endl;
    cout << setw(8)<<"7"<<setw(20)<<"|"<<setw(36)<< "Detect the edges Filter"<< endl;
    cout << "_______________________" << endl;
    cout << setw(8) << "8" << setw(20) << "|" << setw(33) << "Enlarge Image"<<endl;
    cout << "_______________________" << endl;
    cout << setw(8) << "9" << setw(20) << "|" << setw(33) << "Shrink Image"<<endl;
    cout << "_______________________" << endl;
    cout << setw(8) << "a" << setw(20) << "|" << setw(33) << "Mirror Image"<<endl;
    cout << "_______________________" << endl;
    cout << setw(8) << "b" << setw(20) << "|" << setw(33) << "Shuffle Image"<<endl;
    cout << "_______________________" << endl;
    cout << setw(8) << "c" << setw(20) << "|" << setw(33) << "Blur Image"<<endl;
    cout << "_______________________" << endl;
    cout << setw(8)<<"S"<<setw(20)<<"|"<<setw(33)<< "Save New Image"<< endl;
    cout << "_______________________" << endl << endl;
    cin >> chose;
    chose = toupper(chose);
    //choose which filter you want to use
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
            char file [100];
            cout << "enter name of image 2: " ;
            cin >>file;
            strcat(file,".bmp");
            readGSBMP(file,image2); //read second image
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

char Black_and_white(){
    long avg = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            avg +=image[i][j]; //loop in image to find average
        }
    }
    avg /=(SIZE * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {

            if (image[i][j] > avg)
                image[i][j] = 255; //every pixel greater than average turns white
            else
                image[i][j] = 0; //every pixel less than average turns black
        }
    }
    check();
    return image[SIZE][SIZE];
}
char Flip(){ int s = SIZE/2;
    string n;
    cout << "flip horizontally--->1" << endl << "flip vertically--->2" << endl;
    cout << "choose 1 or 2: ";
    cin >> n;
    while (true) {
        if (n == "1") {
            for (int i = 0; i < SIZE; i++) {
                int k = SIZE;
                for (int j = 0; j < s; j++) {
                    swap(image[i][k],
                         image[i][j]);//loop in the image and swap every pixel in the image with the corresponding pixel in the end of the row
                    k--;
                }

            }
            break;
        }
        else if (n == "2") {
            for (int j = 0; j < SIZE; j++) {

                int k = SIZE;
                for (int i = 0; i < s; i++) {
                    swap(image[k][j],
                         image[i][j]); //loop in the image and swap every pixel in the image with the corresponding pixel in the end of the column
                    k--;
                }
            }
            break;
        }
        cout << "wrong input please enter only 1 or 2 \n";
        cin >> n;
    }
    check();
    return image[SIZE][SIZE];

}

char rotate_image()
{
    char deg_rotate;
    //choice the degree of rotate that the user wants
    cout << "input degree Rotate: \n"
            "if you want rotate the image by 90 degree input 1 , \n "
            "if you want rotate the image by 180 degree input 2 , \n "
            "if you want rotate the image by 270 degree input 3  \n" << endl;
    cin >> deg_rotate;
    //rotate image by 90 degree
    for (int row = 0; row < SIZE; row += 1) {
        for (int col = row; col < SIZE; col += 1) {
            if (deg_rotate == '1') {
                // swap the value between rows and columns so that the row index of an element
                // becomes the column index and vice versa.
                // so swap the element at position image[row][col] with the element at image[col][row].
                swap(image[row][col], image[col][row]);
            }

        }
    }
    // rotate image by  180 degree
    if (deg_rotate == '2') {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                swap(image[i][j], image[255- i][255 -j]);
            }
        }

    }
    //rotate image by 270 degree
    if (deg_rotate == '3') {
        for (int i = 0; i < SIZE; i++) {
            for (int j = i; j < SIZE; j++) {
                swap(image[i][j], image[j][i]);

            }
        }
        int i = 0, j = 0;
        //reverse the transposed image by column
        // execute two nested loops: the outer loop scans each column from 0 to SIZE-1,
        // while the inner loop swaps the values in each column.
        for (int col = 0; col < SIZE; col++) {
            i = 0;
            j = SIZE - 1;
            for (; i < j; i += 1, j -= 1) {
                swap(image[i][col], image[j][col]);
            }

        }
    }
    check();
    return image[SIZE][SIZE];
}

char merge (){
    int avg;
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            avg = (image[i][j]+image2[i][j])/2; //get average of the two images
            image[i][j] = avg;
        }
    }
   check();
    return image[SIZE][SIZE];
}

char lighten_darken() {
    cout << "please press 1 >>> to make lighten filter \n 2 >>> to make darken filter ";
    cin >> chose;
    while (true) {
        if (chose == '1') {
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    image[i][j] = (image[i][j] / 2) + 127; //loop in image to increase every pixel

                }

            }
            break;
        } else if (chose == '2') {
            for (int i = 0; i < SIZE; ++i) {
                for (int j = 0; j < SIZE; ++j) {
                    image[i][j] = image[i][j] / 2; //loop in image to decrease every pixel

                }

            }
            break;
        }
        cout << "wrong input please enter only number \'1\' to make lighten filter\n"
                " number\'2\' to make darken filter\n";
        cin >> chose;

    }

    check();
    return image[SIZE][SIZE];

}

char edges()
{
    long avg = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            avg +=image[i][j];//loop in image to find average
        }
    }
    avg /=(SIZE * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            if (image[i][j] > avg)
            {
                image[i][j] = 255;//every pixel greater than average turns white
            }
            else
            {
                image[i][j] = 0;//every pixel less than average turns black
            }
        }
  }
	unsigned char detect[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			detect[i][j] = image[i][j]; //equalize the two images
		}
	}

	for (int i = 1; i < SIZE - 1; i++) {
		for (int j = 1; j < SIZE - 1; j++) {
			int x = 2*detect[i][j-1] - 2*detect[i][j+1] + 2*detect[i-1][j-1] - 2*detect[i-1][j+1] + 2*detect[i+1][j-1] - 2*detect[i+1][j+1];
			int y = 2*detect[i+1][j] - 2*detect[i-1][j] + 2*detect[i+1][j-1] - 2*detect[i-1][j-1] + 2*detect[i+1][j+1] - 2*detect[i-1][j+1];

			if (abs(x) > 600 || abs(y) > 600) {
				image[i][j] = 0; // if abs(x) or abs(y) > 600 we equal it to 0
			}
			else {
				image[i][j] = 255; // if neither abs(x) nor abs(y) are greater than 600 we equal it to 255
			}
		}
	}
	check();
    return image[SIZE][SIZE];
}

char mirror()
{
    int n;
    cout << "Upper 1/2 ---> 1" << endl << "Lower 1/2 ---> 2" << endl << "Right 1/2 ---> 3" << endl << "Left 1/2 ---> 4" <<endl;
    cout << "choose 1 , 2 , 3 or 4: ";
    cin >> n;
    if(n == 1)
    {
        	int s = SIZE/2;

      for (int j = 0; j < SIZE; j++)
        {

            int k = SIZE;
            for (int i = 0; i< s; i++)
            {
                image[k][j]=image[i][j]; //loop in every row in image till the half and equal every pixel with the adjacent one till we reach half the image
                k--;
            }
        }
    }
    else if(n == 2)
    {
            int s = SIZE/2;

    for (int j = 0; j < SIZE; j++)
    {

        int k = SIZE;
        for (int i = 0; i< s; i++)
        {
            image[i][j]=image[k][j];//loop in every row in image till the half and equal every adjacent pixel with the one that has the turn till we reach half the image
            k--;
        }
    }
    }
    else if(n == 3)
    {
            int s = SIZE/2;

    for (int i = 0; i < SIZE; i++)
    {

        int k = SIZE;
        for (int j = 0; j < s; j++)
        {
            image[i][j]=image[i][k];//loop in every column in image till the half and equal every pixel with the adjacent one till we reach half the image

            k--;
        }
    }
    }
    else if(n == 4)
    {
            int s = SIZE/2;

    for (int i = 0; i < SIZE; i++)
    {

        int k = SIZE;
        for (int j = 0; j < s; j++)
        {
            image[i][k]=image[i][j];//loop in every column in image till the half and equal every adjacent pixel with the one that has the turn till we reach half the image

            k--;
        }
    }
    }
    check();
    return image[SIZE][SIZE];
}

char blur() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=
            (image[i][j]+image[i][j+1]+image[i][j-1]+image[i][j+2]+image[i][j-2]+image[i+1][j]+image[i+1][j+1]+image[i+1][j-1]+image[i+1][j+2]+image[i+1][j-2]+image[i-1][j]+image[i-1][j-1]+image[i-1][j+1]+image[i-1][j+2]+image[i-1][j-2])/15;
// add all pixels around the pixel we want
        }
    }
    check();
    return image[SIZE][SIZE];
    }


char invert_image(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            // to invert image
            image[i][j] = 255 - image[i][j];


        }
    }
    check();
    return image[SIZE][SIZE];
}

char enlarge_image()
{
    unsigned char new_image[SIZE][SIZE];
    char qua;
    cout << "if you want enlarging the left upper  Quarter choice (1) \n "
            "if you want enlarging the right upper Quarter choice (2) \n "
            "if you want enlarging the left lower Quarter choice (3)  \n  "
            "if you want enlarging the right lower Quarter choice (4) \n";
    cin >> qua;
    //enlarging the left upper quarter .
    if (qua == '1') {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                /*equated the new image with the old image and divide the row of the old image by 2
                 * and the column of the old image by 2  to get the left upper quarter .
                 */
                    new_image[row][col] = image[row /2][col / 2];
            }
        }
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                image[row][col] = new_image[row][col];
            }
            }
    }
    else if (qua =='2'){
        for (int row=0 ; row < SIZE ; row++){
            for (int col = 0 ; col < SIZE ; col++) {
                /*equated the new image with the old image and divide the row of the old image by 2
                * and the column of the old image by 2 and worked (col / 2 ) + 128 to get the right upper quarter.
                */
                    new_image[row][col] = image[row / 2][(col / 2) + 128];

            }
        }
        for (int row=0 ; row < SIZE ; row++){
            for (int col = 0 ; col < SIZE ; col++) {
                    image[row][col] = new_image[row][col];
            }
        }
    }
    else if (qua == '3'){
        for(int row = 0; row < SIZE ; row++){
            for (int col = 0; col < SIZE ; col++){
                /*equated the new image with the old image and divide the row of the old image by 2
                * and the column of the old image by 2 and worked (row / 2 ) +128 to get the left lower quarter.
                */
                    new_image[row][col] = image[(row / 2) + 128][col / 2];

            }
        }
        for(int row = 0; row < SIZE ; row++){
            for (int col = 0; col < SIZE ; col++){
                    image[row][col] = new_image[row][col];
            }
        }
    }
    else if (qua == '4'){
        for (int row = 0 ; row< SIZE ; row++ ){
            for(int col = 0; col <SIZE ;col++){
                /*equated the new image with the old image and divide the row of the old image by 2
                 * and the column of the old image by 2
                 * and worked (row / 2 ) + 128 , (col / 2 ) + 128 to get the right lower quarter.
                 */
                    new_image[row][col] = image[(row / 2) + 128 ][(col / 2 ) +128 ];

            }
        }
        for (int row = 0 ; row< SIZE ; row++ ){
            for(int col = 0; col <SIZE ;col++){
                image[row][col] = new_image[row][col];
            }
        }
    }
    check();
    return image[SIZE][SIZE];
}
char shuffle()
{
    char part1 , part2 , part3 , part4;
    cout << "enter  any order you likes \n";
    cout << "Enter the first quadrant you want, then the second quadrant ,"
            "then the third quarter , then the fourth quarter \n";
    cout << " if you want the first quarter press (1) \n if you want the second quarter press (2) \n"
            "if you want the third quarter press (3) \n if you want the fourth quarter press (4)\n";
    cin >> part1 >>part2>>part3>>part4;
    save_qua1();
    save_qua2();
    save_qua3();
    save_qua4();
    // (if part1 )  in order to As entered by the user at the first part of the image
    if (part1 == '1'){
        // "r and c " two variable to save the quarter of the image and rearrange  the image.
        int r = 0 , c = 0 ;
        for (int row = 0 ; row < SIZE/2 ; row++){
            for (int col = 0; col < SIZE/2; col++) {

                image[row][col] = image_qua1[r][c++];

            }
            r++;
            c=0;
        }
    }
    if (part1 == '2'){
        int r = 0 , c = 0 ;
        for (int row = 0 ; row < SIZE/2 ; row++){
            for (int col = 0; col < SIZE/2; col++) {
                image[row][col] = image_qua2[r][c++];

            }
            r++;
            c = 0 ;
        }
    }
    if ( part1 == '3'){
        int r = 0 , c = 0 ;
        for (int row = 0 ; row < SIZE/2 ; row++){
            for (int col = 0; col < SIZE/2; col++) {
                image[row][col] = image_qua3[r][c++];

            }
            r++;
            c = 0;
        }
    }
    if (part1 == '4'){
        int r = 0 , c = 0 ;
        for (int row = 0 ; row < SIZE/2 ; row++){
            for (int col = 0; col < SIZE/2; col++) {
                image[row][col] = image_qua4[r][c++];

            }
            r++;
            c = 0 ;
        }
    }
    // (if part2 )  in order to As entered by the user at the second part of the image
    if (part2 == '1'){
        int r = 0 , c = 0 ;
        for (int row = 0; row < SIZE/2; row++) {
            for (int col = 128 ; col <SIZE ; ++col) {
                image[row][col] = image_qua1[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    if( part2 == '2'){
        int r = 0 , c = 0 ;
        for (int row = 0; row < SIZE/2; row++) {
            for (int col = 128 ; col <SIZE ; ++col) {
                image[row][col] = image_qua2[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    if(part2 == '3'){
        int r = 0 , c = 0 ;
        for (int row = 0; row < SIZE/2; row++) {
            for (int col = 128 ; col <SIZE ; ++col) {
                image[row][col] = image_qua3[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    if ( part2 == '4'){
        int r = 0 , c = 0 ;
        for (int row = 0; row < SIZE/2; row++) {
            for (int col = 128 ; col <SIZE ; ++col) {
                image[row][col] = image_qua4[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    // (if part3 )  in order to As entered by the user at the third part of the image
    if (part3 == '1'){
        int r = 0 , c = 0 ;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 0 ; col <SIZE/2 ; ++col) {
                image[row][col] = image_qua1[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    if (part3 == '2'){
        int r = 0 , c = 0 ;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 0 ; col <SIZE/2 ; ++col) {
                image[row][col] = image_qua2[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    if ( part3 == '3'){
        int r = 0 , c = 0 ;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 0 ; col <SIZE/2 ; ++col) {
                image[row][col] = image_qua3[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    if(part3 == '4') {
        int r = 0, c = 0;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 0; col < SIZE / 2; ++col) {
                image[row][col] = image_qua4[r][c++];
            }
            r++;
            c = 0;
        }
    }
    // (if part4 )  in order to As entered by the user at the fourth part of the image
    if (part4 == '1'){
        int r = 0 , c = 0 ;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 128 ; col <SIZE ; ++col) {
                image[row][col] = image_qua1[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    if( part4 == '2'){
        int r = 0 , c = 0 ;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 128 ; col <SIZE ; ++col) {
                image[row][col] = image_qua2[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    if(part4 == '3'){
        int r = 0 , c = 0 ;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 128 ; col <SIZE ; ++col) {
                image[row][col] = image_qua3[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
    if (part4 == '4'){
        int r = 0 , c = 0 ;
        for (int row = 128; row < SIZE; row++) {
            for (int col = 128 ; col <SIZE ; ++col) {
                image[row][col] = image_qua4[r][c++];
            }
            r++;
            c = 0 ;
        }
    }
// if the user input a char > '4'
    while (part1 > '4' || part2 > '4' || part3 > '4' || part4 > '4'){
        cout << "One of the values entered is not a valid."
                "please enter a valid value: \n";
        cin >>part1 >> part2 >>part3 >> part4;
    }
    save_qua1();
    save_qua2();
    save_qua3();
    save_qua4();
    check();
    return image[SIZE][SIZE];
}
void save_qua1 (){
    int r = 0 , c = 0 ;
    for (int row = 0; row < SIZE/2; ++row) {
        for (int col = 0; col < SIZE/2; ++col) {
            image_qua1[r][c++] = image[row][col];

        }
        r++;
        c=0;
    }
}

void save_qua2 () {
    int r = 0, c = 0;
    for (int row = 0; row < SIZE / 2; ++row) {
        for (int col = 128; col < SIZE; ++col) {
            image_qua2[r][c++] = image[row][col];
        }
        r++;
        c = 0;

    }
}

void save_qua3 () {
    int r = 0, c = 0;
    for (int row = 128 ; row < SIZE ; ++row) {
        for (int col = 0; col < SIZE/2; ++col) {
            image_qua3[r][c++] = image[row][col];
        }
        r++;
        c = 0;

    }
}

void save_qua4 (){
    int r = 0, c = 0;
    for (int row = 128 ; row < SIZE ; ++row) {
        for (int col = 128; col < SIZE; ++col) {
            image_qua4[r][c++] = image[row][col];
        }
        r++;
        c = 0;

    }
}
char shrink() {
    char chose;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image2[i][j]=255;
        }

    }
    cout << "if you want make shrink 1- 1/2 \n 2- 1/3 \n 3- 1/4";
    cin >> chose;
 if(chose == '1'){
     for (int i = 0; i < SIZE; ++i) {
         for (int j = 0; j < SIZE; ++j) {
           image2[i/2][j/2]=(image[i][j] + image[i+1][j]+ image[i][j+1]+image[i+1][j+1])/4;

         }
     }
 }// if chose = 1 shrink image to 1/2
 else if (chose == '2'){
     for (int i = 0; i < SIZE; ++i) {
         for (int j = 0; j < SIZE; ++j) {
             image2[i/3][j/3]=(image[i][j] + image[i+1][j]+ image[i][j+1]+image[i+1][j+1])/4;

         }
     }

 }// if chose = 2 shrink image to 1/3
 else if (chose == '3'){

     for (int i = 0; i < SIZE; ++i) {
         for (int j = 0; j < SIZE; ++j) {
             image2[i/4][j/4]=(image[i][j] + image[i+1][j]+ image[i][j+1]+image[i+1][j+1])/4;

         }
     }
 }// if chose = 3 shrink image to 1/4
for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
        image[i][j]= image2[i][j];

    }

}
    check();
    return image[SIZE][SIZE];
}


void read(){
    char file [100];
    cout << "enter file name: ";
    cin >> file;
    strcat(file,".bmp");
    readGSBMP(file,image);//read the image
}
void save(){
    char file [100];
    cout << "enter file name you like to save it with: ";
    cin >> file;
    strcat(file,".bmp");
    writeGSBMP(file,image);// write the modified image
}

void check (){
    cout << "do you want to save your image press S to save Or type M to make more filters: ";
    cin >> chose;
    chose = toupper(chose);
    while(true){
        if (chose == 'S'){
            save();// if chose = s save modified image
            break;
        }
        else if (chose == 'M'){
            menu();// if chose = m continue modifying
            break;
        }
        cout << "wrong input please press S key to save or M to show menu\n";
        cin >> chose;
        chose = toupper(chose);

    }
}
