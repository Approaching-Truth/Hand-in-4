#ifndef _BINARY_HEAP_MAX_H_
#define _BINARY_HEAP_MAX_H_

#include <stdexcept>
#include <vector>

using namespace std;

template <typename Comparable>
class BinaryHeap {
  private:
	int currentSize;	        // Number of elements in heap
	vector<Comparable> array;	// The heap array

	void buildHeap();
	void maxHeapify(int hole);

  public:
    void printHeapArray() { //Function to print array
        for (int i: array)
            std::cout << i << ' ';
    }
	BinaryHeap(int capacity = 100) : array(capacity + 1), currentSize(0) {};

	BinaryHeap(const vector<Comparable> &items) {
		array.resize(items.size() + 10);
		for (int i = 0; i < items.size(); ++i)
			array[i + 1] = items[i];
		buildHeap();
		currentSize = items.size() + 1;
	}

	bool isEmpty() const { return currentSize == 0; }

	void insert(const Comparable& x);
	const Comparable& findMax() const; //Should find and return the largest element in max-heap
	void deleteMax(); //should delete max element in heap
	void deleteMax(Comparable& minItem);

};

#include "binary_heap_max.tpp"

#endif
