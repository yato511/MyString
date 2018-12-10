#include "MyString.h"


#pragma region MyString Constructors
size_t const MyString::npos = -1;
MyString::MyString() {
	this->_length = 0;
	this->_str = new char;
	this->_str[0] = '\0';
}
MyString::MyString(const MyString& s)
{
	this->_length = s._length;
	this->_str = new char[_length + 1];
	for (size_t i = 0; i < this->_length; i++) {
		this->_str[i] = s._str[i];
	}
	this->_str[_length] = '\0';
}
MyString::MyString(const MyString & str, size_t pos, size_t len)
{
	this->_length = len;
	this->_str = new char[_length + 1];
	size_t k = 0;
	for (size_t i = pos; k < _length; i++) {
		this->_str[k] = str._str[i];
		k++;
	}
	this->_str[_length] = '\0';
}
MyString::MyString(const char* str) {
	this->_length = Length(str);
	this->_str = new char[this->_length + 1];
	size_t i;
	for (i = 0; i < this->_length; i++) {
		this->_str[i] = str[i];
	}
	this->_str[i] = '\0';
}
MyString::MyString(const char * s, size_t n)
{
	this->_length = n;
	this->_str = new char[this->_length + 1];
	size_t i;
	for (i = 0; i < this->_length; i++) {
		this->_str[i] = s[i];
	}
	this->_str[i] = '\0';
}
MyString::MyString(size_t n, char c)
{
	this->_length = n;
	this->_str = new char[this->_length + 1];
	size_t i;
	for (i = 0; i < this->_length; i++) {
		this->_str[i] = c;
	}
	this->_str[i] = '\0';
}
MyString::MyString(MyString::iterator first, MyString::iterator last)
{
	int i = 0;
	for (auto it = first; it != last; it++) {
		i++;
	}
	this->_length = i;
	this->_str = new char[this->_length + 1];
	int k = 0;
	for (auto it = first; it != last; it++) {
		this->_str[k] = *it;
		k++;
	}
	this->_str[i] = '\0';
}
MyString::MyString(MyString::reverse_iterator first, MyString::reverse_iterator last)
{
	int i = 0;
	for (auto it = first; it != last; it++) {
		i++;
	}
	this->_length = i;
	this->_str = new char[this->_length + 1];
	int k = 0;
	for (auto it = first; it != last; it++) {
		this->_str[k] = *it;
		k++;
	}
	this->_str[i] = '\0';
}
#pragma endregion

#pragma region MyString Destructor
MyString::~MyString()
{
	if (_str != NULL)
	{
		delete[] this->_str;
		this->_str = NULL;
		//cout << "Deleted" << endl;
		_length = 0;
	}
}
#pragma endregion

#pragma region MyString iterator and reverse_iterator
MyString::iterator MyString::begin() {
	return iterator(this->_str);
}
MyString::iterator MyString::end()
{
	return iterator(this->_str + _length);
}
MyString::reverse_iterator MyString::rbegin() {
	return reverse_iterator(this->_str + _length - 1);
}
MyString::reverse_iterator MyString::rend()
{
	return reverse_iterator(this->_str - 1);
}
#pragma endregion

#pragma region MyString Capacity
size_t MyString::size() const {
	return Length(this->_str);
}
size_t MyString::length() const {
	return Length(this->_str);
}
size_t MyString::max_size() const {
	return INT_MAX;
}
void MyString::resize(size_t n)
{
	if (n < this->_length) {
		this->erase(n + 1, this->_length - n);
	}
	else if (n > this->_length) {
		MyString temp = *this;
		this->_length = n;
		this->_str = new char[this->_length + 1];
		for (int i = 0; i <= temp._length; i++) {
			this->_str[i] = temp._str[i];
		}
	}
}
void MyString::resize(size_t n, char c)
{
	if (n < this->_length) {
		this->erase(n + 1, this->_length - n);
	}
	else if (n > this->_length) {
		MyString temp = *this;
		this->_length = n;
		this->_str = new char[this->_length + 1];
		for (int i = 0; i < temp._length; i++) {
			this->_str[i] = temp._str[i];
		}
		for (int i = temp._length; i < n; i++) {
			this->_str[i] = c;
		}
		this->_str[n] = '\0';
	}
}
size_t MyString::capacity() const
{
	return this->_length + 1;
}
void MyString::reserve(size_t n)
{
	this->resize(n);
}
void MyString::clear()
{
	delete[] this->_str;
	this->_str = new char;
	this->_str[0] = '\0';
	this->_length = 0;
}
bool MyString::empty() const
{
	if (this->_length == 0) return true;
	return false;
}
void MyString::shrink_to_fit()
{
	this->resize(Length(this->_str));
}
#pragma endregion

#pragma region MyString Element Access
char &MyString::operator[](size_t pos) {
	return this->_str[pos];
}
const char & MyString::operator[](size_t pos) const {
	return this->_str[pos];
}
char& MyString::at(size_t index) {
	return this->_str[index];
}
const char & MyString::at(size_t pos) const
{
	return this->_str[pos];
}
char& MyString::back()
{
	return this->_str[_length - 1];
}
const char & MyString::back() const
{
	return this->_str[_length - 1];
}
char& MyString::front()
{
	return this->_str[0];
}
const char & MyString::front() const
{
	return this->_str[0];
}
#pragma endregion

#pragma region MyString Modifiers
//Operator =
MyString & MyString::operator=(const MyString &s)
{
	this->_length = s._length;
	this->_str = new char[_length + 1];
	for (size_t i = 0; i < this->_length; i++) {
		this->_str[i] = s[i];
	}
	this->_str[_length] = '\0';
	return *this;
}
MyString & MyString::operator=(const char * s)
{
	this->_length = Length(s);
	this->_str = new char[_length + 1];
	for (size_t i = 0; i < this->_length; i++) {
		this->_str[i] = s[i];
	}
	this->_str[_length] = '\0';
	return *this;
}
MyString & MyString::operator=(char c)
{
	this->_length = 1;
	this->_str = new char[_length + 1];
	this->_str[0] = c;
	this->_str[1] = '\0';
	return *this;
}

//Operator +=
MyString & MyString::operator+=(const MyString & str)
{
	MyString x = this->_str;
	size_t l = this->_length;

	this->_length += str._length;
	this->_str = new char[this->_length + 1];
	for (size_t i = 0; i < l; i++) {
		this->_str[i] = x[i];
	}

	size_t j = 0;
	for (size_t i = l; i < this->_length; i++) {
		this->_str[i] = str[j++];
	}
	this->_str[this->_length] = '\0';
	return *this;
}
MyString & MyString::operator+=(const char * s)
{
	MyString x = this->_str;
	size_t l = this->_length;
	this->_length += Length(s);
	this->_str = new char[this->_length + 1];
	for (size_t i = 0; i < l; i++) {
		this->_str[i] = x[i];
	}
	size_t j = 0;
	for (size_t i = l; i < this->_length; i++) {
		this->_str[i] = s[j++];
	}
	this->_str[this->_length] = '\0';
	return *this;
}
MyString & MyString::operator+=(char c)
{
	MyString x = this->_str;
	size_t l = this->_length;
	this->_length++;
	this->_str = new char[this->_length + 1];
	size_t i;
	for (i = 0; i < l; i++) {
		this->_str[i] = x[i];
	}
	this->_str[i] = c;
	this->_str[this->_length] = '\0';
	return *this;
}

//Append
MyString & MyString::append(const MyString & str)
{
	this->operator+=(str);
	return *this;
}
MyString & MyString::append(const MyString & str, size_t subpos, size_t sublen)
{
	char* temp = new char[sublen + 1];
	size_t k = 0;
	for (size_t i = subpos; i < subpos + sublen; i++) {
		temp[k] = str[i];
		k++;
	}
	temp[k] = '\0';
	this->operator+=(temp);
	delete[] temp;
	return *this;
}
MyString& MyString::append(const char * s)
{
	this->operator+=(s);
	return *this;
}
MyString& MyString::append(size_t n, char c)
{
	char* s = new char[n + 1];
	for (size_t i = 0; i < n; i++) {
		s[i] = c;
	}
	s[n] = '\0';
	this->operator+=(s);
	delete[]s;
	return *this;
}
MyString& MyString::append(const char * s, size_t n)
{
	char *temp = new char[n + 1];
	size_t i;
	for (i = 0; i < n; i++) {
		temp[i] = s[i];
	}
	temp[i] = '\0';
	this->operator+=(temp);
	return *this;
}
MyString & MyString::append(MyString::iterator first, MyString::iterator last)
{
	char * temp = new char[1000];
	int i = 0;
	for (auto it = first; it != last; it++) {
		temp[i] = *it;
		i++;
	}
	temp[i] = '\0';
	this->operator+=(temp);
	delete[]temp;
	return *this;
}
MyString & MyString::append(MyString::reverse_iterator first, MyString::reverse_iterator last)
{
	char * temp = new char[1000];
	int i = 0;
	for (auto it = first; it != last; it++) {
		temp[i] = *it;
		i++;
	}
	temp[i] = '\0';
	this->operator+=(temp);
	delete[]temp;
	return *this;
}

//Assign
MyString & MyString::assign(const MyString & str)
{
	this->operator=(str);
	return *this;
}
MyString & MyString::assign(const MyString & str, size_t subpos, size_t sublen)
{
	MyString temp;
	temp.append(str, subpos, sublen);
	this->operator=(temp);
	return *this;
}
MyString& MyString::assign(const char * s)
{
	MyString temp = s;
	this->operator=(temp);
	return *this;
}
MyString& MyString::assign(const char * s, size_t n)
{
	MyString temp;
	temp.append(s, n);
	this->operator=(temp);
	return *this;
}
MyString& MyString::assign(size_t n, char c)
{
	MyString temp;
	temp.append(n, c);
	this->operator=(temp);
	return *this;
}
MyString & MyString::assign(MyString::iterator first, MyString::iterator last)
{
	MyString temp;
	temp.append(first, last);
	this->operator=(temp);
	return *this;
}
MyString & MyString::assign(MyString::reverse_iterator first, MyString::reverse_iterator last)
{
	MyString temp;
	temp.append(first, last);
	this->operator=(temp);
	return *this;
}

//Insert
MyString & MyString::insert(size_t pos, const MyString & str)
{
	MyString temp = *this;
	this->_length += str._length;
	this->_str = new char[this->_length + 1];
	size_t i;
	for (i = 0; i < pos; i++) {
		this->_str[i] = temp[i];
	}

	for (size_t k = 0; k < str._length; k++) {
		this->_str[i] = str[k];
		i++;
	}
	for (size_t j = pos; j <= temp._length; j++) {
		this->_str[i] = temp[j];
		i++;
	}
	return *this;
}
MyString & MyString::insert(size_t pos, const MyString & str, size_t subpos, size_t sublen)
{
	MyString temp = *this;
	this->_length += sublen;
	this->_str = new char[this->_length + 1];
	size_t i;
	for (i = 0; i < pos; i++) {
		this->_str[i] = temp[i];
	}

	for (size_t k = subpos; k < subpos + sublen; k++) {
		this->_str[i] = str[k];
		i++;
	}
	for (size_t j = pos; j <= temp._length; j++) {
		this->_str[i] = temp[j];
		i++;
	}
	return *this;
}
MyString & MyString::insert(size_t pos, const char * s)
{
	MyString temp = s;
	return this->insert(pos, temp);
}
MyString & MyString::insert(size_t pos, const char * s, size_t n)
{
	MyString temp = *this;
	this->_length += n;
	this->_str = new char[this->_length + 1];
	size_t i;
	for (i = 0; i < pos; i++) {
		this->_str[i] = temp[i];
	}

	for (size_t k = 0; k < n; k++) {
		this->_str[i] = s[k];
		i++;
	}
	for (size_t j = pos; j <= temp._length; j++) {
		this->_str[i] = temp[j];
		i++;
	}
	return *this;
}
MyString & MyString::insert(size_t pos, size_t n, char c)
{
	char*temp = new char[n + 1];
	for (size_t i = 0; i < n; i++) {
		temp[i] = c;
	}
	temp[n] = '\0';
	this->insert(pos, temp);
	delete[] temp;
	return *this;
}
void MyString::insert(MyString::iterator p, size_t n, char c)
{
	MyString temp = *this;
	this->_length += n;
	this->_str = new char[this->_length + 1];

	MyString::iterator it;
	size_t i = 0;
	for (it = temp.begin(); it != p; it++) {
		this->_str[i] = *it;
		i++;
	}
	for (size_t j = 0; j < n; j++) {
		this->_str[i] = c;
		i++;
	}
	this->_str[this->_length] = '\0';
}
MyString::iterator MyString::insert(MyString::iterator p, char c)
{
	size_t ppos = 0;
	for (MyString::iterator it = this->begin(); it != p; it++) {
		ppos++;
	}
	MyString temp = *this;
	this->_length++;
	this->_str = new char[this->_length + 1];
	size_t i = 0;
	MyString::iterator it;
	for (it = temp.begin(); it != p; it++) {
		this->_str[i] = *it;
		i++;
	}
	this->_str[i] = c; i++;
	for (; it != temp.end(); it++) {
		this->_str[i] = *it;
		i++;
	}
	this->_str[_length] = '\0';
	return MyString::iterator(this->begin() + ppos);
}
MyString & MyString::insert(MyString::iterator p, MyString::iterator first, MyString::iterator last)
{
	MyString temp = *this;
	size_t len = 0;
	for (MyString::iterator i = first; i != last; i++) {
		len++;
	}
	this->_length += len;
	this->_str = new char[this->_length + 1];
	size_t i = 0;
	MyString::iterator it;
	for (it = temp.begin(); it != p; it++) {
		this->_str[i] = *it;
		i++;
	}
	for (MyString::iterator it1 = first; it1 != last; it1++) {
		this->_str[i] = *it1;
		i++;
	}
	for (it = p; it != temp.end(); it++) {
		this->_str[i] = *it;
		i++;
	}
	this->_str[_length] = '\0';
	return *this;
}
MyString & MyString::insert(MyString::iterator p, MyString::reverse_iterator first, MyString::reverse_iterator last)
{
	MyString temp = *this;
	size_t len = 0;
	for (MyString::reverse_iterator i = first; i != last; i++) {
		len++;
	}
	this->_length += len;
	this->_str = new char[this->_length + 1];
	size_t i = 0;
	MyString::iterator it;
	for (it = temp.begin(); it != p; it++) {
		this->_str[i] = *it;
		i++;
	}
	for (MyString::reverse_iterator it1 = first; it1 != last; it1++) {
		this->_str[i] = *it1;
		i++;
	}
	for (it = p; it != temp.end(); it++) {
		this->_str[i] = *it;
		i++;
	}
	this->_str[_length] = '\0';
	return *this;
}

//Erase
MyString & MyString::erase(size_t pos, size_t len)
{
	MyString temp = *this;
	if (_length < pos + len)
		len = this->_length - pos;
	this->_length -= len;
	this->_str = new char[this->_length + 1];
	for (size_t i = 0; i < pos; i++) {
		this->_str[i] = temp._str[i];
	}
	for (size_t i = pos; i < temp._length; i++) {
		this->_str[i] = temp._str[i + len];
	}
	this->_str[_length] = '\0';
	return *this;
}
MyString::iterator MyString::erase(MyString::iterator p)
{
	size_t ppos = 0;
	for (MyString::iterator it = this->begin(); it != p; it++) {
		ppos++;
	}
	MyString temp = *this;
	this->_length--;
	this->_str = new char[this->_length + 1];
	size_t k = 0;
	for (MyString::iterator i = temp.begin(); i != p; i++) {
		this->_str[k] = *i;
		k++;
	}
	for (MyString::iterator i = p + 1; i != temp.end(); i++) {
		this->_str[k] = *i;
		k++;
	}
	this->_str[_length] = '\0';
	return MyString::iterator(this->begin() + ppos);
}
MyString::iterator MyString::erase(MyString::iterator first, MyString::iterator last)
{
	size_t ppos = 0;
	for (MyString::iterator it = this->begin(); it != first; it++) {
		ppos++;
	}
	size_t len = 0;
	for (MyString::iterator it = first; it != last; it++) {
		len++;
	}
	MyString temp = *this;
	this->_length -= len;
	this->_str = new char[this->_length + 1];
	size_t k = 0;
	for (MyString::iterator i = temp.begin(); i != first; i++) {
		this->_str[k] = *i;
		k++;
	}
	for (MyString::iterator i = last; i != temp.end(); i++) {
		this->_str[k] = *i;
		k++;
	}
	this->_str[_length] = '\0';
	return MyString::iterator(this->begin() + ppos);
}

//Replace
MyString & MyString::replace(size_t pos, size_t len, const MyString & str)
{
	MyString temp = *this;
	this->_length += str._length - len;
	this->_str = new char[_length + 1];
	size_t i;
	for (i = 0; i < pos; i++) {
		this->_str[i] = temp[i];
	}
	for (size_t j = 0; j < str._length; j++) {
		this->_str[i] = str._str[j];
		i++;
	}
	for (size_t j = pos + len; j < temp._length; j++) {
		this->_str[i] = temp._str[j];
		i++;
	}
	this->_str[_length] = '\0';
	return *this;
}
MyString & MyString::replace(MyString::iterator i1, MyString::iterator i2, const MyString & str)
{
	MyString temp = *this;
	size_t len = 0;
	for (MyString::iterator i = i1; i != i2; i++) {
		len++;
	}
	this->_length += str._length - len;
	this->_str = new char[this->_length + 1];
	MyString::iterator i;
	size_t k = 0;
	for (i = temp.begin(); i != i1; i++) {
		this->_str[k] = *i;
		k++;
	}
	for (size_t j = 0; j < str._length; j++) {
		this->_str[k] = str[j];
		k++;
	}
	for (i = i2; i != temp.end(); i++) {
		this->_str[k] = *i;
		k++;
	}
	this->_str[_length] = '\0';
	return *this;
}
MyString & MyString::replace(size_t pos, size_t len, const MyString & str, size_t subpos, size_t sublen)
{
	MyString temp(str, subpos, sublen);
	this->replace(pos, len, temp);
	return *this;
}
MyString & MyString::replace(size_t pos, size_t len, const char * s)
{
	MyString temp = s;
	this->replace(pos, len, temp);
	return *this;
}
MyString & MyString::replace(MyString::iterator i1, MyString::iterator i2, const char * s)
{
	MyString temp = *this;
	size_t len = 0;
	for (MyString::iterator i = i1; i != i2; i++) {
		len++;
	}
	size_t sLen = Length(s);
	this->_length += sLen - len;
	this->_str = new char[this->_length + 1];
	MyString::iterator i;
	size_t k = 0;
	for (i = temp.begin(); i != i1; i++) {
		this->_str[k] = *i;
		k++;
	}
	for (size_t j = 0; j < sLen; j++) {
		this->_str[k] = s[j];
		k++;
	}
	for (i = i2; i != temp.end(); i++) {
		this->_str[k] = *i;
		k++;
	}
	this->_str[_length] = '\0';
	return *this;
}
MyString & MyString::replace(size_t pos, size_t len, const char * s, size_t n)
{
	MyString temp(s, n);
	this->replace(pos, len, temp);
	return*this;
}
MyString & MyString::replace(MyString::iterator i1, MyString::iterator i2, const char * s, size_t n)
{
	MyString temp(s, n);
	this->replace(i1, i2, temp);
	return*this;
}
MyString & MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	MyString temp(n, c);
	this->replace(pos, len, temp);
	return*this;
}
MyString & MyString::replace(MyString::iterator i1, MyString::iterator i2, size_t n, char c)
{
	MyString temp(n, c);
	this->replace(i1, i2, temp);
	return*this;
}
MyString & MyString::replace(MyString::iterator i1, MyString::iterator i2, MyString::iterator first, MyString::iterator last)
{
	MyString temp(first, last);
	this->replace(i1, i2, temp);
	return*this;
}

//Swap
void MyString::swap(MyString & str)
{
	MyString temp = *this;
	this->operator=(str);
	str = temp;
}

//Push_back
void MyString::push_back(char c)
{
	this->operator+=(c);
}

//Pop_back
void MyString::pop_back()
{
	this->erase(_length - 1, 1);
}

#pragma endregion

#pragma region MyString operations
//C_Str
const char * MyString::c_str() const
{
	return this->_str;
}

//Data
const char * MyString::data() const
{
	return this->_str;
}

//Copy
size_t MyString::copy(char * s, size_t len, size_t pos) const
{
	char*temp = new char[len + 1];
	size_t length = 0;
	for (size_t i = pos; i < pos + len; i++) {
		s[length] = this->_str[i];
		length++;
	}
	s = temp;
	s[length] = '\0';
	return length;
}

//Find
size_t MyString::find(const MyString & str, size_t pos) const
{
	int l1 = this->_length;
	int l2 = str._length;
	if (l1 - pos < l2)
		return -1;
	for (int i = pos; i < l1 - l2 + 1; i++)
	{
		int count = 0;
		int k = i;
		for (int j = 0; j < l2; j++)
		{
			if (this->_str[k] != str._str[j])
				break;
			else
			{
				k++;
				count++;
			}
			if (count == l2)
				return i;
		}
	}
	return -1;
}
size_t MyString::find(const char * s, size_t pos) const
{
	MyString temp = s;
	return this->find(temp, pos);
}
size_t MyString::find(const char * s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->find(temp, pos);
}
size_t MyString::find(char c, size_t pos) const
{
	for (int i = pos; i < this->_length; i++) {
		if (this->_str[i] == c) {
			return i;
		}
	}
	return -1;
}

//Rfind
size_t MyString::rfind(const MyString & str, size_t pos) const
{
	int l1 = this->_length;
	if (pos > l1 || pos == npos)
		pos = l1 - 1;
	int l2 = str._length;
	if (pos - 1 < l2)
		return -1;
	for (int i = pos; i >= l2 - 1; i--)
	{
		int count = 0;
		int k = i;
		for (int j = l2 - 1; j >= 0; j--)
		{
			if (this->_str[k] != str._str[j])
				break;
			else
			{
				k--;
				count++;
			}
			if (count == l2)
				return i - l2 + 1;
		}
	}
	return -1;
}
size_t MyString::rfind(const char * s, size_t pos) const
{
	MyString temp = s;
	return this->rfind(temp, pos);
}
size_t MyString::rfind(const char * s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->rfind(temp, pos);
}
size_t MyString::rfind(char c, size_t pos) const
{
	for (int i = pos; i > 0; i--) {

		if (this->_str[i] == c) {
			return i;
		}
	}
	return -1;
}

//Find_first_of
size_t MyString::find_first_of(const MyString & str, size_t pos) const
{
	int l1 = this->length();
	int l2 = str.length();
	for (int i = 0; i < l1; i++)
		for (int j = 0; j < l2; j++)
			if (str._str[j] == this->_str[i])
				return i;
	return -1;
}
size_t MyString::find_first_of(const char * s, size_t pos) const
{
	MyString temp = s;
	return find_first_of(temp, pos);
}
size_t MyString::find_first_of(const char * s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return find_first_of(temp, pos);
}
size_t MyString::find_first_of(char c, size_t pos) const
{
	int l = this->length();
	for (int i = pos; i < l; i++)
		if (this->_str[i] == c)
			return i;
	return -1;
}

//Find_last_of
size_t MyString::find_last_of(const MyString & str, size_t pos) const
{
	int l1 = this->length();
	if (pos == npos || pos >= l1) pos = l1 - 1;
	int l2 = str.length();
	for (int i = pos; i > -1; i--)
		for (int j = 0; j < l2; j++)
			if (str._str[j] == this->_str[i])
				return i;
	return -1;
}
size_t MyString::find_last_of(const char * s, size_t pos) const
{
	MyString temp = s;
	return find_last_of(temp, pos);
}
size_t MyString::find_last_of(const char * s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return find_last_of(temp, pos);
}
size_t MyString::find_last_of(char c, size_t pos) const
{
	if (pos == npos) pos = this->length() - 1;
	for (int i = pos; i >= 0; i--)
		if (this->_str[i] == c)
			return i;
	return -1;
}

//Find_first_not_of
size_t MyString::find_first_not_of(const MyString & str, size_t pos) const
{
	int l1 = this->length();
	int l2 = str.length();

	for (int i = 0; i < l1; i++) {
		bool ok = true;
		for (int j = 0; j < l2; j++) {
			if (this->_str[i] == str._str[j]) {
				ok = false;
				break;
			}
		}
		if (ok == true) return i;
	}
	return -1;
}
size_t MyString::find_first_not_of(const char * s, size_t pos) const
{
	MyString temp(s);
	return this->find_first_not_of(temp, pos);
}
size_t MyString::find_first_not_of(const char * s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return this->find_first_not_of(temp, pos);
}
size_t MyString::find_first_not_of(char c, size_t pos) const
{
	int l1 = this->length();
	for (int i = 0; i < l1; i++) {
		if (this->_str[i] != c)
			return i;
	}
	return -1;
}

//Find_last_not_of
size_t MyString::find_last_not_of(const MyString & str, size_t pos) const
{
	int l1 = this->length();
	int l2 = str.length();
	if (pos == npos || pos >= l1) pos = l1 - 1;
	for (int i = pos; i > 0; i--) {
		bool ok = true;
		for (int j = 0; j < l2; j++) {
			if (this->_str[i] == str._str[j]) {
				ok = false;
				break;
			}
		}
		if (ok == true) return i;
	}
	return -1;
}
size_t MyString::find_last_not_of(const char * s, size_t pos) const
{
	MyString temp(s);
	return find_last_not_of(temp, pos);
}
size_t MyString::find_last_not_of(const char * s, size_t pos, size_t n) const
{
	MyString temp(s, n);
	return find_last_not_of(temp, pos);
}
size_t MyString::find_last_not_of(char c, size_t pos) const
{
	int l1 = this->length();
	if (pos == npos || pos >= l1) pos = l1 - 1;
	for (int i = pos; i >= 0; i--) {
		if (this->_str[i] != c)
			return i;
	}
	return -1;
}

//Substr
MyString MyString::substr(size_t pos, size_t len) const
{
	if (len == npos) len = this->length() - pos;
	MyString a;
	a._length = len;
	a._str = new char[a._length + 1];
	int j = 0;
	for (int i = pos; i < pos + len; i++) {
		a._str[j] = this->_str[i];
		j++;
	}
	a._str[a._length] = '\0';
	return a;
}

//Compare
int MyString::compare(const MyString & str) const
{
	if ((*this) < str) return -1;
	else if ((*this) > str) return 1;
	else return 0;
}
int MyString::compare(size_t pos, size_t len, const MyString & str) const
{
	MyString temp;
	temp._length = len;
	temp._str = new char[temp._length + 1];
	int k = 0;
	for (int i = pos; i < pos + len; i++) {
		temp._str[k] = this->_str[i];
		k++;
	}
	temp._str[temp._length] = '\0';
	return temp.compare(str);
}
int MyString::compare(size_t pos, size_t len, const MyString & str, size_t subpos, size_t sublen) const
{
	MyString temp;
	temp._length = len;
	temp._str = new char[temp._length + 1];
	int k = 0;
	for (int i = pos; i < pos + len; i++) {
		temp._str[k] = this->_str[i];
		k++;
	}
	temp._str[temp._length] = '\0';

	MyString temp1;
	temp1._length = sublen;
	temp1._str = new char[temp1._length + 1];
	int k1 = 0;
	for (int i = subpos; i < subpos + sublen; i++) {
		temp1._str[k] = str._str[i];
		k1++;
	}
	temp1._str[temp1._length] = '\0';

	return temp.compare(temp1);
}
int MyString::compare(const char * s) const
{
	MyString temp = s;
	return this->compare(temp);
}
int MyString::compare(size_t pos, size_t len, const char * s) const
{
	MyString temp = s;
	return this->compare(pos, len, temp);
}
int MyString::compare(size_t pos, size_t len, const char * s, size_t n) const
{
	MyString temp(s, n);
	return this->compare(pos, len, temp);
}

#pragma endregion

#pragma region MyString Non - member function overloads

//Compare
bool operator == (const MyString &s1, const MyString &s2) {
	if (s1._length != s2._length) return false;
	for (size_t i = 0; i < s1._length; i++) {
		if (s1[i] != s2[i]) return false;
	}
	return true;
}
bool operator!=(const MyString & s1, const MyString & s2)
{
	return !(s1 == s2);
}
bool operator < (const MyString& s1, const MyString& s2) {
	size_t l = (s1._length < s2._length) ? s1._length : s2._length;
	for (size_t i = 0; i < l; i++) {
		if (s1[i] < s2[i]) return true;
		else if (s1[i] > s2[i]) return false;
	}
	if (s1._length < s2._length) return true;
	return false;
}
bool operator > (const MyString& s1, const MyString& s2) {
	size_t l = (s1._length < s2._length) ? s1._length : s2._length;
	for (size_t i = 0; i < l; i++) {
		if (s1[i] > s2[i]) return true;
		else if (s1[i] < s2[i]) return false;
	}
	if (s1._length > s2._length) return true;
	return false;
}
bool operator>=(const MyString & s1, const MyString & s2)
{
	return (s1 > s2 || s1 == s2);
}
bool operator<=(const MyString & s1, const MyString & s2)
{
	return (s1 < s2 || s1 == s2);
}

//Operater >> and <<
ostream& operator << (ostream& outStream, const MyString &s)
{
	outStream << s._str;
	return outStream;
}
istream& operator >> (istream& inStream, MyString &s)
{
	char* temp1 = new char[2049];
	inStream >> temp1;
	s = temp1;
	delete[]temp1;

	return inStream;
}

//Getline
void getline(istream& inStream, MyString& s) {
	char* temp = new char[2049];
	size_t i = 0;
	char x;

	while (x = getc(stdin)) {
		if (x != '\n')
		{
			temp[i] = x;
			i++;
		}
		else break;
	}
	temp[i] = '\0';
	s = temp;
	delete[]temp;

}

//Operator +
MyString operator+(const MyString & s1, const MyString & s2)
{
	MyString result;
	char*s = new char[s1.length() + s2.length() + 1];
	size_t i = 0;
	for (; i < s1.length(); i++) {
		s[i] = s1[i];
	}
	size_t j = 0;
	for (; j < s2.length(); j++) {
		s[i + j] = s2[j];
	}
	s[i + j] = '\0';
	result = s;

	return result;
}
MyString operator+(const MyString & lhs, const char * rhs)
{
	MyString temp = rhs;
	return lhs + temp;
}
MyString operator+(const char * lhs, const MyString & rhs)
{
	MyString temp = lhs;
	return temp + rhs;
}
MyString operator+(const MyString & lhs, char rhs)
{
	MyString temp(1, rhs);
	return lhs + temp;
}
MyString operator+(char lhs, const MyString & rhs)
{
	MyString temp(1, lhs);
	return temp + rhs;
}

#pragma endregion


#pragma region MyString::iterator
MyString::iterator::iterator() {	}
MyString::iterator::iterator(char* s) {
	this->ite = s;
}
MyString::iterator::iterator(const iterator & i)
{
	this->ite = i.ite;
}
char MyString::iterator::operator*() {
	return *ite;
}
MyString::iterator& MyString::iterator::operator=(char* s) {
	this->ite = s;
	return *this;
}
MyString::iterator& MyString::iterator::operator++()
{
	this->ite++;
	return *this;
}
MyString::iterator& MyString::iterator::operator++(int)
{
	++(*this);
	return *this;
}
MyString::iterator& MyString::iterator::operator--()
{
	ite--;
	return *this;
}
MyString::iterator& MyString::iterator::operator--(int)
{
	--(*this);
	return *this;
}
MyString::iterator& MyString::iterator::operator+(size_t index)
{
	this->ite += index;
	return *this;
}
MyString::iterator& MyString::iterator::operator+=(size_t index)
{
	this->operator+(index);
	return *this;
}
MyString::iterator& MyString::iterator::operator-(size_t index)
{
	this->ite -= index;
	return *this;
}
MyString::iterator& MyString::iterator::operator-=(size_t index)
{
	this->operator-(index);
	return *this;
}
bool MyString::iterator::operator==(const MyString::iterator& i) {
	MyString temp1 = this->ite;
	MyString temp2 = i.ite;
	return !(temp1 == temp2);
}
bool MyString::iterator::operator!=(const MyString::iterator& i) {
	MyString temp1 = this->ite;
	MyString temp2 = i.ite;
	return !(temp1 == temp2);
}
#pragma endregion

#pragma region MyString::reverse_iterator
MyString::reverse_iterator::reverse_iterator() {	}
MyString::reverse_iterator::reverse_iterator(char* s) {
	this->rite = s;
}
MyString::reverse_iterator::reverse_iterator(const reverse_iterator & i)
{
	this->rite = i.rite;
}
char MyString::reverse_iterator::operator*() {
	return *rite;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator=(char* s) {
	this->rite = s;
	return *this;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator++()
{
	this->rite--;
	return *this;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator++(int)
{
	++(*this);
	return *this;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator--()
{
	this->rite++;
	return *this;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator--(int)
{
	--(*this);
	return *this;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator+(size_t index)
{
	this->rite -= index;
	return *this;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator+=(size_t index)
{
	this->operator+(index);
	return *this;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator-(size_t index)
{
	this->rite += index;
	return *this;
}
MyString::reverse_iterator& MyString::reverse_iterator::operator-=(size_t index)
{
	this->operator-(index);
	return *this;
}
bool MyString::reverse_iterator::operator==(const MyString::reverse_iterator& i) {
	MyString temp1 = this->rite;
	MyString temp2 = i.rite;
	return (temp1 == temp2);
}
bool MyString::reverse_iterator::operator!=(const MyString::reverse_iterator& i) {
	MyString temp1 = this->rite;
	MyString temp2 = i.rite;
	return !(temp1 == temp2);
}
#pragma endregion




//Sub function: Replace for strlen(const char* str)
size_t Length(const char* _str) {
	size_t length = 0;
	for (size_t i = 0; _str[i] != '\0'; i++) {
		length++;
	}
	return length;
}