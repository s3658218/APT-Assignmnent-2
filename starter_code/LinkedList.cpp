
#include "LinkedList.h"
#include "Tile.h"
#include "TileCodes.h"
#include "Player.h"
#include "GameMenu.h"
#include <string>
#include <iostream>


GameMenu gm;
using std::string;

void removeNode(Node* n){
Node* temp = nullptr;
// setting a location to the next spot in the linkedlist
if ( n -> next != nullptr){
temp = n -> next;
}
//while the next position isn't a nullptr, make the head the next position
if (n -> next != nullptr){
   n -> tile = temp -> tile;
   n -> next = temp -> next;
   free(temp);
}else{
//else it just sets the head as null
   free(n);
 }
}

void LinkedList::addBackToBag(Node* hand){
   // creating a new node to add to the end of the bag
   Node* tmp = new Node();
   //setting the new node value as the hand's value
   tmp -> tile = hand -> tile;
   tmp -> next = nullptr;
   //setting a node to iterate through the linked list
   Node* ptr = headBag;
   //finding the end of the linked list
   while (ptr -> next != nullptr){
      ptr = ptr -> next;
   }
   ptr -> next = tmp;
   ptr = ptr -> next;
}
void LinkedList::createBag(Tile* tile){
   Node* tmp = new Node();
   tmp -> tile = tile;
   tmp -> next = nullptr;
   if (headBag == nullptr){
      headBag = tmp;
   }else{
   Node* ptr = headBag;
   while (ptr -> next != nullptr){
      ptr = ptr -> next;
   }
   ptr -> next = tmp;
   ptr = ptr -> next;
   }
}

Node* LinkedList::deal(Node* hand){
   Node* tmp = new Node();
   tmp -> tile = headBag -> tile;
   tmp -> next = nullptr;
   if (hand == nullptr){
      hand = tmp;
      removeNode(headBag);
      return hand;
   }else{
   Node* ptr = hand;
   while (ptr -> next != nullptr){
      ptr = ptr -> next;
   }
   ptr -> next = tmp;
   ptr = ptr -> next;
   removeNode(headBag);
   return hand;
   }
}
Node* LinkedList::replaceTile(Node* hand, int index, Node* bag){
   Node* temp = hand;
   //if the index is 0 it will replace the head tile
   if (index == 0){
      addBackToBag(hand);
      hand -> tile = bag -> tile;
      removeNode(bag);
      return hand;
   } else {
   //find the position in the linkedlist with the index and replace at that position
   for (int i = 0; i < index; i++){
      temp = temp -> next;
   }
   addBackToBag(temp);
   temp -> tile = bag -> tile;
   removeNode(bag);
   return hand;
   }
}
Node* LinkedList::placeTile(Node* hand, int index){
   Node* temp = hand;
   if (index == 0){
      removeNode(hand);
      deal(hand);
      return hand;
   } else {
      for (int i = 0; i < index; i++){
      temp = temp -> next;
   }
   removeNode(temp);
   deal(hand);
   return hand;
   }

}

void LinkedList::tileComparePlace(Node* n, Tile* tile){
   int index = 0;
   int counter = 0;
   Node* temp = n;
   Tile tempTile = *tile;
   while (counter <= 6){
   Tile* nodeTileptr = temp -> tile;
   Tile nodeTile = *nodeTileptr;
      if (tempTile.colour == nodeTile.colour && tempTile.shape == nodeTile.shape){
         std::cout << "Placed tile" <<  std::endl;
         placeTile(n, index);
         counter = 8;
         gm.tileCheck = true;
      } else {
         if(temp -> next != nullptr){
         temp = temp -> next;
         }
         counter++;
         index++;
      }
   }
  if (counter == 6){ std::cout << "Enter a valid tile" << std::endl;
  delete tile;
  }
}
// void LinkedList::tileCompareReplace(string player, Tile* tile, bool check){
//    int index = 0;
//    int counter = 0;
//    Node* temp = nullptr;
//    if (player == pp.player1){
//       temp = p1Head;
//    } else if (player == pp.player2){
//       temp = p2Head;
//    }
//    while (counter <= 6){
//    Tile tempTile = *tile;
//    Tile* nodeTileptr = temp -> tile;
//    Tile nodeTile = *nodeTileptr;
//       if (tempTile.colour == nodeTile.colour && tempTile.shape == nodeTile.shape){
//          std::cout << "Replaced tile" <<  std::endl;
//          replaceTile(temp, index, headBag);
//          counter = 8;
//          check = true;
//       } else {
//          if(temp -> next != nullptr){
//          temp = temp -> next;
//          }
//          counter++;
//          index++;
//       }
//    }
//   if (counter == 7){ std::cout << "Enter a valid tile" << std::endl;
//    delete tile;
//   }
// }

LinkedList::LinkedList() {
   headBag = nullptr;
   p1Head = nullptr;
   p2Head = nullptr;
}

LinkedList::~LinkedList() {
       Node* temp = headBag;
    while (temp != nullptr)
    {
        Node* del = del;
        temp = temp->next;
        delete temp;
    }
}

