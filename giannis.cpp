#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cstdlib>

using namespace std;

typedef char (&maze)[5][7];

maze printMaze(maze a){
  for (int i =0; i<5 ; i++ )
  {
    for(int j = 0 ; j<7 ; j++){
      cout << a[i][j];
    }
    cout << endl;
  }
  cout << "\n";
}



maze recur(maze mz, int start,int i, int step){

  char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
  char c = '\0';

  if(start!=6){
    if(mz[i][start+1]== '.'){
      
      c = digits[step];
     
      mz[i][start+1]= c;

      printMaze(mz);


      recur(mz,start+1, i, step+1);
    }
  }
  
  if(start!=0){
    if(mz[i][start-1]=='.'){

      c = digits[step];
      //cout<< step;

      mz[i][start-1]= c;
      recur(mz, start-1, i, step+1);
    }
  }

  if(i!=4){
    if(mz[i+1][start]=='.'){

      c = digits[step];
      //cout<< step;

      mz[i+1][start]= c;
      recur(mz,start, i+1, step+1);
    }
  }
  return mz;

}

maze findLongestPath(maze mz){

  char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
  char c;

  for (int start = 0; start<7 ; start++){
    if (mz[0][start]=='.'){
      mz[0][start]=digits[0];

      if(mz[1][start]=='.'){
        mz[1][start]= digits[1];
        recur(mz, start, 1, 2);
      }
    }
  }
  return mz;

  /*for(int i=0; i < 5; i++){
    for(int j=0 ; j<7 ; j++){
      mz[i][j] = temp[i][j];
    }
  }*/
}


int main() 
{ 
   char maze[5][7];

  //file open
    ifstream fp("labyrinth.txt");

    if (! fp) {
      cout << "Error, file couldn't be opened" << endl; 
      return 1;
    }


    for (int i =0; i<5 ; i++ ){
      for(int j = 0 ; j<7 ; j++){
        fp >> maze[i][j];
        if ( ! fp ) {
              cout << "Error reading file for element " << i << "," << j << endl; 
              return 1; 
          }
      }
    }

    
    for (int i =0; i<5 ; i++ ){
      for(int j = 0 ; j<7 ; j++){
        cout << maze[i][j];
      }
      cout << endl;
    }
    cout<<"\n";

    findLongestPath(maze);

    for (int i =0; i<5 ; i++ ){
      for(int j = 0 ; j<7 ; j++){
        cout << maze[i][j];
      }
      cout << endl;
    }
    cout<<"\n";

    fp.close();
    return 0;

}
