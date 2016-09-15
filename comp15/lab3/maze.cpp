//
//  maze.cpp
//  MazeCreator
//
//  Created by Chris Gregg on 2/8/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "maze.h"
#include "stack.h"
using namespace std;

Maze::Maze(int size, unsigned int rand_seed)
{
        srand(rand_seed);
        maze_size = size;
        maze_array_size = maze_size * 2 + 1; // the actual size of the array, including walls and border
        for(int a = 0; a < MAX; a++)
        {
                for(int b = 0; b < MAX; b++)
                {
                        if(a % 2 == 0 || b % 2 == 0)
                                maze[a][b] = 1;
                        else
                                maze[a][b] = PATH;
                }
        }
}

// solve_maze should be passed a human-readable maze
// with a start and finish, and a start position of 1,1
// dead-end paths that have been tested should be marked
// with lowercase x
// The correct path should be marked with periods, .
bool Maze::solve_maze_recursive(int row, int col) {
        // be careful! 2d arrays seem backwards and upside down
        // compared to cartesian coordinates:
        // maze[0][0] == top left
        // maze[1][0] == one down, zero to the right
        // maze[0][1] == zero down, one to the right
        // maze[row][col] == row down and col to the right
        
        // (1) if the row or col coordinates are outside the array, then return false
        // i.e., if row (or col) is less than zero or greater than or equal to the maze_array_size
        
        // TODO: Students write code here
        if ((row < 0 || row >= maze_array_size) ||
            (col < 0 || col >= maze_array_size)) {
                return false;
        }
        
        // (2) if the value at maze[row][col] is either 'X' or 'x' or '.' return false
        // i.e., the location is either blocked or already part of the path
        
        // TODO: Students write code here
        if ((maze[row][col] == 'X') ||
            (maze[row][col] == 'x') ||
            (maze[row][col] == '.')) {
                return false;
        }
        
        // (3) if the value is 'F' we've found the finish, so return true!
        
        // TODO: Students write code here
        if (maze[row][col] == 'F') {
                return true;
        }
        
        // (4) We have a potential path, so we set maze[row][col] to equal '.'
        
        // TODO: Students write code here

        maze[row][col] = '.';
        
        //print_maze(); // uncomment to debug
        
        // (5)-(8) recursively call solve_maze_recursive(row,col) for north, east, south, and west
        // If one of the positions returns true, then return true (north is done for you)
        
        // north
        if (solve_maze_recursive(row-1,col) == true) return true;
        // east
        // TODO: Students write code here
        if (solve_maze_recursive(row,col+1) == true) return true;
        // south
        // TODO: Students write code here
        if (solve_maze_recursive(row+1,col) == true) return true;
        // west
        // TODO: Students write code here
        if (solve_maze_recursive(row,col-1) == true) return true;
        // (9) we didn't actually find a solution, so mark the position with an 'x'
        
        // TODO: Students write code here
        maze[row][col] = 'x';
        
        //print_maze(); // uncomment to debug
        
        // (10) we didn't find a solution down this path, so return false
        
        // TODO: Students write code here
        return false;
}

void Maze::solve_maze_stack(int row, int col){
        // (1) create a Stack called stack
        
        // TODO: Students write code here
        Stack stack = Stack();

        while (1){ // loop to keep going until we find a solution
                // (2) if maze[row][col] equals 'F' then we found the finish!
                // We must break out of the loop
                
                // TODO: Students write code here
                if (maze[row][col] == 'F') break;
                
                // (3) we have a possible path, so mark it with '.'
                
                // TODO: Students write code here
                
                maze[row][col] = '.';
               

                print_maze(); // uncomment to debug
                
                // (4)-(7) For each direction, check to see if we are out-of-bounds
                // and also make sure we haven't either hit a blocked path
                // or a path that is part of the solution.
                // If we have a viable path, push our current position onto the
                // stack, and then go in that direction
                // (north is done for you)
                
                // north
                if (row-1 >= 0 &&
                    maze[row-1][col]!='X' &&
                    maze[row-1][col]!='x' &&
                    maze[row-1][col]!='.'){
                        stack.push(Position(row,col));
                        row-=1;
                        continue;
                }
                // east
                
                // TODO: Students write code here
                if (col+1 < maze_array_size &&
                    maze[row][col+1]!='X' &&
                    maze[row][col+1]!='x' &&
                    maze[row][col+1]!='.'){
                        stack.push(Position(row,col));
                        col+=1;
                        continue;
                }
                // south
                
                // TODO: Students write code here
                if (row+1 < maze_array_size &&
                    maze[row+1][col]!='X' &&
                    maze[row+1][col]!='x' &&
                    maze[row+1][col]!='.'){
                        stack.push(Position(row,col));
                        row+=1;
                        continue;
                }
                // west
                
                // TODO: Students write code here
                if (col-1 >= 0 &&
                    maze[row][col-1]!='X' &&
                    maze[row][col-1]!='x' &&
                    maze[row][col-1]!='.'){
                        stack.push(Position(row,col));
                        col-=1;
                        continue;
                }
                
                // (8) we didn't actually find a solution, so mark the position with 'x'
                
                // TODO: Students write code here
                maze[row][col] = 'x';
                
                print_maze(); // uncomment to debug
                
                // (9) because we didn't find a solution, we have to pop the stack and
                // set row and col to the Position values we just popped from the stack
                
                // TODO: Students write code here
                Position justPopped;
                justPopped = stack.pop();
                row = justPopped.row;
                col = justPopped.col;
        }
}

// generates a maze
void Maze::generate_maze(){
        int index = 0;
        int backtrack_x[CELL];
        int backtrack_y[CELL];
        backtrack_x[index] = 1;
        backtrack_y[index] = 1;
        maze_generator(index, backtrack_x, backtrack_y, 1, 1, maze_size, 1);
}

void Maze::maze_generator(int index, int backtrack_x[CELL], int backtrack_y[CELL], int x, int y, int n, int visited)
{
        if(visited < n * n)
        {
                int neighbour_valid = -1;
                int neighbour_x[4];
                int neighbour_y[4];
                int step[4];
                
                int x_next;
                int y_next;
                
                if(x - 2 > 0 && is_closed(x - 2, y))  // upside
                {
                        neighbour_valid++;
                        neighbour_x[neighbour_valid]=x - 2;;
                        neighbour_y[neighbour_valid]=y;
                        step[neighbour_valid]=1;
                }
                
                if(y - 2 > 0 && is_closed(x, y - 2))  // leftside
                {
                        neighbour_valid++;
                        neighbour_x[neighbour_valid]=x;
                        neighbour_y[neighbour_valid]=y - 2;
                        step[neighbour_valid]=2;
                }
                
                if(y + 2 < n * 2 + 1 && is_closed(x, y + 2))  // rightside
                {
                        neighbour_valid++;
                        neighbour_x[neighbour_valid]=x;
                        neighbour_y[neighbour_valid]=y + 2;
                        step[neighbour_valid]=3;
                        
                }
                
                if(x + 2 < n * 2 + 1 && is_closed(x + 2, y))  // downside
                {
                        neighbour_valid++;
                        neighbour_x[neighbour_valid]=x+2;
                        neighbour_y[neighbour_valid]=y;
                        step[neighbour_valid]=4;
                }
                
                if(neighbour_valid == -1)
                {
                        // backtrack
                        x_next = backtrack_x[index];
                        y_next = backtrack_y[index];
                        index--;
                }
                
                if(neighbour_valid!=-1)
                {
                        int randomization = neighbour_valid + 1;
                        int random = rand()%randomization;
                        x_next = neighbour_x[random];
                        y_next = neighbour_y[random];
                        index++;
                        backtrack_x[index] = x_next;
                        backtrack_y[index] = y_next;
                        
                        int rstep = step[random];
                        
                        if(rstep == 1)
                                maze[x_next+1][y_next] = PATH;
                        else if(rstep == 2)
                                maze[x_next][y_next + 1] = PATH;
                        else if(rstep == 3)
                                maze[x_next][y_next - 1] = PATH;
                        else if(rstep == 4)
                                maze[x_next - 1][y_next] = PATH;
                        visited++;
                }
                
                maze_generator(index, backtrack_x, backtrack_y, x_next, y_next, n, visited);
        }
}

// requires human_readable_maze
void Maze::print_maze()
{
        for(int a = 0; a < maze_size * 2 + 1; a++)
        {
                for(int b = 0; b < maze_size * 2 + 1; b++)
                {
                        printf("%c",maze[a][b]);
                }
                printf("\n");
        }
        printf("\n");
}

void Maze::human_readable_maze()
{
        for(int a = 0; a < maze_array_size; a++)
        {
                for(int b = 0; b < maze_array_size; b++)
                {
                        if (a==1 && b==1)
                                maze[a][b]='S'; // the start location
                        else if (a==maze_array_size - 2 && b==maze_array_size-2) // the finish location
                                maze[a][b]='F';
                        else if(maze[a][b] == WALL)
                                maze[a][b]='X';
                        else
                                maze[a][b]=' ';
                }
        }
}

int Maze::is_closed(int x, int y)
{
        if(maze[x - 1][y]  == WALL
           && maze[x][y - 1] == WALL
           && maze[x][y + 1] == WALL
           && maze[x + 1][y] == WALL
           )
                return 1;
        
        return 0;
}

bool Maze::isSameSolutionAs(Maze anotherMaze){
        for (int row=0;row<maze_array_size;row++){
                for (int col=0;col<maze_array_size;col++){
                        if (maze[row][col] != anotherMaze.maze[row][col]) return false;
                }
        }
        return true;
}

