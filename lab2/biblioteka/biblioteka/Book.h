#pragma once
#include <string>

using namespace std;

class Book
{
	string author, title;
public:
	Book();
	Book(const string& author, const string& title);
	Book(string&& author, string&& title);
	Book(const Book& other);
	Book(Book&& other);
	string GetAuthor() const;
	string GetTitle() const;
	void SetAuthor(const string& author);
	void SetTitle(const string& title);
	void SetAuthor(string&& author);
	void SetTitle(string&& title);
	Book& operator=(const Book& right);
	Book& operator=(Book&& right);
	~Book();
};