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
    int childCount;
    Node* parent;


    Node (std::string name, bool isFile);
  };

  Node* root;
  Node* currDir;
  std::vector<std::string> split(std::string path, char divider);
  Node* traversePath(const std::string& path);

public:

  FS();

  void printTree(Node* node, int indent);

  void tree();

  void serialize();
  void serializeHelper(Node* node, std::string& serial);

  void deserialize(const std::string& serial);
  Node* deserializeHelper(Node* node, const std::vector<std::string>& serial, int& i);

  void cd(const std::string& path);

  void mkdir(const std::string& name, const std::string& path);

  void touch(const std::string& name, const std::string& path);

  void rmdir(const std::string& path);

  void ls() const;

  void pwd() const;
};

#endif // FS_H
