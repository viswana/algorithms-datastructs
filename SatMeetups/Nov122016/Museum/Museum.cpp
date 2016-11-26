/*! \file Museum.cpp
 *
 * There is a museum organized as an NxM grid of rooms
 * Some rooms are locked and inaccessible. Other rooms
 * are open and only within the museum. Guards are in 
 * some rooms and can only move North, South, East and West
 * only through open rooms and only within the museum.
 * For each room, find the shortest distance to a guard.
 */

#include <iostream>
#include <list>
#include <utility>

using namespace std;

 /**
 * @brief Coordinates of a cell in the grid 
 *
 * Coordinates of a cell in the grid
 */
typedef struct _Coord {
  size_t x; /**< Row num */
  size_t y; /**< Col num */
}Coord, *pCoord;

 /**
 * @brief Print the contents of the grid to stdout
 * @param grid two dimensional array of integers representing grid
 * @param n number of rows in grid
 * @param m number of cols in grid
 */
void printGrid(int* grid, size_t n, size_t m)  {
  if (grid == NULL) return;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++)
      cout << grid[i*m+j] << "\t";
    cout << endl;
  }
}

 /**
 * @brief Fill an NxM grid representing rooms with shortest distance from guards.
 * @param grid two dimensional array of integers representing grid
 * @param n number of rows in grid
 * @param m number of cols in grid
 * @param gPos array of Coords representing guard positions
 * @param gnum number of guard positions
 * @param lRooms array of Coords representing locked Rooms
 * @param lRnum number of locked rooms
 *
 * Given an NxM grid of rooms, some of which are locked, fill the open
 * rooms with weights representing shortest distance from a room with 
 * a guard. 
 * Cells filled with -2 represent locked rooms.
 * Cells filled with -1 are guard positions.
 * Cells filled with 0 are initial values of open rooms.
 */ 

void fillGrid(int* grid, size_t n, size_t m, pCoord gPos, size_t gnum, pCoord lRooms, size_t lRnum) {
  if (grid == NULL || (lRooms == NULL && lRnum > 0) || n < 1 || m < 1 || gPos == NULL || gnum < 1)  return;

  for(size_t g = 0; g < gnum; g++) {
    list<pair<size_t, size_t> > q;
    bool visited[n][m];
    for (size_t i = 0; i < n; i++) 
      for (size_t j = 0; j < m; j++)
        visited[i][j] = false;

    pair<size_t, size_t> guard = make_pair(gPos[g].x, gPos[g].y);
    q.push_back(guard);
    /*! \var int fdepth
     * \brief Counts the depth of the frontier from the source
     */
    int fdepth = 0; 
    /*! \var size_t count
     * \brief Counts the number of items given frontier depth
     */
    size_t count = q.size();
    while(!q.empty()) {
      while(count > 0) {
        pair<size_t, size_t> t = q.front();
        visited[t.first][t.second] = true;
        //top
        if (t.first > 0) { 
          if (!visited[t.first-1][t.second]) {
            size_t top = (t.first-1)*m+t.second;
            if (grid[top] == 0 || grid[top] > fdepth+1) {
              grid[top] = fdepth+1;
              q.push_back(make_pair(t.first-1, t.second));
            }
          }
        }
        //bottom
        if (t.first < n-1) {
          if (!visited[t.first+1][t.second]) {
            size_t bottom = (t.first+1)*m+t.second;
            if (grid[bottom] == 0 || grid[bottom] > fdepth+1) {
              grid[bottom] = fdepth+1;
              q.push_back(make_pair(t.first+1, t.second));
            }
          }
        }
        //left
        if (t.second > 0) {
          if (!visited[t.first][t.second-1]) {
            size_t left = t.first*m+(t.second-1);
            if (grid[left] == 0 || grid[left] > fdepth+1) {
              grid[left] = fdepth+1;
              q.push_back(make_pair(t.first, t.second-1));
            }
          }
        }
        //right
        if (t.second < m-1) {
          if (!visited[t.first][t.second+1]) {
            size_t right = t.first*m+(t.second+1);
            if (grid[right] == 0 || grid[right] > fdepth+1) {
              grid[right] = fdepth+1;
              q.push_back(make_pair(t.first, t.second+1));
            }
          }
        }
        q.pop_front();
        count--;
      }
      fdepth++;
      count = q.size();
    }
  }
}


int main() {
  size_t n = 10, m = 10;
  int grid[n][m];
  for (size_t i = 0; i < n; i++)
    for(size_t j = 0; j < m; j++) 
      grid[i][j] = 0;
  
  Coord gPos[] = { {0, 1}, {3, 2}, {5, 5} };
  Coord lRooms[] = { {1, 3}, {2, 2}, {4, 0} };  
  size_t gnum = sizeof(gPos)/sizeof(Coord);
  size_t lRnum = sizeof(lRooms)/sizeof(Coord);
  for (size_t i = 0; i < gnum; i++) 
    grid[gPos[i].x][gPos[i].y] = -1;
  for (size_t i = 0; i < lRnum; i++) 
    grid[lRooms[i].x][lRooms[i].y] = -2;

  cout << "Before Filling the grid" << endl;
  printGrid((int*) grid, n, m);
  fillGrid((int*) grid, n, m, gPos, gnum, lRooms, lRnum); 
  cout << "After Filling the grid" << endl;
  printGrid((int*) grid, n, m);
  return 0;
}
