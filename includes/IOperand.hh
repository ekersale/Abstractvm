//
// IOperand.hh for abstract_vm in /home/kersal_e/projet_actuels/cpp_abstractvm/includes
// 
// Made by Elliot Kersale
// Login   <kersal_e@epitech.net>
// 
// Started on  Thu Feb 20 14:19:55 2014 Elliot Kersale
// Last update Wed Feb 26 20:41:23 2014 Martin Porrès
//

#ifndef			_IOPERAND_HH__
# define		_IOPERAND_HH__
/*
** ENUM TYPE
*/
typedef enum
{
	INT8,
	INT16,
	INT32,
	FLOAT,
	DOUBLE
}	eOperandType;
/*
** IOPERAND INTERFACE
*/
class IOperand
{
public:
  virtual ~IOperand() {};

  virtual std::string const &toString() const = 0;
  
  virtual int getPrecision() const = 0;
  virtual eOperandType getType() const = 0;
  virtual std::string getValue() const = 0;
  virtual double transform(std::string) const = 0;
  virtual bool check(double, std::string) const = 0;

  virtual IOperand *operator+(const IOperand &rhs) const = 0;
  virtual IOperand *operator-(const IOperand &rhs) const = 0;
  virtual IOperand *operator*(const IOperand &rhs) const = 0;
  virtual IOperand *operator/(const IOperand &rhs) const = 0;
  virtual IOperand *operator%(const IOperand &rhs) const = 0;
};
/*
**
*/
#endif
//EOF _IOPERAND_HH__
