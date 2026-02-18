#include "FS.h"
#include <iostream>
#include <sstream>


FS::FS() {
  this->root = new Node("root", false);
  this->currDir = this->root;
}

FS::Node::Node(std::string name, bool isFile) {
  this->name = name;
  this->isFile = isFile;
  this->parent = nullptr;
}

std::vector<std::string> FS::split(std::string path, char divider) {
  std::stringstream ss(path);
  std::string item;
  std::vector<std::string> result;

  while (std::getline(ss, item, divider)) {
    result.push_back(item);
  }

  return result;
}

void FS::printTree(Node* node, int indent) {
  if (node == nullptr) return;

  for (int i = 0; i < indent; i++) {
    std::cout << " ";
  }

  std::cout << node->name << std::endl;

  for (Node* child : node->children) {
    printTree(child, indent + 1);
  }
}

void FS::tree() {
  printTree(this->root, 0);
}

FS::Node* FS::traversePath(std::string path) {
  std::vector<std::string> pathVec = split(path, '/');
  Node* curr = this->currDir;

  for (std::string str : pathVec) {
    bool childFound = false;
    bool file = false;

    if (str == "..") {
      if (curr->parent != nullptr) curr = curr->parent;
      continue;
    }

    for (Node* child : curr->children) {
      if (str == child->name && !child->isFile) {
        curr = child;
        childFound = true;
        break;
      }
      if (str == child->name && child->isFile) {
        file = true;
        std::cout << child->name << " is a directory" << std::endl;
        break;
      }
    }

    if (!childFound) return nullptr;
    if (file) break;
  }

  return curr;
}

void FS::cd(std::string path) {
  Node* dir = traversePath(path);

  if (dir != nullptr) {
    this->currDir = dir;
  }
}

void FS::mkdir(std::string name, std::string path) {
  cd(path);

  Node* dir = new Node(name, false);
  dir->parent = this->currDir;
  this->currDir->children.push_back(dir);

  std::cout << "Directory '" << name << "' created successfully in "
    << (path.empty() ? "current directory" : path) << std::endl;
}

void FS::touch(std::string name, std::string path) {
  cd(path);

  Node* file = new Node(name, true);
  file->parent = this->currDir;
  this->currDir->children.push_back(file);

  std::cout << "File '" << name << "' created successfully in "
    << (path.empty() ? "current directory" : path) << std::endl;
}

void FS::rmdir(std::string path) {
  Node* dir = traversePath(path);
  if (!dir) {
    std::cout << "Directory not found" << std::endl;
    return;
  }

  Node* parent = dir->parent;
  if (!parent) return;

  bool dirFound = false;
  for (int i = 0; i < parent->children.size(); i++) {
    if (parent->children[i] == dir) {
      parent->children.erase(parent->children.begin() + i);
      dirFound = true;
      break;
    }
  }

  if (!dirFound) {
    std::cout << "Directory not found" << std::endl;
    return;
  }

  std::cout << "File '" << dir->name << "' deleted successfully in "
    << (path.empty() ? "current directory" : path) << std::endl;
}

void FS::pwd() {
  Node* temp = this->currDir;
  std::vector<std::string> path;

  while (temp != nullptr) {
    path.push_back(temp->name);
    temp = temp->parent;
  }

  for (int i = path.size() - 1; i >= 0; i--) {
    std::cout << "/" << path[i];
  }
}

void FS::ls() {
  Node* temp = this->currDir;

  for(Node* child : this->currDir->children) {
    std::string type = child->isFile ? "File" : "Dir";
    std::cout << type << " " << child->name << (type == "Dir" ? "/" : "") << std::endl;
  }

}
