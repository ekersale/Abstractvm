//
// parsing.cpp for abstract_vm in /home/kersal_e/projet_actuels/cpp_abstractvm
// 
// Made by Elliot Kersale
// Login   <kersal_e@epitech.net>
// 
// Started on  Thu Feb 20 14:29:33 2014 Elliot Kersale
// Last update Sat Mar  1 18:33:32 2014 Elliot Kersale
//

#include		<stdlib.h>
#include		<unistd.h>
#include		"Calculator.hh"
#include		"Parse.hh"

Parse::Parse()
{
  
}

Parse::Parse(Parse const &cpy)
{

}

Parse::~Parse()
{

}

void		Parse::set_line(std::string &line)
{
  _line = line;
  if (_line.find(";", 0) == _line.npos && !_line.empty())
    _vect.push_back(line);
}

int		Parse::clean_line()
{
  if (_line.find("push", 0) != _line.npos || _line.find("assert", 0) != _line.npos)
    {
      std::string tmp;
      std::istringstream iss(_line);
      int x = 0;
      while (getline(iss, tmp, ' '))
	{
	  if (x == 1)
	    {
	      if (tmp.find("int8", 0) != _line.npos || tmp.find("int16", 0) != _line.npos ||
		  tmp.find("int32", 0) != _line.npos || tmp.find("float", 0) != _line.npos ||
		  tmp.find("double", 0) != _line.npos)
		{
		  const char *str = tmp.c_str();
		  int i = 0;
		  while (str[i])
		    {
		      if (str[i] == '(')
			{
			  i++;
			  while (str[i] != ')' && str[i])
			    {
			      if (str[i] >= '0' && str[i] <= '9' || str[i] == '.')
				i++;
			      else
				return (EXIT_FAILURE);
			    }
			}
		      if (str[i] == ')')
			{
			  if (!str[i + 1])
			    break;
			  else
			    return (EXIT_FAILURE);
			}
		      i++;
		    }
		}
	    }
	  x++;
	}
      if (x != 2)
        return (EXIT_FAILURE);
      return (0);
    }
  if (_line.find("pop", 0) == _line.npos && _line.find("dump", 0) == _line.npos &&
      _line.find("add", 0) == _line.npos && _line.find("sub", 0) == _line.npos &&
      _line.find("mul", 0) == _line.npos && _line.find("div", 0) == _line.npos &&
      _line.find("mod", 0) == _line.npos && _line.find("print", 0) == _line.npos &&
      _line.find("exit", 0) == _line.npos && _line.find(";", 0) == _line.npos && _line.npos && !_line.empty())
    {
      return (EXIT_FAILURE);
    }
  return (0);
}

int		Parse::send()
{
  Calculator calc;
  std::string	tmp;

  while (!_vect.empty())
    {
      tmp = _vect.front();
      _vect.erase(_vect.begin(), _vect.begin() + 1);
      if (choose_calc(tmp, &calc) == 1)
        return (EXIT_FAILURE);
    }
}

int    Parse::choose_calc(std::string const &tmp, Calculator *calc)
{
  int   res = 0;

  if (tmp.find("push", 0) != tmp.npos)
    (*calc).push(choose_ope(tmp));
  else if (tmp.find("add", 0) != tmp.npos)
    res = (*calc).add();
  else if (tmp.find("mul", 0) != tmp.npos)
    res = (*calc).mul();
  else if (tmp.find("sub", 0) != tmp.npos)
    res = (*calc).sub();
  else if (tmp.find("div", 0) != tmp.npos)
    res = (*calc).div();
  else if (tmp.find("mod", 0) != tmp.npos)
    res = (*calc).mod();
  else if (tmp.find("dump", 0) != tmp.npos)
    (*calc).dump();
  else if (tmp.find("assert", 0) != tmp.npos)
    res = (*calc).assert(choose_ope(tmp));
  else if (tmp.find("pop", 0) != tmp.npos)
    res = (*calc).pop();
  else if (tmp.find("print", 0) != tmp.npos)
    res = (*calc).print();
  if (res == 1)
      return (EXIT_FAILURE);
  return (0);
}

IOperand		*Parse::choose_ope(const std::string & tmp)
{
  IOperand *ope;

  if (tmp.find("int8", 4) != tmp.npos)
    ope = createInt8(getvalue(tmp));
  if (tmp.find("int16", 4) != tmp.npos)
    ope = createInt16(getvalue(tmp));
  if (tmp.find("int32", 4) != tmp.npos)
    ope = createInt32(getvalue(tmp));
  if (tmp.find("float", 4) != tmp.npos)
    ope = createFloat(getvalue(tmp));
  if (tmp.find("double", 4) != tmp.npos)
      ope = createDouble(getvalue(tmp));
  return (ope);
}

std::string	Parse::getvalue(const std::string & tmp)
{
  std::string	value;
  const char *cstr = tmp.c_str();
  int i;

  i = 0;
  while (cstr[i] != '(' && cstr[i] != '\n')
    i++;
  i++;
  while (cstr[i] != ')' && cstr[i] != '\n')
    {
      value += cstr[i];
      i++;
    }
  return (value);
}

IOperand *Parse::createInt8(const std::string & value)
{
  return (new Operand<int8_t>(value, INT8));
}

IOperand *Parse::createInt16(const std::string & value)
{
  return (new Operand<int16_t>(value, INT16));
}

IOperand *Parse::createInt32(const std::string & value)
{
  return (new Operand<int32_t>(value, INT32));
}

IOperand *Parse::createFloat(const std::string & value)
{
  return (new Operand<float>(value, FLOAT));
}

IOperand *Parse::createDouble(const std::string & value)
{
  return (new Operand<double>(value, DOUBLE));
}
