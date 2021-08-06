 /*
 * TurtleGraphcis.c
 * Sample solution to exercise 4.7: implement a turtle graphics program
 */

#include <stdio.h>
#include <stdlib.h>

void turtle(int commands[], int commandSize);

int main()
{
  // sample graphics with sizes
  int turtle1[] = {5, 5, 3, 5, 5, 4, 2, 5, 12, 3, 5, 11, 3, 5, 11, 3, 5, 11, 6,  9};
  int size1 = 21;
  int turtle2[] = {3, 5, 3, 4, 5, 12, 2, 5, 3, 1, 3, 5, 1, 4, 2, 5, 3, 1, 3, 5, 1, 4, 2, 5, 3, 1, 3, 5, 1, 4, 2, 5, 2, 1, 3, 5, 1, 4, 2, 5, 2, 1, 5, 1, 3, 2, 5, 4, 1, 5, 1, 3, 2, 5, 2, 4, 1, 5, 1, 3, 2, 5, 2, 1, 4, 1, 5, 1, 3, 2, 5, 3, 1, 4, 5, 1, 3, 2, 5, 3, 1, 4, 5, 1, 3, 2, 5, 3, 1, 3, 5, 1, 4, 2, 5, 3, 1, 3, 5, 1, 4, 2, 5, 3, 1, 3, 5, 1, 4, 2, 5, 2, 1, 3, 5, 1, 4, 2, 5, 2, 1, 5, 1, 3, 2, 5, 4, 1, 5, 1, 3, 2, 5, 2, 1, 4, 5, 1, 3, 2, 5, 2, 1, 4, 5, 1, 3, 2, 5, 3,   1, 4, 5, 1, 3, 2, 5, 3, 6, 9};
  int size2 = 160;
  int turtle3[] = {5, 5, 3, 5, 20, 4, 4, 2, 5, 9, 3, 5, 9, 3, 5, 8, 3, 3, 5, 4, 4, 5, 8, 6, 9};
  int size3 = 25;

  // variable for user choice
  int choice;
  // variable for command counter
  int commandCount;
  // storage for recording commands
  int turtleFree[1000] = {9};
    

  do {
    printf("Welcome to Turtle Graphics\n"
	   "Please choose from the following:\n"
	   "1) Execute sample 1\n"
	   "2) Execute sample 2\n"
	   "3) Execute sample 3\n"
	   "4) Record turtle graphics\n"
	   "5) Display last record\n"
	   "6) Exit\nYour Choice? ");
    scanf("%i", &choice);
    switch(choice) {
    case 1: // display sample 1
      turtle(turtle1, size1);
      break;
    case 2: // display sample 2
      turtle(turtle2, size2);
      break;
    case 3: // display sample 3
      turtle(turtle3, size3);
      break;
    case 4: // record commands
      printf("Please enter the turtle commands - finish by entering "
	     "command 9\n");
      // record at most 1000 commands, terminate if 9 is entered
      for (commandCount=0; commandCount<1000; ++commandCount) {
	scanf("%i", &turtleFree[commandCount]);
	if (turtleFree[commandCount] == 9) {
	  // entered 9, terminate loop
	  break;
	}
	printf("Enter the next command: ");
      }
      break;
    case 5: // display recorded commands
      turtle(turtleFree, 1000);
      break;
    }
  } while (choice != 6);
  
  return EXIT_SUCCESS;
}

/*
 * turtle(commands, commandSize)
 * implements turtle capabilities
 *
 * param: int commands[] - array with turtle commands (closed with 9)
 *        int commandSize - maximum size of commands array
 * return: void
 */
void turtle(int commands[], int commandSize)
{
  // two dimensional array for floor, initialised to all 0
  int floor[30][30] = {{0}};
  // variable for current turtle x position
  // 0 is left border
  int turtleX=0;
  // variable for current turtle y position
  // 0 is top border
  int turtleY=0;
  
  // variable for current pen position (0=up, 1=down)
  int penPosition=0;
  // variable for direction (0=up, 1=right, 2=down, 3=left)
  int direction=1;
  // variable for number of steps
  int steps;
  
  // loop through all commands and perform actions on floor
  for (int i=0; i<commandSize; ++i) {
    // react to next command
    switch(commands[i]) {
    case 1: // pen up
      penPosition=0;
      break;
    case 2: // pen down
      // change position
      penPosition=1;
      // if you wish to leave a mark at current position, uncomment
      // leave mark at current position
      // floor[turtleY][turtleX] = penPosition;
      break;
    case 3: // turn right
      direction = (direction+1)%4;
      break;
    case 4: // turn left
      // in mod(n) adding (n-1) = subtracting 1
      direction = (direction+3)%4;
      break;
    case 5: // move
      // read number of steps and increment command index
      steps = commands[++i];
      switch (direction) {
      case 0: // up
	// for each step leave mark in up direction
	for (int j=0; j<steps; ++j) {
	  if (turtleY > 0) {
	    // decrement position
	    --turtleY;
	    // leave mark at new position
	    floor[turtleY][turtleX] = penPosition;
	  }
	}
	break;
      case 1: // right
	// for each step leave mark in right direction
	for (int j=0; j<steps; ++j) {
	  if (turtleX < 29) {
	    // increment position
	    ++turtleX;
	    // leave mark at new position
	    floor[turtleY][turtleX] = penPosition;
	  }
	}
	break;
      case 2: // down
	// for each step leave mark in up direction
	for (int j=0; j<steps; ++j) {
	  if (turtleY < 29) {
	    // increment position
	    ++turtleY;
	    // leave mark at new position
	    floor[turtleY][turtleX] = penPosition;
	  }
	}
	break;
      case 3: // left
	// for each step leave mark in left direction
	for (int j=0; j<steps; ++j) {
	  if (turtleX > 0) {
	    // decrement position
	    --turtleX;
	    // leave mark at new position
	    floor[turtleY][turtleX] = penPosition;
	  }
	}
	break;
      default:
	printf("Illegal direction %i found at index %d\n", direction, i);
      }
      break;
    case 6: // print floor
      // start at new line
      printf("\n");
      for (int y=0; y<30; ++y) {
	for (int x=0; x<30; ++x) {
	  if (floor[y][x] == 0) printf(" ");
	  else if (floor[y][x] == 1) printf("*");
	  else printf("Illegal maker %i found at position[%i][%i]\n",
		      floor[y][x], y, x);
	}
	// print newline for next line of floor
	printf("\n");
	// move forward
      }
      break;
    case 9: // end of data
      // cause loop termination
      i = commandSize;
      break;
    default: // illegal input
      printf("Illegal command %i found at index %i - ignore and continue "
	     "with next command\n", commands[i], i);
    }
  }

}
