/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thamon <thamon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:31:55 by thamon            #+#    #+#             */
/*   Updated: 2022/12/28 18:12:57 by thamon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <map>
#include <iostream>
#include "incl/map.hpp"
// namespace ft = std;


bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main(void)
{
	std::cout << "======================= TEST TOUS LES CONSTRUCTORS =======================\n" << std::endl;
	
	ft::map<char,int> first;
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	std::cout << "Default constructor : OK " << std::endl; 
	ft::map<char,int> second (first.begin(),first.end());
	std::cout << "Range constructor : OK " << std::endl; 

	std::cout << "Copy constructor : OK " << std::endl; 
	ft::map<char,int> third (second);

	third = second;
	std::cout << "Overload operator = : OK" << std::endl;
	ft::map<std::string, std::string> test;
	ft::map<std::string, std::string>::iterator test_it;
	ft::map<std::string, std::string>::reverse_iterator rev_test_it;

	test.insert(ft::pair<std::string, std::string>("Helo", "Test"));
	test.insert(ft::pair<std::string, std::string>("End", "of map"));

	
	std::cout << "\n======================= ITERATORS =======================\n" << std::endl;
	std::cout << "============ BEGIN ITERATOR ============" << std::endl;
	test_it = test.begin();
	std::cout << "first elements is : {" << test_it->first << "} second element is : {" << test_it->second << "} " << std::endl;

	std::cout << "============ END ITERATOR ============" << std::endl;
	test_it = test.end();
	--test_it;
	std::cout << "first elements is : {" << test_it->first << "} second element is : {" << test_it->second << "} " << std::endl;
   
	std::cout << "============ RBEGIN ITERATOR ============" << std::endl;
	rev_test_it = test.rbegin();
	std::cout << "first elements is : {" << test_it->first << "} second element is : {" << test_it->second << "} " << std::endl;
	
	std::cout << "============ REND ITERATOR ============" << std::endl;
	rev_test_it = test.rend();
	--test_it;
	std::cout << "first elements is : {" << test_it->first << "} second element is : {" << test_it->second << "} " << std::endl;

	std::cout << "\n======================= CAPACITY =======================\n" << std::endl;

	ft::map<int, std::string>               int_string;
	ft::map<std::string, std::string>       string_string;
	ft::map<char, char>                     char_char;
	ft::map<char, bool>                     char_bool;

	std::cout << "======= AVANT INSERTION =======" << std::endl << std::endl;
	
	std::cout << "===== Vide ou non =====" << std::endl << std::endl;
	std::cout << "int_string is empty? " << (int_string.empty() ? "yes" : "no" ) << std::endl; 
	std::cout << "string_string is empty? " << (string_string.empty() ? "yes" : "no" ) << std::endl; 
	std::cout << "char_char is empty? " << (char_char.empty() ? "yes" : "no" ) << std::endl; 
	std::cout << "char_bool is empty? " << (char_bool.empty() ? "yes" : "no" ) << std::endl << std::endl; 

	std::cout << "===== Taille du container =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl; 
	std::cout << "string_string size: " << string_string.size() << std::endl; 
	std::cout << "char_char size: " << char_char.size() << std::endl; 
	std::cout << "char_bool size: " << char_bool.size() << std::endl << std::endl; 


	int_string.insert(ft::pair<int, std::string>(42, "Test du pair"));
	string_string.insert(ft::pair<std::string, std::string>("wwewewewewe", "Test du pair"));
	char_char.insert(ft::pair<char, char>('o', 'w'));
	char_bool.insert(ft::pair<char, bool>('o',false));
	
	std::cout << "======= APRES INSERTION =======" << std::endl << std::endl;
	
	std::cout << "===== Vide ou non =====" << std::endl << std::endl;
	std::cout << "int_string is empty? " << (int_string.empty() ? "yes" : "no" ) << std::endl; 
	std::cout << "string_string is empty? " << (string_string.empty() ? "yes" : "no" ) << std::endl; 
	std::cout << "char_char is empty? " << (char_char.empty() ? "yes" : "no" ) << std::endl; 
	std::cout << "char_bool is empty? " << (char_bool.empty() ? "yes" : "no" ) << std::endl << std::endl; 

	std::cout << "===== Taille du container =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl; 
	std::cout << "string_string size: " << string_string.size() << std::endl; 
	std::cout << "char_char size: " << char_char.size() << std::endl; 
	std::cout << "char_bool size: " << char_bool.size() << std::endl << std::endl; 


	std::cout << "============================ ELEMENT ACCESS =======================" << std::endl << std::endl;

	std::cout << "===== Premier index du container =====" << std::endl << std::endl;
	std::cout << "int_string " << int_string[42] << std::endl; 
	std::cout << "string_string " << string_string["wwewewewewe"] << std::endl; 
	std::cout << "char_char " << char_char['o'] << std::endl; 
	std::cout << "char_bool " << char_bool['o'] << std::endl << std::endl; 

	std::cout << "============================ MODIFIERS =======================" << std::endl << std::endl;

	std::cout << "===== test d'inserer plusieur valeurs =====" << std::endl << std::endl;
	
	int_string.insert(ft::pair<int, std::string>(43, "a"));
	int_string.insert(ft::pair<int, std::string>(44, "b"));
	int_string.insert(ft::pair<int, std::string>(45, "c"));
	int_string.insert(ft::pair<int, std::string>(46, "d"));
	int_string.insert(ft::pair<int, std::string>(47, "e"));
	int_string.insert(ft::pair<int, std::string>(48, "f"));
	int_string.insert(ft::pair<int, std::string>(49, "g"));
	
	string_string.insert(ft::pair<std::string, std::string>("vdgdgsdgsd", "vsdgvdbfgngf"));
	string_string.insert(ft::pair<std::string, std::string>("gfdgdfg", "asogfdgduh"));
	string_string.insert(ft::pair<std::string, std::string>("fff", "hgfh"));
	string_string.insert(ft::pair<std::string, std::string>("kyuhmyt", "kyukhgmgh"));
	
	char_char.insert(ft::pair<char, char>('w', 'w'));
	char_bool.insert(ft::pair<char, bool>('e',false));
	char_char.insert(ft::pair<char, char>('z', 'y'));
	char_bool.insert(ft::pair<char, bool>('f',true));
	char_char.insert(ft::pair<char, char>('x', 'w'));
	char_bool.insert(ft::pair<char, bool>('o',false));
	char_char.insert(ft::pair<char, char>('p', 'g'));
	char_bool.insert(ft::pair<char, bool>('z',true));

	std::cout << "===== differente sizes apres insertion =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl; 
	std::cout << "string_string size: " << string_string.size() << std::endl; 
	std::cout << "char_char size: " << char_char.size() << std::endl; 
	std::cout << "char_bool size: " << char_bool.size() << std::endl << std::endl; 

	std::cout << "===== Test erease =====" << std::endl << std::endl;
	
	int_string.erase(int_string.begin());
	string_string.erase(string_string.begin());
	char_char.erase(char_char.begin());
	char_bool.erase(char_bool.begin());

	
	std::cout << "===== differente sizes apres erase =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl; 
	std::cout << "string_string size: " << string_string.size() << std::endl; 
	std::cout << "char_char size: " << char_char.size() << std::endl; 
	std::cout << "char_bool size: " << char_bool.size() << std::endl << std::endl; 

	std::cout << "===== Test clear tous les container =====" << std::endl << std::endl;

	int_string.clear();
	string_string.clear();
	char_char.clear();
	char_bool.clear();

	std::cout << "===== differente sizes apres clear =====" << std::endl << std::endl;
	std::cout << "int_string size: " << int_string.size() << std::endl; 
	std::cout << "string_string size: " << string_string.size() << std::endl; 
	std::cout << "char_char size: " << char_char.size() << std::endl; 
	std::cout << "char_bool size: " << char_bool.size() << std::endl << std::endl; 

	ft::map<std::string, std::string>   map_a;
	ft::map<std::string, std::string>::iterator   map_a_it;
	ft::map<std::string, std::string>   map_b;
	ft::map<std::string, std::string>::iterator   map_b_it;
	
	
	std::cout << "============================ SWAP =======================" << std::endl << std::endl;
   
	std::cout << "===== Avant le swap =====" << std::endl << std::endl;
	
	ft::map<char,int> foo,bar;
	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	foo.swap(bar);
	
	std::cout << "===== Apres le swap =====" << std::endl << std::endl;
	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
		
	std::cout << "\n============================ KEY_COMP =======================" << std::endl << std::endl;

	ft::map<char,int> mymap;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;	 // key value of last element

		ft::map<char,int>::iterator it = mymap.begin();
		do
			std::cout << it->first << " => " << it->second << std::endl;
		while ( mycomp((*it++).first, highest) );

		std::cout << std::endl;

	std::cout << "============================ VALUE_COMP =======================" << std::endl << std::endl;

	ft::map<char,int> test_map;

	test_map['x']=1001;
	test_map['y']=2002;
	test_map['z']=3003;

	std::cout << "test_map contains:\n";

	ft::pair<char,int> highest_pair = *test_map.rbegin();          // last element

	ft::map<char,int>::iterator it_val = test_map.begin();
	do {
		std::cout << it_val->first << " => " << it_val->second << '\n';
	} while ( test_map.value_comp()(*it_val++, highest_pair) );

	std::cout << "\n============================ FIND =======================" << std::endl << std::endl;

	ft::map<int, int>	ope_map;
	ft::map<int, int>::iterator	ope_map_ite;

	ope_map.insert(ft::pair<int, int>(42, 11238));
	ope_map.insert(ft::pair<int, int>(25, 88907));
	ope_map.insert(ft::pair<int, int>(125, 18));
	ope_map.insert(ft::pair<int, int>(16857, 132));
	ope_map.insert(ft::pair<int, int>(568, 18));
	ope_map.insert(ft::pair<int, int>(67568, 658));
	ope_map.insert(ft::pair<int, int>(5687, 5678));
	ope_map.insert(ft::pair<int, int>(64, 54754));
	ope_map.insert(ft::pair<int, int>(5623123, 56782));
	ope_map.insert(ft::pair<int, int>(213, 56754));
	ope_map.insert(ft::pair<int, int>(568, 5687));

	std::cout << "===== Cherche l'element 42 =====" << std::endl << std::endl;
	ope_map_ite = ope_map.find(42);
	if (ope_map_ite == ope_map.end())
		std::cout << "impossible de find la value" << std::endl;
	else
		std::cout << "{" << ope_map_ite->first << "} {"<< ope_map_ite->second << "} "<< std::endl;
	ope_map_ite = ope_map.find(41232);
	if (ope_map_ite == ope_map.end())
		std::cout << "impossible de find la value" << std::endl;
	else
		std::cout << "{" << ope_map_ite->first << "} {"<< ope_map_ite->second << "} "<< std::endl;
	
	std::cout << "\n============================ COUNT =======================" << std::endl << std::endl;
	std::cout << "===== Nombre d'element 42  =====" << std::endl << std::endl;
	std::cout << "Il a ete trouve " << ope_map.count(42) << " fois dans la map" << std::endl;
	
	std::cout << "===== Nombre d'element 84 =====" << std::endl << std::endl;
	std::cout << "Il a ete trouve " << ope_map.count(84) << " fois dans la map" << std::endl;
	
	std::cout << "===== Nombre d'element 123897 =====" << std::endl << std::endl;
	std::cout << "Il a ete trouve " << ope_map.count(123897) << " fois dans la map" << std::endl;

	std::cout << "\n============================ LOWER_BOUND =======================" << std::endl << std::endl;

	std::cout << "===== Lower_bound for 184 =====" << std::endl << std::endl;
	ope_map_ite = ope_map.lower_bound(184);	
	if (ope_map_ite == ope_map.end())
		std::cout << "impossible de find la value" << std::endl;
	else
		std::cout << "{" << ope_map_ite->first << "} {"<< ope_map_ite->second << "} "<< std::endl;

	std::cout << "===== Lower_bound for 1 =====" << std::endl << std::endl;
	ope_map_ite = ope_map.lower_bound(1);	
	if (ope_map_ite == ope_map.end())
		std::cout << "impossible de find la value" << std::endl;
	else
		std::cout << "{" << ope_map_ite->first << "} {"<< ope_map_ite->second << "} "<< std::endl;


	std::cout << "===== Lower_bound for -1 =====" << std::endl << std::endl;
	ope_map_ite = ope_map.lower_bound(-1);	
	if (ope_map_ite == ope_map.end())
		std::cout << "impossible de find la value" << std::endl;
	else
		std::cout << "{" << ope_map_ite->first << "} {"<< ope_map_ite->second << "} "<< std::endl;

	std::cout << "\n============================ UPPER_BOUND =======================" << std::endl << std::endl;

	std::cout << "===== upper_bound for 184 =====" << std::endl << std::endl;
	ope_map_ite = ope_map.upper_bound(184);	
	if (ope_map_ite == ope_map.end())
		std::cout << "impossible de find la value" << std::endl;
	else
		std::cout << "{" << ope_map_ite->first << "} {"<< ope_map_ite->second << "} "<< std::endl;

	std::cout << "===== upper_bound for -1 =====" << std::endl << std::endl;
	ope_map_ite = ope_map.upper_bound(-1);	
	if (ope_map_ite == ope_map.end())
		std::cout << "impossible de find la value" << std::endl;
	else
		std::cout << "{" << ope_map_ite->first << "} {"<< ope_map_ite->second << "} "<< std::endl;


	std::cout << "===== upper_bound for 123 =====" << std::endl << std::endl;
	ope_map_ite = ope_map.upper_bound(123);	
	if (ope_map_ite == ope_map.end())
		std::cout << "impossible de find la value" << std::endl;
	else
		std::cout << "{" << ope_map_ite->first << "} {"<< ope_map_ite->second << "} "<< std::endl;

	std::cout << "\n============================ EQUAL_RANGE =======================" << std::endl << std::endl;
 	ft::map<char,int> equal_range_map;

	equal_range_map['a']=10;
	equal_range_map['b']=20;
	equal_range_map['c']=30;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = equal_range_map.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}
