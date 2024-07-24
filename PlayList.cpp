
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "PlayList.h"
#include "Song.h"

// PlayList method implementations go here

PlayList::PlayList() {
  this->head = NULL;
}


PlayList::PlayList(const PlayList& pl) {
  PlayListNode* temp = pl.head;
  int i = 0;
  while (temp != NULL) {
    insert(temp->song, i);
    temp = temp->next;
    i++;
  } 
}


PlayList& PlayList::operator=(const PlayList & pl) {
  PlayListNode* current = head;
  PlayListNode* next = NULL;
  while (current != NULL) {
    next = current->next;
    delete current;
    current = next;
  }

  PlayListNode* temp = pl.head;
  int i = 0;
  while (temp != NULL) {
    insert(temp->song, i);
    temp = temp->next;
    i++;
  }

  return *this;
}


PlayList::~PlayList() {
  PlayListNode* current = head;
  while (current != NULL) {
    PlayListNode* next = current->next;
    delete current;
    current = next;
  }
  head = 0;
}


void PlayList::insert(Song sng, unsigned int pos) {
  if (pos > length || pos < 0) {
    std::cout << "Position is out of range. Cannot insert." << std::endl;
    return;
  }

  PlayListNode* newNode = new PlayListNode(sng);
  newNode->next = NULL;
  

  if (head == NULL) {
    head = newNode;
    length++;
    return;
  }
  
  PlayListNode* temp = head;
  if (pos == 0) {
    newNode->next = temp;
    head = newNode;
    length++;
    return;
  }

  int i = 0;
  while (i < pos-1) {
    temp = temp->next;
    i++;
  }
  
  newNode->next = temp->next;
  temp->next = newNode;
  length++;
  return;
}


Song PlayList::remove(unsigned int pos) {
  if (length < 1) {
    throw std::out_of_range("The playlist is empty.");
  }

  if (length <= pos || pos < 0) {
    throw std::out_of_range("The position is out of range.");
  }

  PlayListNode* temp1 = head;
  PlayListNode* temp2 = NULL;

  temp1 = head;
  if (pos == 0) {
    head = head->next;
  }

  else {
    int count = 0;
    while (count < pos) {
      temp2 = temp1;
      temp1 = temp1->next;
      count++;
    }
    temp2->next = temp1->next;
  }
  length--;
  Song oldSong = temp1->song;
  delete temp1;
  return oldSong;
}


void PlayList::swap(unsigned int pos1, unsigned int pos2) {
  if (length < 2) {
    std::cout << "The playlist does not have enough songs to do a swap." << std::endl;
    return;
  }

  if (pos1 >= length || pos2 >= length) {
    std::cout << "The songs are out of range. Cannot do a swap." << std::endl << std::endl;
    return;
  }

  if (pos1 == pos2) {
    return;
  }
 
  PlayListNode* prev1 = NULL;
  PlayListNode* current1 = head;
  unsigned int i = 0;
  while (current1 && i != pos1) {
    prev1 = current1;
    current1 = current1->next;
    i++;
  }
 
  PlayListNode* prev2 = NULL;
  PlayListNode* current2 = head;
  i = 0;
  while (current2 && i != pos2) {
    prev2 = current2;
    current2 = current2->next;
    i++;
  }
 
  if (current1 == NULL || current2 == NULL) {
    return;
  }
 
  if (prev1 != NULL) {
    prev1->next = current2;
  }
  else {
    head = current2;
  }
 
  if (prev2 != NULL) {
    prev2->next = current1;
  }
  else {
    head = current1;
  }
  PlayListNode* temp = current2->next;
  current2->next = current1->next;
  current1->next = temp;
  return;
}


Song PlayList::get(unsigned int pos) const {
  if (length < 1) {
    throw std::out_of_range("The playlist is empty.");
  }
  
  if (pos < 0 || pos >= length) {
    throw std::out_of_range("The position entered is out of range");
  }

  PlayListNode* temp = head;
  int i = 0;
  while (i != pos) {
    temp = temp->next;
    i++;
  }
  return temp->song;
}


unsigned int PlayList::size() const {
  return length;
}