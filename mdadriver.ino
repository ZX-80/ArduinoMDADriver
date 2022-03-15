#define HSYNC 8
#define VSYNC 16
#define ROWS 123

const byte buf[124][13] = {
  {},                      // VERTICAL BLANKING:   row 0
  #include "images/out.h"  // IMAGE DATA:          row 1 - 115
                           // VERTICAL BLANKING:   row 116 - 123
};

//PORTB = 000_VH_bgr
#define SETC(x) PORTB = (PORTB & ~7) | x

#define EXEC_NOP asm volatile ("nop\n\t")
#define EXEC_10_NOPS EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP;
#define EXEC_50_NOPS EXEC_10_NOPS; EXEC_10_NOPS; EXEC_10_NOPS; EXEC_10_NOPS; EXEC_10_NOPS;
#define EXEC_100_NOPS EXEC_50_NOPS; EXEC_50_NOPS;

#define EXEC_LEFT_BLANKING_AND_OVERSCAN() { SETC(0); EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP;}
#define EXEC_RIGHT_OVERSCAN_AND_BLANKING() { SETC(0); }
#define EXEC_HSYNC() { PORTB |= HSYNC; EXEC_100_NOPS; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; PORTB &= ~HSYNC; }

#define LDELAY  EXEC_10_NOPS; EXEC_10_NOPS; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP; EXEC_NOP;

void DRAW_PIXELS_FOR_LINE(int i) { 
  SETC((buf[i][0] >> 7) & 1);
  SETC((buf[i][0] >> 6) & 1);
  SETC((buf[i][0] >> 5) & 1);
  SETC((buf[i][0] >> 4) & 1);
  SETC((buf[i][0] >> 3) & 1);
  SETC((buf[i][0] >> 2) & 1);
  SETC((buf[i][0] >> 1) & 1);
  SETC((buf[i][0] >> 0) & 1);

  SETC((buf[i][1] >> 7) & 1);
  SETC((buf[i][1] >> 6) & 1);
  SETC((buf[i][1] >> 5) & 1);
  SETC((buf[i][1] >> 4) & 1);
  SETC((buf[i][1] >> 3) & 1);
  SETC((buf[i][1] >> 2) & 1);
  SETC((buf[i][1] >> 1) & 1);
  SETC((buf[i][1] >> 0) & 1);

  SETC((buf[i][2] >> 7) & 1);
  SETC((buf[i][2] >> 6) & 1);
  SETC((buf[i][2] >> 5) & 1);
  SETC((buf[i][2] >> 4) & 1);
  SETC((buf[i][2] >> 3) & 1);
  SETC((buf[i][2] >> 2) & 1);
  SETC((buf[i][2] >> 1) & 1);
  SETC((buf[i][2] >> 0) & 1);

  SETC((buf[i][3] >> 7) & 1);
  SETC((buf[i][3] >> 6) & 1);
  SETC((buf[i][3] >> 5) & 1);
  SETC((buf[i][3] >> 4) & 1);
  SETC((buf[i][3] >> 3) & 1);
  SETC((buf[i][3] >> 2) & 1);
  SETC((buf[i][3] >> 1) & 1);
  SETC((buf[i][3] >> 0) & 1);

  SETC((buf[i][4] >> 7) & 1);
  SETC((buf[i][4] >> 6) & 1);
  SETC((buf[i][4] >> 5) & 1);
  SETC((buf[i][4] >> 4) & 1);
  SETC((buf[i][4] >> 3) & 1);
  SETC((buf[i][4] >> 2) & 1);
  SETC((buf[i][4] >> 1) & 1);
  SETC((buf[i][4] >> 0) & 1);

  SETC((buf[i][5] >> 7) & 1);
  SETC((buf[i][5] >> 6) & 1);
  SETC((buf[i][5] >> 5) & 1);
  SETC((buf[i][5] >> 4) & 1);
  SETC((buf[i][5] >> 3) & 1);
  SETC((buf[i][5] >> 2) & 1);
  SETC((buf[i][5] >> 1) & 1);
  SETC((buf[i][5] >> 0) & 1);

  SETC((buf[i][6] >> 7) & 1);
  SETC((buf[i][6] >> 6) & 1);
  SETC((buf[i][6] >> 5) & 1);
  SETC((buf[i][6] >> 4) & 1);
  SETC((buf[i][6] >> 3) & 1);
  SETC((buf[i][6] >> 2) & 1);
  SETC((buf[i][6] >> 1) & 1);
  SETC((buf[i][6] >> 0) & 1);

  SETC((buf[i][7] >> 7) & 1);
  SETC((buf[i][7] >> 6) & 1);
  SETC((buf[i][7] >> 5) & 1);
  SETC((buf[i][7] >> 4) & 1);
  SETC((buf[i][7] >> 3) & 1);
  SETC((buf[i][7] >> 2) & 1);
  SETC((buf[i][7] >> 1) & 1);
  SETC((buf[i][7] >> 0) & 1);

  SETC((buf[i][8] >> 7) & 1);
  SETC((buf[i][8] >> 6) & 1);
  SETC((buf[i][8] >> 5) & 1);
  SETC((buf[i][8] >> 4) & 1);
  SETC((buf[i][8] >> 3) & 1);
  SETC((buf[i][8] >> 2) & 1);
  SETC((buf[i][8] >> 1) & 1);
  SETC((buf[i][8] >> 0) & 1);

  SETC((buf[i][9] >> 7) & 1);
  SETC((buf[i][9] >> 6) & 1);
  SETC((buf[i][9] >> 5) & 1);
  SETC((buf[i][9] >> 4) & 1);
  SETC((buf[i][9] >> 3) & 1);
  SETC((buf[i][9] >> 2) & 1);
  SETC((buf[i][9] >> 1) & 1);
  SETC((buf[i][9] >> 0) & 1);

  SETC((buf[i][10] >> 7) & 1);
  SETC((buf[i][10] >> 6) & 1);
  SETC((buf[i][10] >> 5) & 1);
  SETC((buf[i][10] >> 4) & 1);
  SETC((buf[i][10] >> 3) & 1);
  SETC((buf[i][10] >> 2) & 1);
  SETC((buf[i][10] >> 1) & 1);
  SETC((buf[i][10] >> 0) & 1);

  SETC((buf[i][11] >> 7) & 1);
  SETC((buf[i][11] >> 6) & 1);
  SETC((buf[i][11] >> 5) & 1);
  SETC((buf[i][11] >> 4) & 1);
  SETC((buf[i][11] >> 3) & 1);
  SETC((buf[i][11] >> 2) & 1);
  SETC((buf[i][11] >> 1) & 1);
  SETC((buf[i][11] >> 0) & 1);
  
  SETC((buf[i][12] >> 7) & 1);
  SETC((buf[i][12] >> 6) & 1);
  SETC((buf[i][12] >> 5) & 1);
  SETC((buf[i][12] >> 4) & 1);
}

#define DRAW_LINE(i) { \
  EXEC_HSYNC(); \
  EXEC_LEFT_BLANKING_AND_OVERSCAN(); \
  DRAW_PIXELS_FOR_LINE(i); \
  EXEC_RIGHT_OVERSCAN_AND_BLANKING(); \
}

int row = 0;

void setup() {
    DDRB = B111111;
    PORTB &= ~(HSYNC | 7);  // HSYNC/PIXEL LOW
    noInterrupts();
}

void loop() {
  DRAW_LINE(row); LDELAY;
  DRAW_LINE(row); LDELAY;
  DRAW_LINE(row);

  switch (row++) { // 27 cycles
    case 116:
      PORTB &= ~VSYNC; // VSYNC LOW
      break;
    case 121:
      PORTB |= VSYNC; // VSYNC HIGH
      break;
    case ROWS:
      row = 0;
      break;
  }
}
