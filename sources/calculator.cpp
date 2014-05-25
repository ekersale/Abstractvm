//
// calculator.cpp for abstract_vm in /home/kersal_e/projet_actuels/cpp_abstractvm
// 
// Made by Elliot Kersale
// Login   <kersal_e@epitech.net>
// 
// Started on  Thu Feb 20 14:56:34 2014 Elliot Kersale
// Last update Sat Mar  1 18:31:39 2014 Elliot Kersale
//

#include		<cstdlib>
#include		"Calculator.hh"

Calculator::Calculator()
{

}

Calculator::Calculator(Calculator const &cpy)
{

}

Calculator::~Calculator()
{

}

void	Calculator::push(IOperand *value)
{
  pile.push(value);
}

int	Calculator::pop()
{
  if (pile.empty())
    {
      std::cerr << "Pile is empty" << std::endl;
      return (EXIT_FAILURE);
    }
  pile.pop();
  return (0);
}

void	Calculator::dump()
{
  IOperand *ope;
  std::stack<IOperand *> stack_tmp;

  stack_tmp = pile;
  while (!pile.empty())
    {
      ope = pile.top();
      pile.pop();
      std::cout << ope->getValue() << std::endl;
    }
  pile = stack_tmp;
}

int	Calculator::check_value(const std::string &v1, const std::string &v2)
{
  std::stringstream conv1;
  std::stringstream conv2;
  double value1;
  double value2;

  conv1 << v1;
  conv2 << v2;
  conv1 >> value1;
  conv2 >> value2;
  if (value1 == value2)
    return (1);
  else
    return (0);
}

int	Calculator::assert(IOperand *value)
{
  IOperand *tmp;
  
  tmp = pile.top();
  if (check_value(tmp->getValue(), value->getValue()) == 1 && value->getType() == tmp->getType())
    {
      delete value;
      return (0);
    }
  else
    {
      std::cerr << "Value on top are differents" << std::endl;
      delete value;
      return (EXIT_FAILURE);
    }
}

int	Calculator::add()
{
  IOperand	*v1;
  IOperand	*v2;

  if (pile.size() < 2)
    {
      std::cerr << "Pile count less of 2 elements" << std::endl;
      return (EXIT_FAILURE);
    }
  v1 = pile.top();
  pile.pop();
  v2 = pile.top();
  pile.pop();
  this->pile.push(*v1 + *v2);
  delete v1;
  delete v2;
  return (0);
}

int	Calculator::sub()
{
  IOperand	*v1;
  IOperand	*v2;
  
  if (pile.size() < 2)
    {
      std::cerr << "Pile count less of 2 elements" << std::endl;
      return (EXIT_FAILURE);
    }
  v1 = pile.top();
  pile.pop();
  v2 = pile.top();
  pile.pop();
  this->pile.push(*v1 - *v2);
  delete v1;
  delete v2;
  return (0);
}

int	Calculator::mul()
{
  IOperand	*v1;
  IOperand	*v2;
  
  if (pile.size() < 2)
    {
      std::cerr << "Pile count less of 2 elements" << std::endl;
      return (EXIT_FAILURE);
    }
  v1 = pile.top();
  pile.pop();
  v2 = pile.top();
  pile.pop();
  this->pile.push((*v1) * (*v2));
  delete v1;
  delete v2;
  return (0);
}

bool	Calculator::isNull(const std::string & str)
{
  std::string cpy = str;
  std::string::iterator it;
  
  for(it = cpy.begin(); it != cpy.end(); it++)
    {
      if ((*it) != '0' || (*it) != '.' || (*it) != '-')
	return false;
    }
  return true;
}

int	Calculator::div()
{
  IOperand	*v1;
  IOperand	*v2;
  
  if (pile.size() < 2)
    {
      std::cerr << "Pile count less of 2 elements" << std::endl;
      return (EXIT_FAILURE);
    }
  v1 = pile.top();
  pile.pop();
  v2 = pile.top();
  pile.pop();
  if (isNull(v2->getValue()) == false)
    this->pile.push((*v1) / (*v2));
  else
    {
      delete v1;
      delete v2;
      std::cerr << "Impossible to divide by zero" << std::endl;
      return (EXIT_FAILURE);
    }
  delete v1;
  delete v2;
  return (0);
}

int	Calculator::mod()
{
  IOperand *v1;
  IOperand *v2;
  IOperand *res;
  
  if (pile.size() < 2)
    {
      std::cerr << "Pile count less of 2 elements" << std::endl;
      return (EXIT_FAILURE);
    }
  v1 = pile.top();
  pile.pop();
  v2 = pile.top();
  pile.pop();
  res = (*v1) % (*v2);
  if (res != NULL)
    {
      this->pile.push(res);
      delete v1;
      delete v2;
      return (0);
    }
  delete v1;
  delete v2;
  std::cerr << "Impossible to make a modulo with a decimal number" << std::endl;
  return (EXIT_FAILURE);
}

int Calculator::print()
{
  IOperand *v1;
  short tmp;
  
  if (pile.size() < 1)
    return (EXIT_FAILURE);
  v1 = pile.top();
  if (v1->getType() != INT8)
    {
      std::cerr << "Value on top is not a 8 bit value" << std::endl;
      delete v1;
      return (EXIT_FAILURE);
    }
  else
    {
      std::stringstream conv;
      char s;
      conv << v1->getValue();
      conv >> tmp;
      s = tmp;
      std::cout << s << std::endl;
    }
  delete v1;
  return (0);
}
