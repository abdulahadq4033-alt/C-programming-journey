/* tetris.c
   Simple console Tetris (single-file). Portable: Windows (_WIN32) uses conio.h,
   POSIX uses termios + select. Compile with: gcc tetris.c -o tetris
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
  #include <conio.h>
  #include <windows.h>
  #define CLEAR_SCREEN() system("cls")
  void sleep_ms(int ms){ Sleep(ms); }
#else
  #include <termios.h>
  #include <unistd.h>
  #include <sys/select.h>
  #define CLEAR_SCREEN() printf("\x1b[2J\x1b[H")
  static struct termios orig_term;
  void disable_input_buffering(){
    tcgetattr(STDIN_FILENO, &orig_term);
    struct termios newt = orig_term;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  }
  void restore_input_buffering(){
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_term);
  }
  int kbhit(){
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
  }
  int getch_nonblock(){
    int c = getchar();
    return c;
  }
  void sleep_ms(int ms){ usleep(ms * 1000); }
#endif

#define WIDTH 10
#define HEIGHT 20
#define FIELD_W (WIDTH+2)
#define FIELD_H (HEIGHT+2)

char field[FIELD_H][FIELD_W+1]; // +1 for '\0'

int pieces[7][4] = {
  {1,3,5,7}, // I
  {2,4,5,7}, // Z
  {3,5,4,6}, // S
  {3,5,4,7}, // T
  {2,3,5,7}, // L
  {3,5,7,6}, // J
  {2,3,4,5}  // O (square)
};

int currPiece;
int rotation; // 0-3 but we'll use rotation via transforms
int posX, posY; // top-left anchor (we'll use coordinates inside playfield)
int score = 0;
int gameOver = 0;
int dropInterval = 500; // ms

// Map piece cell index (0..3) to x,y depending on rotation & piece template
void rotateCoords(int idx, int r, int *x, int *y){
  // piece is given as 4 indices (0..3) mapping to a 4x4 grid:
  // index -> (i%2?) BUT the templates above are typical compact forms:
  // We'll decode by reconstructing base coordinates from the number
  int px = pieces[currPiece][idx] % 2 ? 1 : 0; // not reliable; instead decode as 0..3 grid
  // Use common approach: the numbers in arrays are positions in a 4x4 matrix numbered:
  // 0 1 2 3
  // 4 5 6 7
  // 8 9 10 11
  //12 13 14 15
  int val = pieces[currPiece][idx];
  int baseX = val % 4;
  int baseY = val / 4;
  // rotate 90 degrees r times around center of 4x4 (1.5,1.5)
  int rx = baseX, ry = baseY;
  for(int i=0;i<r;i++){
    int nx = ry;
    int ny = 3 - rx;
    rx = nx; ry = ny;
  }
  *x = rx;
  *y = ry;
}

// check if piece at posX,posY with rotation r fits
int doesFit(int r){
  for(int i=0;i<4;i++){
    int x,y;
    rotateCoords(i, r, &x, &y);
    int fx = posX + x;
    int fy = posY + y;
    if(fy < 0 || fy >= FIELD_H) return 0;
    if(fx < 0 || fx >= FIELD_W) return 0;
    if(field[fy][fx] != ' ') return 0;
  }
  return 1;
}

void placePiece(){
  for(int i=0;i<4;i++){
    int x,y;
    rotateCoords(i, rotation, &x, &y);
    int fx = posX + x;
    int fy = posY + y;
    if(fy>=0 && fy<FIELD_H && fx>=0 && fx<FIELD_W)
      field[fy][fx] = '#';
  }
}

void clearLines(){
  int lines = 0;
  for(int y=0;y<HEIGHT;y++){
    int full = 1;
    for(int x=1;x<=WIDTH;x++){
      if(field[y][x]==' ') { full = 0; break; }
    }
    if(full){
      lines++;
      for(int yy=y; yy>0; yy--){
        for(int x=1;x<=WIDTH;x++){
          field[yy][x] = field[yy-1][x];
        }
      }
      for(int x=1;x<=WIDTH;x++) field[0][x] = ' ';
    }
  }
  if(lines>0){
    score += (lines * 100);
    // speed up a bit
    if(dropInterval > 100) dropInterval -= lines*10;
  }
}

void initField(){
  for(int y=0;y<FIELD_H;y++){
    for(int x=0;x<FIELD_W;x++){
      if(x==0 || x==FIELD_W-1 || y==FIELD_H-1) field[y][x] = '|';
      else field[y][x] = ' ';
    }
    field[y][FIELD_W] = '\0';
  }
}

void spawnPiece(){
  currPiece = rand()%7;
  rotation = 0;
  posX = 3; // starting approx center in 4x4
  posY = 0;
  if(!doesFit(rotation)){
    gameOver = 1;
  }
}

void draw(){
  CLEAR_SCREEN();
  printf("Score: %d\n", score);
  // copy field to temp to draw piece too
  char tmp[FIELD_H][FIELD_W+1];
  for(int y=0;y<FIELD_H;y++) strcpy(tmp[y], field[y]);
  // draw current piece into tmp
  for(int i=0;i<4;i++){
    int x,y;
    rotateCoords(i, rotation, &x, &y);
    int fx = posX + x;
    int fy = posY + y;
    if(fy>=0 && fy<FIELD_H && fx>=0 && fx<FIELD_W)
      tmp[fy][fx] = '@';
  }
  // print visible area: only HEIGHT rows and WIDTH columns inside walls
  for(int y=0;y<HEIGHT;y++){
    for(int x=0;x<FIELD_W;x++){
      putchar(tmp[y][x]);
    }
    putchar('\n');
  }
  printf("\nControls: a:left d:right s:soft drop w:rotate space:hard drop q:quit\n");
}

int main(){
  srand((unsigned)time(NULL));
#ifndef _WIN32
  disable_input_buffering();
  atexit(restore_input_buffering);
#endif
  initField();
  spawnPiece();
  unsigned long lastDrop = (unsigned long)clock();
  int ch;
  draw();
  while(!gameOver){
    // input
    if(
#ifdef _WIN32
       _kbhit()
#else
       kbhit()
#endif
      ){
#ifdef _WIN32
      ch = _getch();
      // handle arrow keys (two-step)
      if(ch==0 || ch==224){ ch = _getch(); } // ignore extended
#else
      ch = getchar();
#endif
      if(ch=='a'){ // left
        posX -= 1;
        if(!doesFit(rotation)) posX += 1;
      } else if(ch=='d'){ // right
        posX += 1;
        if(!doesFit(rotation)) posX -= 1;
      } else if(ch=='s'){ // soft drop
        posY += 1;
        if(!doesFit(rotation)){
          posY -= 1;
          placePiece();
          clearLines();
          spawnPiece();
        }
      } else if(ch=='w'){ // rotate
        int old = rotation;
        rotation = (rotation + 1) % 4;
        if(!doesFit(rotation)) rotation = old;
      } else if(ch==' '){ // hard drop
        while(doesFit(rotation)){
          posY++;
        }
        posY--;
        placePiece();
        clearLines();
        spawnPiece();
      } else if(ch=='q' || ch=='Q'){
        break;
      }
      draw();
    }
    // drop by timer
    unsigned long now = (unsigned long)(clock());
    if((now - lastDrop) * 1000 / CLOCKS_PER_SEC >= (unsigned)dropInterval){
      lastDrop = now;
      posY += 1;
      if(!doesFit(rotation)){
        posY -= 1;
        placePiece();
        clearLines();
        spawnPiece();
      }
      draw();
    }
    sleep_ms(20);
  }

  CLEAR_SCREEN();
  if(gameOver) printf("Game Over!\n");
  printf("Final score: %d\n", score);
#ifndef _WIN32
  // restore handled by atexit
#endif
  return 0;
}
