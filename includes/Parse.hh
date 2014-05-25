//
// Parse.hh for Parse in /home/porres_m/PROJETS/abstract_VM/cpp_abstractvm/includes
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Fri Feb 21 17:56:28 2014 Martin Porrès
// Last update Sat Mar  1 18:32:42 2014 Elliot Kersale
//

#ifndef			_PARSE_HH__
# define		_PARSE_HH__
/*
** INCLUDES
*/
#include		<sstream>
#include		<iostream>
#include		<fstream>
#include		<string>
#include		<vector>
#include		"Calculator.hh"
#include		"Operand.hpp"
/*
** PARSING CLASS
*/
class Parse
{
public:
  Parse();
  Parse(Parse const &cpy);
  ~Parse();

  void		set_line(std::string &);
  std::string	get_line();
  int		clean_line();
  int		send();
  int		choose_calc(std::string const &, Calculator *);
  IOperand	*choose_ope(const std::string &);
  std::string	getvalue(const std::string &);

private:
  std::string			_line;
  std::vector<std::string>	_vect;
  IOperand * createInt8(const std::string & value);
  IOperand * createInt16(const std::string & value);
  IOperand * createInt32(const std::string & value);
  IOperand * createFloat(const std::string & value);
  IOperand * createDouble(const std::string & value);
};
/*
**
*/
#endif
//EOF _PARSE_HH__
