
/* 
Big O Notation:

The worst case running time of the default constructor is O(1) because there is only one line of 
code and all it does is specify that he head is equal to NULL.

The worst case running time of the destructor is O(N) because there is a loop that will continue to go
through the entire linked list and delete each node.

The worst case running time of the copy constructor is O(N^2) because there is a loop that will continue to go
through the entire linked list of the object that is being copied and will stop when it hits the final node (NULL).
And inside of that loop, the insert function is being called that is O(N) as well (described more in depth when
I talk about it's running time), so since there is a nested loop it will be O(N^2).

The worst case running time of the overloaded assignment operator is O(N^2) because even though there are two loops
that both run through the entire linked list that is being copied and destroyed, and inside of one of the loops
the insert function is being called which is also O(N). Therefore, the running time is O(N^2).

The worst case running time of the insert function is O(N) because there is a while loop that will go through
the linked list to find the position to insert the song in the playlist.

The worst case running time of the remove funciton is O(N) because there is a loop that will go through the 
linked list to find the position of the song to remove in the playlist.

The worst case running time of the get function is O(N) because the loop will continue to run through the linked
list until it finds the position of the song to get in the playlist.

The worst case running time of the swap function is O(N) because even though there are two loop that both
run through the linked list to find the desired position, the loops are not nested. Therefore, the worst
case running time would be O(N) + O(N) = 2*O(N) but since you drop the constants, it would just be O(N).

The worst case running time of the size function is O(1) because there is just one line that is just returning 
the length private variable.

The worst case running time of the enter a song command is O(N^2) because it is inside a while loop that is O(N) 
and will continue to run until the program is ended and it calls the insert function that is O(N) as well.
Also, there are error loops but they dont count.

The worst case running time of the remove a song command is O(N^2) because it is inside a while loop that is O(N) 
and will continue to run until the program is ended and it calls the remove function that is O(N) as well.
Also, there are error loops but they dont count.

The worst case running time of the swap two songs command is O(N^2) because it is inside a while loop that is O(N) 
and will continue to run until the program is ended and it calls the swap function that is O(N) as well.
Also, there are error loops but they dont count.

The worst case running time of the print all songs command is O(N^2) because it runs a loop (O(N)) that will go 
through the length of the playlist and at each iteration it will call the get function that is O(N) as well. Therefore,
the nested loops will give us O(N^2).
*/

#include <iostream>
#include <string>
#include "Song.h"
#include "PlayList.h"


void menu() {
  bool loop = true;
  bool lp = true;
  double a1;
  std::cout << "Hello, use the menu below to create your very own playlist!" << std::endl << std::endl;
  std::cout << "Menu:" << std::endl;
  std::cout << "1 - Enter a song with its position in the playlist" << std::endl;
  std::cout << "2 - Remove a song from the playlist" << std::endl;
  std::cout << "3 - Swap two songs in the playlist" << std::endl;
  std::cout << "4 - Print all the songs in the playlist" << std::endl;
  std::cout << "5 - Quit" << std::endl;

  PlayList P;

  while (loop) {
    std::cin.clear();
    std::cout << "Select 1 (enter), 2 (remove), 3 (swap), 4 (print), or 5 (quit): ";
    std::cin >> a1;

    while (lp) {
      if (a1 == 1 || a1 == 2 || a1 == 3 || a1 == 4 || a1 == 5) {
        break;
      }
      std::cout << "Please try again. Select an integer from 1 to 5." << std::endl;
      std::cout << "Select 1 (enter), 2 (remove), 3 (swap), 4 (print), or 5 (quit): ";
      std::cin.clear();
      std::cin.ignore(256, '\n');
      std::cin >> a1;
    }

    unsigned int a = a1;
    
    //Enter a song command
    if (a == 1) {
      std::cin.ignore(256, '\n');
      string a, b;
      int c;
      std::cout << "Song name: ";
      std::getline(std::cin, a);
      std::cout << "Artist name: ";
      std::getline(std::cin, b);
      std::cout << "Length (seconds): ";
      std::cin >> c;
      while (std::cin.fail()) {
        std::cout << "Error. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Time: ";
        std::cin >> c;
      }

      Song S(a,b,c);

      int position = P.size();
      int d;
      std::cin.clear();
      std::cin.ignore(256, '\n');
      if (position == 0) {
        std::cout << "Enter position (1): ";
      }
      else {
        std::cout << "Enter position (1 to " << position+1 << "): ";
      }
      std::cin >> d;
      bool lp = true;
      while (lp) {
        if (d > position+1 || d < 1) {
          std::cout << "Out of range. Please try again." << std::endl;
          if (position == 0) {
            std::cout << "Enter position (1): ";
          }
          else {
            std::cout << "Enter position (1 to " << position+1 << "): ";
          }
          std::cin.clear();
          std::cin.ignore(256, '\n');
          std::cin >> d;
        }
        else {
          break;
        }
      }
      P.insert(S,d-1);
      std::cout << "You have entered " << S.getName() << " at position " << d << " in the playlist." << std::endl << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
    }


    // Remove a song
    else if (a == 2) {
      int position = P.size();
      if (position < 1) {
        std::cout << "The playlist is empty. You must add at least one song first." << std::endl << std::endl;
      }
      else {
        if (position == 1) {
          std::cout << "Select position to remove a song (1): ";
        }
        else {
          std::cout << "Select position to remove a song (1 to " << position << "): "; 
        }
        std::cin.clear();
        std::cin.ignore(256, '\n');
        int a;
        std::cin >> a;
        bool lp = true;
        while (lp) {
          if (a > position || a < 1) {
            std::cout << "Out of range. Please try again." << std::endl;
            if (position == 1) {
              std::cout << "Select position to remove a song (1): ";
            }
            else {
              std::cout << "Select position to remove a song (1 to " << position << "): ";
            }
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> a;
          }
          else {
            break;
          } 
        }

        Song out = P.remove(a-1);
        std::cout << "You have removed " << out.getName() << " from the playlist." << std::endl << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n'); 
      }
    }

    // Swap two songs
    else if (a == 3) {
      int position = P.size();
      if (position < 2) {
        std::cout << "Not enough songs in the playlist to swap. Please add more." << std::endl<< std::endl;
      }
      else {
        std::cout << "Swap song at position (1 to " << position << "): ";
        int e;
        int f;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> e;
        std::cout << "with song at position (1 to " << position << "): ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> f;
        while (lp) {
          if (e < 1 || f < 1 || e > P.size() || f > P.size()) {
            std::cout << std::endl;
            std::cout << "Out of range. Please try again." << std::endl;
            std::cout << "Swap song at position (1 to " << position << "): ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> e;
            std::cout << "with song at position (1 to " << position << "): ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> f;
          }
          else {
            break;
          }
        }
        P.swap(e-1,f-1);
        std::cout << "The songs at position " << e << " and " << f << " have been swapped." << std::endl << std::endl;
      }
    }


    //Print all the songs
    else if (a == 4) {
      std::cout << std::endl;
      int position = P.size();
      if (position < 1) {
        std::cout << "The playlist is empty. Please enter at least one song." << std::endl << std::endl;
      }
      else {
        int i = 0;
        int j = 1;
        while (j <= position) {
          std::cout << j << ". " << P.get(i).getName() << " (" << P.get(i).getArtist() << ") " << P.get(i).getLength() << "s" << std::endl;
          i++;
          j++;
        } 
        std::cout << std::endl; 
      }
    }


    //Exit
    else {
      std::cout << std::endl;
      std::cout << "You have quit the program. Thanks for listening!" << std::endl << std::endl;
      loop = false;
    }
  }
}


int main() {
  menu();

  return 0;
}
