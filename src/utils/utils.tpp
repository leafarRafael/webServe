/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:06:22 by myokogaw          #+#    #+#             */
/*   Updated: 2024/12/10 20:06:22 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iterator>
#include <sstream>
#include <list>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <iomanip>

template<typename StringType, typename CharType, typename ContainerType>
ContainerType split(const StringType& s, CharType delimiter) {
    ContainerType	listToken;
    std::string		token;
    std::istringstream iss(s);

    if (s.find(delimiter) == std::string::npos){
        listToken.push_back(s);
        return listToken;
    }
    while (std::getline(iss, token, delimiter)) {
        if (!token.empty()) {
            listToken.push_back(token);
        }
    }
    return listToken;
}

template<typename T>
void putMap(T _request){
	typename T::iterator it;

	for(it = _request.begin(); it != _request.end(); it++){
		std::cout << it->first << " " << it->second << "\n";
	}
}

template<typename StringType, typename ContainerType>
ContainerType getLineErase(StringType &orin, StringType delimiter, bool erase){
    std::size_t     find;
    ContainerType   line;

    if (delimiter.empty() || orin.empty()){
        return "";
    }
    find = orin.find(delimiter);
    if (find == std::string::npos){
        return "";
    }
    line = orin.substr(0, find);
    if (erase == true)
	    orin.erase(0, find + delimiter.length());
	return line;
}

template<typename T>
void putMapList(T _request){
	typename T::iterator it;
    std::list<std::string>::iterator l_IT;

	for(it = _request.begin(); it != _request.end(); it++){
		std::cout << it->first << " ";
        l_IT = it->second.begin();
        for (; l_IT != it->second.end(); l_IT++){
            std::cout << *l_IT << " ";   
        }
        std::cout << "\n";
	}
}

template<typename String>
void trim(String &str){
    
    while(str.size() > 0 && std::isspace(static_cast<unsigned char>(str[0]))){
    	str.erase(0, 1);
    }
	while(str.size() > 0 && std::isspace(static_cast<unsigned char>(str[str.size() -1]))){
		str.erase(str.size() - 1, 1);
    }
}

template<typename T>
std::string getCurrentDateTime(T l) {
    l = std::time(0);
    std::tm* localTime = std::localtime(&l);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H:%M:%S GMT", localTime);
    return std::string(buffer);
}

template<typename T>
bool isNumeric(T content){
    typename T::iterator it, ite;

    it = content.begin();
    ite = content.end();
    while(it != ite){
        if (not std::isdigit(*it)){
            return false;
        }
        it++;
    }
    return true;
}

template<typename T, typename X>
void    removeToString(T &origin, X toRemove){
    trim(origin);
    std::string orin = origin, remove = toRemove;
    if (orin.empty() || remove.empty())
        return ;
    if (orin.find(remove) == std::string::npos)
        return ;
    orin.erase(orin.find(remove), remove.length());
    trim(orin);
    origin = orin;
}

template<typename T, typename X>
void	normalize(T &origin, X toRemove){
	trim(origin);
	removeToString(origin, ";");
	removeToString(origin, toRemove);
    std::string orig = origin;
	std::string::iterator it = orig.begin(), ite = orig.end();
	trim(orig);
	while (it != ite){
		if (*it == '\t')
			*it = ' ';
		it++;
	}
	trim(orig);
    origin = orig;
}

template<typename T, typename X, typename C>
void	normalize(T &origin, X toRemove, C c){
	trim(origin);
	removeToString(origin, c);
	removeToString(origin, toRemove);
    std::string orig = origin;
	std::string::iterator it = orig.begin(), ite = orig.end();
	trim(orig);
	while (it != ite){
		if (*it == '\t')
			*it = ' ';
		it++;
	}
	trim(orig);
    origin = orig;
}


template<typename T>
int	toInt(T svalue){
	std::ostringstream	oss;
	int					valueInt;

	oss << svalue;
	std::istringstream	iss(oss.str());
	iss >> valueInt;
	return valueInt;
}


template<typename T>
std::size_t	toulong(T svalue){
	std::ostringstream	oss;
	size_t				valueInt;

	oss << svalue;
	std::istringstream	iss(oss.str());
	iss >> valueInt;
	return valueInt;
}