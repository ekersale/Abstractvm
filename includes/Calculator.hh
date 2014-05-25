//
// Calculator.hh for abstract_vm in /home/kersal_e/projet_actuels/cpp_abstractvm
// 
// Made by Elliot Kersale
// Login   <kersal_e@epitech.net>
// 
// Started on  Thu Feb 20 10:54:12 2014 Elliot Kersale
// Last update Sat Mar  1 18:31:17 2014 Elliot Kersale
//

#ifndef		_CALCULATOR_HH__
# define	_CALCULATOR_HH__
/*
** INCLUDES
*/
#include	<sstream>
#include	<string>
#include	<fstream>
#include	<stack>
#include 	<iostream>
#include	"Operand.hpp"
/*
** CALCULATOR CLASS
*/
class		Calculator
{
public:
  Calculator();
  Calculator(Calculator const &);
  ~Calculator();

  void		push(IOperand *);
  int		pop();
  void		dump();
  int		assert(IOperand *);
  int		add();
  int		sub();
  int		mul();
  int		div();
  int		mod();
  int		print();
  bool		isNull(const std::string &);
  int		check_value(const std::string &, const std::string &);
private:
  std::stack<IOperand *>	pile;
};
/*
**
*/
#endif
//EOF _CALCULATOR_HH__
