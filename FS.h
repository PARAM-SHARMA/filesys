#ifndef FS_H
#define FS_H

#include <string>
#include <vector>

class FS {
private:
  struct Node {
    std::string name;
    bool isFile;
    std::string content;
    std::vector<Node*> children;
    Node* parent;


    Node (std::string name, bool isFile);
  };

  Node* root;
  Node* currDir;
  std::vector<std::string> split(std::string path, char divider);
  Node* traversePath(std::string path);

public:

  FS();

  void printTree(Node* node, int indent);

  void tree();

  void cd(std::string path);

  void mkdir(std::string name, std::string path);

  void touch(std::string name, std::string path);

  void rmdir(std::string path);

  void ls();

  void pwd();
};

#endif
