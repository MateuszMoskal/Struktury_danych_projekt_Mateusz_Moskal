#pragma once
class Dictionary
{
public:
	virtual bool insert(int key, int value) = 0;
	virtual void remove(int key) = 0;
	virtual bool contains(int key) = 0;
	virtual int get(int key) = 0;
	virtual void clean() = 0;
	virtual void cleanAndResize(int size) = 0;
};
