// 16,1.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <string>
#include <algorithm>
int main()
{	
	/*
	std::vector<int> vect;
	for (int count = 0; count < 6; ++count)
		vect.push_back(10 - count);

	for (int index = 0; index < vect.size(); ++index)
		std::cout << vect[index] << ' ';

	std::cout << '\n';

	std::deque<int> deq;
	for (int count = 0; count < 3; ++count)
	{
		deq.push_back(count); // insert at end of array
		deq.push_front(10 - count); // insert at front of array
	}

	for (int index = 0; index < deq.size(); ++index)
		std::cout << deq[index] << ' ';

	std::cout << '\n';

	std::vector<int> vect;
	for (int count = 0; count < 6; ++count)
		vect.push_back(count);

	std::vector<int>::const_iterator it;
	it = vect.begin();
	
	while (it != vect.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << '\n';
	

	std::list<int> li;
	for (int count = 0; count < 6; ++count)
		li.push_back(count);

	std::list<int>::const_iterator it;
	it = li.begin();
	while (it != li.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << '\n';
	

	std::set<int> myset;
	myset.insert(7);
	myset.insert(2);
	myset.insert(-6);
	myset.insert(8);
	myset.insert(1);
	myset.insert(-4);

	std::set<int>::const_iterator it;
	it = myset.begin();
	while (it != myset.end())
	{
		std::cout << *it << " ";
		++it;
	}
	

	std::map<int, std::string> mymap;
	mymap.insert(std::make_pair(4, "apple"));
	mymap.insert(std::make_pair(2, "orange"));
	mymap.insert(std::make_pair(1, "banana"));
	mymap.insert(std::make_pair(3, "grapes"));
	mymap.insert(std::make_pair(6, "mango"));
	mymap.insert(std::make_pair(5, "peach"));

	std::map<int, std::string>::const_iterator it;
	it = mymap.begin();
	while (it != mymap.end())
	{
		std::cout << it->first << "=" << it->second << " ";
		++it;
	}
	std::cout << "\n";
	*/

	std::list<int> li;
	for (int nCount = 0; nCount < 6; nCount++)
		li.push_back(nCount);

	std::list<int>::const_iterator it;
	it = min_element(li.begin(), li.end());
		std::cout << *it << ' ';
	it = max_element(li.begin(), li.end());
		std::cout << *it << ' ';
	
    return 0;
}

