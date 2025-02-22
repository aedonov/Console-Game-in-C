#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>



#define COLS 20
#define ROWS 20
int oX, oY;

void clearScreen() {
    system("cls");
    system("mode con: cols=40 lines=30");
}

void gitLink(){
    printf("redirecting");
    system("start https://github.com/aedonov");
}

void textColor(int color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void collect(int *oX, int *oY){
    *oX = rand() % (COLS-1);
    *oY = rand() % (COLS-1);
}

void printGrid(int xx, int xy, int oX,int oY) { 
    clearScreen();
    // int numC = rand() % (COLS -1);'
    printf("Adonos Software 2025\n");
    printf("Use WASD or Arrow Keys\n");
    printf("press 'Q' to quit\n");
    printf("press 'H' to be redirected\nto my github\n");


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == xy && j == xx) {
                printf("X");  
            } else if (i == oY && j == oX){
                printf("0");
            // } else if (numC <= i && numC <= j && numC != x && numC != y){
            //     printf("@");
            } else {
                printf("*");  
            }
        }
        printf("\n");
    }



    // if (xx == oX && xy == oY){
    //     collect(&oX, &oY);
    // }
}


int main() {
    clock_t lastTime = clock();
    int frames = 0;
    float fps = 0;
    clearScreen();
    int xx = COLS / 2;  
    int xy = ROWS / 2;
    char ch;
    collect(&oX, &oY);

    while (1) {
        clock_t currentTime = clock();
        frames++;
        if ((currentTime - lastTime) / CLOCKS_PER_SEC >= 0.1) {
            fps = frames / (float)((currentTime - lastTime) / CLOCKS_PER_SEC);
            frames = 0;  
            lastTime = currentTime;
            char title[50];
            snprintf(title, sizeof(title), "FPS: %.3f", fps);
            SetConsoleTitle(title);
        }

        printGrid(xx, xy, oX, oY);  
        ch = getch(); 

        if (ch == 224 || ch == -32){
            int c2 = getch();
            switch (c2){
                case 72:
                //up
                if (xy > 1) xy--; 
                break;

                case 80:
                //down
                if (xy < ROWS - 1) xy++;  
                break;

                case 75:
                //left
                if (xx > 0) xx--;  
                break;

                case 77:
                //right
                if (xx < COLS - 1) xx++; 
                break;

                default:
                printf("error");
                break;
            }
        } else if (ch == 'w' || ch == 'W') {
            if (xy > 0) xy--;  
        } else if (ch == 's' || ch == 'S') {
            if (xy < ROWS - 1) xy++;  
        } else if (ch == 'a' || ch == 'A') {
            if (xx > 0) xx--;  
        } else if (ch == 'd' || ch == 'D') {
            if (xx < COLS - 1) xx++;  
        } else if (ch == 'q' || ch == 'Q') {
            break; 
        } else if (ch == '1'){
            textColor(1);
        } else if (ch == '2'){
            textColor(2);
        } else if (ch == '3'){
            textColor(3);
        } else if (ch == '4'){
            textColor(4);
        } else if (ch == '5'){
            textColor(5);
        } else if (ch == '6'){
            textColor(6);
        } else if (ch == '7'){
            textColor(7);
        } else if (ch == '8'){
            textColor(8);
        } else if (ch == '9'){
            textColor(9);;
        } else if (ch == '0'){
            textColor(0);
        } else if (ch == 'h' || ch == 'H'){
            gitLink();
        }
        
        if (xx ==oX && xy == oY){
            collect(&oX, &oY);
        }
        Sleep(10);
    }
return 0;
}