//
// Operand.hh for abstract_vm in /home/porres_m/PROJETS/abstract_VM/cpp_abstractvm/includes
// 
// Made by Martin Porrès
// Login   <porres_m@epitech.net>
// 
// Started on  Thu Feb 20 16:10:54 2014 Martin Porrès
// Last update Sat Mar  1 18:29:48 2014 Elliot Kersale
//

#ifndef			_OPERAND_HPP__
# define		_OPERAND_HPP__
/*
** INCLUDES
*/
#include		<iostream>
#include		<sstream>
#include		"IOperand.hh"
/*
** OPERAND CLASS
*/
template<class T>
class Operand : public IOperand
{
public:
  Operand(std::string const &, eOperandType);
  Operand(T, eOperandType, int);
  Operand(const Operand &);
  ~Operand();
  
  IOperand *operator+(const IOperand &rhs) const;
  IOperand *operator-(const IOperand &rhs) const;
  IOperand *operator*(const IOperand &rhs) const;
  IOperand *operator/(const IOperand &rhs) const;
  IOperand *operator%(const IOperand &rhs) const;
  
  std::string const &toString() const;
  int getPrecision() const;
  eOperandType getType() const;
  std::string getValue() const;
  double transform(std::string) const;
  bool check(double, std::string) const;
  T return_v() const;
private:
  T		_value;
  eOperandType	_type;
  int		_precision;
};
/*
** OPERAND METHODES
*/
template<typename T>
Operand<T>::Operand(std::string const & value, eOperandType i) :  _type(i), _precision(i)
{
  std::stringstream conv;
  conv << value;
  conv >> _value;
}

template<typename T>
Operand<T>::Operand(T value, eOperandType i, int precision) : _value(value), _type(i), _precision(precision)
{
  
}

template<typename T>
Operand<T>::Operand(const Operand &cpy)
{
  _value = cpy.getValue();
  _type = cpy.getType();
}

template<typename T>
Operand<T>::~Operand()
{

}

template<typename T>
std::string const &Operand<T>::toString() const
{
  
}

template<typename T>
T Operand<T>::return_v() const
{
  return (_value);
}

template<typename T>
int Operand<T>::getPrecision() const
{
  return (_precision);
}

template<typename T>
eOperandType Operand<T>::getType() const
{
  return (_type);
}

template<typename T>
std::string Operand<T>::getValue() const
{
  std::string conv;
  std::stringstream it;

  it << _value;
  it >> conv;
  return (conv);
}

template<typename T>
IOperand *Operand<T>::operator+(const IOperand &rhs) const
{
  T		value;
  eOperandType	type;
  int		precision;
  
  if (this->getPrecision() > rhs.getPrecision())
    {
      precision = this->getPrecision();
      type = this->getType();
     }
  else
    {
      precision = rhs.getPrecision();
      type = rhs.getType();
    }
  value = this->transform(this->getValue()) + rhs.transform(rhs.getValue());
  Operand	*res = new Operand(value, type, precision);
  return (res);
}

template<typename T>
IOperand *Operand<T>::operator-(const IOperand &rhs) const
{
  T		value;
  eOperandType	type;
  int		precision;
  
  if (this->getPrecision() > rhs.getPrecision())
    {
      precision = this->getPrecision();
      type = this->getType();
    }
  else
    {
      precision = rhs.getPrecision();
      type = rhs.getType();
    }
  value = (double)(this->_value) - rhs.transform(rhs.getValue());
  Operand	*res = new Operand(value, type, precision);
  return (res);
}

template<typename T>
IOperand *Operand<T>::operator*(const IOperand &rhs) const
{
  T		value;
  eOperandType	type;
  int		precision;

  if (this->getPrecision() > rhs.getPrecision())
    {
      precision = this->getPrecision();
      type = this->getType();
    }
  else
  {
    precision = rhs.getPrecision();
    type = rhs.getType();
  }
  value = (double)(this->_value) * rhs.transform(rhs.getValue());
  Operand	*res = new Operand(value, type, precision);
  return (res);
}

template<typename T>
IOperand *Operand<T>::operator/(const IOperand &rhs) const
{
  T		value;
  eOperandType	type;
  int		precision;

  if (this->getPrecision() > rhs.getPrecision())
    {
      precision = this->getPrecision();
      type = this->getType();
    }
  else
    {
      precision = rhs.getPrecision();
      type = rhs.getType();
    }
  value = (double)(this->_value) / rhs.transform(rhs.getValue());
  Operand	*res = new Operand(value, type, precision);
  return (res);
}

template<typename T>
IOperand *Operand<T>::operator%(const IOperand &rhs) const
{
  T		value;
  eOperandType	type;
  int		precision;
  double	tmp;
  
  if (this->getPrecision() > rhs.getPrecision())
    {
      precision = this->getPrecision();
      type = this->getType();
    }
  else
    {
      precision = rhs.getPrecision();
      type = rhs.getType();
    }
  tmp = rhs.transform(rhs.getValue());
  if (rhs.check((double)(this->_value), rhs.getValue()) == true)
    value = (int)(this->_value) % (int)(tmp);
  else
    return (NULL);
  Operand	*res = new Operand(value, type, precision);
  return (res);
}

template<typename T>
double	Operand<T>::transform(std::string str) const
{
  std::stringstream conv;
  double res;
  
  conv << str;
  conv >> res;
  return (res);
}

template<typename T>
bool	Operand<T>::check(double v1, std::string v2) const
{
  std::string conv;
  std::stringstream it;
  
  if (v2.find(".", 0) != v2.npos)
    return false;
  it << v1;
  it >> conv;
  if (conv.find(".", 0) != conv.npos)
    return false;
  return (true);  
}
/*
**
*/
#endif
//EOF _OPERAND_HPP__
