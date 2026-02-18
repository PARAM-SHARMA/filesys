#include "FS.h"
#include <iostream>

enum Command {
  MKDIR,
  RMDIR,
  TOUCH,
  PWD,
  CD,
  TREE,
  LS,
  EXIT,
  UNKNOWN
};

Command getCommand(const std::string& cmd) {
  if (cmd == "mkdir") return MKDIR;
  if (cmd == "rmdir") return RMDIR;
  if (cmd == "touch") return TOUCH;
  if (cmd == "pwd")   return PWD;
  if (cmd == "cd")    return CD;
  if (cmd == "tree")  return TREE;
  if (cmd == "ls")  return LS;
  if (cmd == "exit")  return EXIT;
  return UNKNOWN;
}

int main() {
  FS fs;
  std::string cmd;
  std::string arg1;
  std::string arg2;

  while(true) {
    fs.pwd();
    std::cout << "> ";
    std::cin >> cmd;

    Command command = getCommand(cmd);

    switch (command) {
      case MKDIR:
        std::cin >> arg1 >> arg2;
        fs.mkdir(arg1, arg2);
        break;

      case RMDIR:
        std::cin >> arg1;
        fs.rmdir(arg1);
        break;

      case TOUCH:
        std::cin >> arg1 >> arg2;
        fs.touch(arg1, arg2);
        break;

      case PWD:
        fs.pwd();
        break;

      case CD:
        std::cin >> arg1;
        fs.cd(arg1);
        break;

      case TREE:
        fs.tree();
        break;

      case LS:
        fs.ls();
        break;

      case EXIT:
        return 0;  // or break if inside loop

      case UNKNOWN:
        std::cout << "Unknown command" << std::endl;
        break;
    }
  }

  std::cout << std::endl;

  return 0;
}
