//Sarah Akhavan Kazemzadeh
//9231057
//Data structures / final-project : minHeap.cpp

#include "minHeap.h"
#include <iostream>
#include <vector>

namespace DS {
	//constructors:
	template <class T>
	minHeap<T>::minHeap(T* array, int length) : _vector(length){
    	for(int i = 0; i < length; i++)
    	{
        	_vector[i] = array[i];
    	}

    	heapify();
	}

	template <class T>
	minHeap<T>::minHeap(const std::vector<T>& vector) : _vector(vector){
	    heapify();
	}

	template <class T>
	minHeap<T>::minHeap()
	{}


	//destructors:
	template <class T>
	minHeap<T>::~minHeap()
	{}

	//functions:

	template <class T>
	void minHeap<T>::heapify(){
    	int length = _vector.size();
    	for(int i=length-1; i>=0; i--)
    	{
        	floatDown(i);
    	}	
	}//heapify	

	template <class T>
	void minHeap<T>::floatDown(int index){
	    int length = _vector.size();
	    int leftChildIndex = 2*index + 1;
	    int rightChildIndex = 2*index + 2;

	    if(leftChildIndex >= length)
	        return; //index is a leaf

	    int minIndex = index;

	    if(_vector[index] > _vector[leftChildIndex]){
	        minIndex = leftChildIndex;
	    }
	    
	    if((rightChildIndex < length) && (_vector[minIndex] > _vector[rightChildIndex])){
	        minIndex = rightChildIndex;
	    }

	    if(minIndex != index){
        //need to swap
    	    T temp = _vector[index];
	        _vector[index] = _vector[minIndex];
  	    	_vector[minIndex] = temp;
        	floatDown(minIndex);
    	}
	}//floatDown

	template <class T>
	void minHeap<T>::floatUp(int index){
	    if(index == 0)
	        return;

	    int parentIndex = (index-1)/2;

	    if(_vector[parentIndex]> _vector[index])
	    {
	        T temp = _vector[parentIndex];
	        _vector[parentIndex] = _vector[index];
	        _vector[index] = temp;
	        floatUp(parentIndex);
	    }
	}//floatUp

	template <class T>
	void minHeap<T>::insert(T data){
	    int length = _vector.size();
	    _vector.push_back(data);

	    floatUp(length);
	}//insert

	template <class T>
	T minHeap<T>::getMin(){
		//if _vector.size() == 0 -> throw exception
	    return _vector[0];
	}//getMin
    
    template <class T>
	void minHeap<T>::deleteMin(){
	    int length = _vector.size();

	    if(length == 0)	return; //if the Heap is already empty!!
    
	    _vector[0] = _vector[length-1];
	    _vector.pop_back();

	    floatDown(0);
	}//deleteMin

	template <class T>
	int minHeap<T>::size(){
		return (int)_vector.size();
	}


}//namespace D
