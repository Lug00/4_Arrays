#pragma once
#include <iostream>
//#include "Entity.h"
//#include "Weapon.h"
//#include "Character.h"

template <typename T>
class GenericArray
{
	size_t size;
	T* array;

public:

	GenericArray()
	{
		size = 0;
		array = nullptr; //new T[0]
	}
	GenericArray(size_t newsize)
	{
		size = newsize;
		array = new T[newsize];
	}
	~GenericArray()
	{
		if (array != nullptr)
		{
			delete[] array;
			size = 0;
		}
	}

	T& operator[](size_t index)
	{
		return array[index];
	}

	void resize(size_t newSize)
	{
		T* newdata = new T[newSize];
		if (newSize < size)
		{
			for (int i = 0; i < newSize; i++)
			{
				newdata[i] = array[i];
			}
			delete[] array;
			array = newdata;
			size = newSize;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				newdata[i] = array[i];
			}
			delete[] array;
			array = newdata;
			size = newSize;
		}
	}

	size_t getsize() const
	{
		return size;
	}

	size_t sizebytes()
	{
		return sizeof(T);
	}

	void printvalues()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "[" << i << "] = " << array[i] << std::endl;
		}

		//ADD
		T Add(T newitem)
		{
			resize(size + 1);

		}
	}
};

//template specialization
template<>
inline void GenericArray<Entity>::listContents()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << i << "] = " << array[i].toString() << std::endl;
	}
}

template<>
inline void GenericArray<Weapon>::listContents()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << i << "] = " << array[i].toString() << std::endl;
	}
}

template<>
inline void GenericArray<Character>::listContents()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << i << "] = "
			<< array[i].toString()
			<< "(" << array[i].GetType() << ")"
			<< std::endl;
	}
}
