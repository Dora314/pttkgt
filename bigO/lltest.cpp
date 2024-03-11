#include <iostream>
#include <random>
#include <chrono>
#include <ratio>

using namespace std;

// Cấu trúc nút
struct Node {
  int data;
  Node* next;
};

// Hàm sinh số ngẫu nhiên
int randomInt(int min, int max) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(min, max);
  return dist(gen);
}

// Hàm thêm nút vào danh sách liên kết đơn
void addNode(Node*& head, int data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

// Hàm tìm kiếm số trong danh sách liên kết đơn
bool search(Node* head, int data) {
  while (head != nullptr) {
    if (head->data == data) {
      return true;
    }
    head = head->next;
  }
  return false;
}

// Hàm main
int main() {
  // Tạo danh sách liên kết đơn
  Node* head = nullptr;
  for (int i = 0; i < 10000; i++) {
    addNode(head, randomInt(1, 10000));
  }

  // Tìm kiếm số ngẫu nhiên và đo thời gian
  int searchNumber = randomInt(1, 10000);
  chrono::high_resolution_clock::time_point start, end;
  start = chrono::high_resolution_clock::now();
  bool found = search(head, searchNumber);
  end = chrono::high_resolution_clock::now();

  // In kết quả
  cout << "Số cần tìm: " << searchNumber << endl;
  cout << "Tìm thấy: " << (found ? "Có" : "Không") << endl;
  cout << "Thời gian tìm kiếm: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

  return 0;
}
