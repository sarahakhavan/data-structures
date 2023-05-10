//Sarah Akhavan Kazemzadeh
//9231057
//Data structures/final-project : minHeap.h


#ifndef __minHeap
#define __minHeap
#include <iostream>
#include <vector>

namespace DS{
	template <class T>
	class minHeap
	{
	private:
		std::vector<T> _vector;
		void heapify();
		void floatUp(int index);
		void floatDown(int index);
	public:
		//comstructors:
		minHeap();
		minHeap(T* array, int length);
    	minHeap(const std::vector<T>& vector);
    	//destructors:
		~minHeap();

	public:
		void insert(T data);
		T getMin();
		void deleteMin();
		int size();
	
	};//template class minHeap
}//namespace DS
#endif