#pragma once
class Dictionary
{
public:
	virtual void insert(int key, int value) = 0;
	virtual void remove(int key) = 0;
	virtual bool contains(int key) = 0;
	virtual int get(int key) = 0;
};
