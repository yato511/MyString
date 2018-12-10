#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class MyString
{
public:

	//
	//Iterator and reverse_interator
	//
	class iterator {
	private:
		char* ite;
	public:
		iterator();
		iterator(char* s);
		iterator(const iterator& i);
		char operator*();
		iterator& operator = (char* s);
		iterator& operator++();
		iterator& operator++(int);
		iterator& operator--();
		iterator& operator--(int);
		iterator& operator+(size_t index);
		iterator& operator+=(size_t index);
		iterator& operator-(size_t index);
		iterator& operator-=(size_t index);
		bool operator==(const MyString::iterator& i);
		bool operator!=(const MyString::iterator& i);
	};
	class reverse_iterator {
	private:
		char* rite;
	public:
		reverse_iterator();
		reverse_iterator(char* s);
		reverse_iterator(const reverse_iterator& i);
		char operator*();
		reverse_iterator& operator = (char* s);
		reverse_iterator& operator++();
		reverse_iterator& operator++(int);
		reverse_iterator& operator--();
		reverse_iterator& operator--(int);
		reverse_iterator& operator+(size_t index);
		reverse_iterator& operator+=(size_t index);
		reverse_iterator& operator-(size_t index);
		reverse_iterator& operator-=(size_t index);
		bool operator==(const MyString::reverse_iterator& i);
		bool operator!=(const MyString::reverse_iterator& i);
	};


	//
	//Constructer
	//
	MyString();
	MyString(const MyString& str);
	MyString(const MyString& str, size_t pos, size_t len);
	MyString(const char* s);
	MyString(const char* s, size_t n);
	MyString(size_t n, char c);
	MyString(MyString::iterator first, MyString::iterator last);
	MyString(MyString::reverse_iterator first, MyString::reverse_iterator last);


	//
	//Destructor
	//
	~MyString();


	//
	//Iterators access
	//
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();


	//
	//Capacity
	//
	size_t size() const;
	size_t length() const;
	size_t max_size() const;
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t capacity() const;
	void reserve(size_t n = 0);
	void clear();
	bool empty() const;
	void shrink_to_fit();


	//
	//Element access
	//
	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;
	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;


	//
	//Modifiers
	//
	MyString& operator= (const MyString& str);
	MyString& operator= (const char* s);
	MyString& operator= (char c);

	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);

	MyString& append(const MyString& str);
	MyString& append(const MyString& str, size_t subpos, size_t sublen);
	MyString& append(const char* s);
	MyString& append(const char* s, size_t n);
	MyString& append(size_t n, char c);
	MyString& append(MyString::iterator first, MyString::iterator last);
	MyString& append(MyString::reverse_iterator first, MyString::reverse_iterator last);

	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_t subpos, size_t sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, size_t n);
	MyString& assign(size_t n, char c);
	MyString& assign(MyString::iterator first, MyString::iterator last);
	MyString& assign(MyString::reverse_iterator first, MyString::reverse_iterator last);

	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);
	void insert(MyString::iterator p, size_t n, char c);
	MyString::iterator insert(MyString::iterator p, char c);
	MyString& insert(MyString::iterator p, MyString::iterator first, MyString::iterator last);
	MyString& insert(MyString::iterator p, MyString::reverse_iterator first, MyString::reverse_iterator last);

	MyString& erase(size_t pos, size_t len);
	MyString::iterator erase(MyString::iterator p);
	MyString::iterator erase(MyString::iterator first, MyString::iterator last);

	MyString& replace(size_t pos, size_t len, const MyString& str);
	MyString& replace(MyString::iterator i1, MyString::iterator i2, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(MyString::iterator i1, MyString::iterator i2, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(MyString::iterator i1, MyString::iterator i2, const char* s, size_t n);
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	MyString& replace(MyString::iterator i1, MyString::iterator i2, size_t n, char c);
	MyString& replace(MyString::iterator i1, MyString::iterator i2, MyString::iterator first, MyString::iterator last);

	void swap(MyString& str);

	void push_back(char c);
	void pop_back();



	//
	//String operations
	//
	const char* c_str() const;
	const char* data() const;

	size_t copy(char* s, size_t len, size_t pos) const;

	size_t find(const MyString& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;

	size_t rfind(const MyString& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;

	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;

	size_t find_last_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;

	size_t find_first_not_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;

	size_t find_last_not_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;

	MyString substr(size_t pos = 0, size_t len = npos) const;

	int compare(const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

	//
	//Non - member function overloads
	//
	friend MyString operator +(const MyString &s1, const MyString &s2);
	friend MyString operator +(const MyString& lhs, const char* rhs);
	friend MyString operator +(const char* lhs, const MyString& rhs);
	friend MyString operator +(const MyString& lhs, char rhs);
	friend MyString operator +(char lhs, const MyString& rhs);

	friend istream& operator >> (istream& inStream, MyString &s);
	friend ostream& operator << (ostream& outStream, const MyString &s);

	friend void getline(istream& inStream, MyString&s);

	friend bool operator == (const MyString& s1, const MyString& s2);
	friend bool operator != (const MyString& s1, const MyString& s2);
	friend bool operator < (const MyString& s1, const MyString &s2);
	friend bool operator > (const MyString &s1, const MyString &s2);
	friend bool operator >= (const MyString &s1, const MyString &s2);
	friend bool operator <= (const MyString &s1, const MyString &s2);

private:
	char* _str;
	size_t _length;
	static const size_t npos;

};

size_t Length(const char*);
