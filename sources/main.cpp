//
// main.cpp for abstract_vm in /home/kersal_e/projet_actuels/cpp_abstractvm
// 
// Made by Elliot Kersale
// Login   <kersal_e@epitech.net>
// 
// Started on  Thu Feb 20 10:35:01 2014 Elliot Kersale
// Last update Wed Feb 26 20:39:21 2014 Martin Porrès
//

#include		<cstdlib>
#include		"Parse.hh"

int			main(int ac, char **av)
{
  try
    {
      if (ac > 1)
	{
	  Parse	command;
	  for (int i = 1; i <= (ac - 1); i++)
	    {
	      std::ifstream file(av[i]);
	      if (file.fail())
		std::cerr << "File : " << av[i] << " : does not exist" << std::endl;
	      else
		{
		  std::string buff;
		  while (getline(file, buff))
		    {
		      command.set_line(buff);
		      if (command.clean_line() == 1)
		      	{
			  std::cerr << "Error on parsing file : " << buff << std::endl;
			  return (EXIT_FAILURE);
		      	}
		      if (buff == "exit")
			break ;
		    }
		}
	      command.send();
	      file.close();
	    }
	}
      else
	{
	  std::string buff;
	  Parse	command;
	  while(getline(std::cin, buff, '\n'))
	    {
	      command.set_line(buff);
	      command.clean_line();
	      if (buff.find(";;") == 0)
		break ;
	    }
	  command.send();
	}
    }
  catch(std::exception &e)
    {
      std::cerr << "error : " << e.what() << std::endl;
    }
  return (0);
}
