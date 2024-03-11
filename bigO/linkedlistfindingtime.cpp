#include <iostream>
#include <random>
#include <chrono>
#include <ratio>

using namespace std;

// Structure for a node in the singly linked list
struct NodeLL {
  int data;
  NodeLL* next;
};

// Function to generate a random integer within a specified range
int randomInt(int min, int max) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(min, max);
  return dist(gen);
}

// Function to create a new node with the given value
NodeLL* createNode(int value) {
  NodeLL* newNode = new NodeLL;
  newNode->data = value;
  newNode->next = nullptr;  // Use nullptr for modern C++
  return newNode;
}

// Function to add a node to the end of the singly linked list
NodeLL* addToTail(NodeLL* head, int value) {
  NodeLL* newNode = createNode(value);

  if (head == nullptr) {
    head = newNode;
  } else {
    NodeLL* temp = head;
    while (temp->next != nullptr) { // Use nullptr for clarity
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

// Function to search for a given number in the singly linked list
bool searchList(NodeLL* head, int value) {
  NodeLL* temp = head;
  while (temp != nullptr) {
    if (temp->data == value) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

int main() {
  // Create a singly linked list with 1,000,000 random integers between 1 and 100,000
  NodeLL* head = nullptr;
  for (int i = 0; i < 1000000; i++) {
    head = addToTail(head, randomInt(1, 100000));
  }

  // Generate a random number to search for
  int searchNumber = randomInt(1, 100000);

  // Use high-resolution clock for more accurate timing
  chrono::high_resolution_clock::time_point start, end;
  start = chrono::high_resolution_clock::now();

  // Search for the number
  bool found = searchList(head, searchNumber);

  end = chrono::high_resolution_clock::now();

  // Calculate and display search time in nanoseconds and microseconds
  auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
  cout << "Số cần tìm: " << searchNumber << endl;
  cout << "Đã tìm thấy " << (found ? "Có" : "Không") << endl;
  cout << "Thời gian tìm kiếm: " << duration.count() << " ns" << endl;
  cout << "                 hoặc " << chrono::duration_cast<chrono::microseconds>(duration).count() << " μs" << endl;

  return 0;
}
