#pragma once
#include <iostream>
#include <stdio.h>
#include "Book.h"

using namespace std;

Book::Book()
{
	cout << "Konstruktor bezparametrowy\n";
	SetAuthor("Franz Kafka");
	SetTitle("Przemiana");
}
Book::Book(const string& author, const string& title)
{
	SetAuthor(author);
	SetTitle(title);
	cout << "Konstruktor z l-referencjami: " << GetAuthor() << ", " << GetTitle() << "\n";
}
Book::Book(string&& author, string&& title)
{
	SetAuthor(author);
	SetTitle(title);
	cout << "Konstruktor z r-referencjami: " << GetAuthor() << ", " << GetTitle() << "\n";
}
Book::Book(const Book& other)// konstruktor kopiuj¹cy -> l-referencja
{
	SetAuthor(other.GetAuthor());
	SetTitle(other.GetTitle());
}
Book::Book(Book&& other)// konstruktor kopiuj¹cy -> r-referencja
{
	author = other.author;
	title = other.title;
	other.author = "Deleted";
	other.title = "deleted";
}
void Book::SetAuthor(const string& author)//setter dla autora-> l-referencja
{
	this->author = author;
}
void Book::SetTitle(const string& title)//setter dla tytu³u-> l-referencja
{
	this->title = title;
}
void Book::SetAuthor(string&& author)//setter dla autora-> r-referencja
{
	this->author = author;
}
void Book::SetTitle(string&& title)//setter dla tytu³u-> r-referencja
{
	this->title = title;
}
string Book::GetTitle() const
{
	return title;
}
string Book::GetAuthor() const
{
	return author;
}
Book& Book::operator=(const Book& right)
{
	Book tmp = right;
	swap(title, tmp.title);
	swap(author, tmp.author);
	return *this;
}
Book& Book::operator=(Book&& right)
{
	author = move(right.author);
	title = move(right.title);
	return *this;
}
Book::~Book()
{
	//cout << "Destruktor ksiazki " << GetTitle() << " autora " << GetAuthor() << "\n";
}