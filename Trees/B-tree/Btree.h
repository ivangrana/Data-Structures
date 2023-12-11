#include <vector>

class ArvoreBNode {
public:
  bool e_folha;
  std::vector<int> chaves;
  std::vector<ArvoreBNode *> filhos;

  ArvoreBNode(bool leaf = true);
};

class ArvoreB {
public:
  ArvoreBNode *raiz;

  ArvoreB();

  void insert(int key);
  void inserir_nao_nulo(ArvoreBNode *node, int key);
  void split_child(ArvoreBNode *parent, int index);
  void mostrarArvore();
  bool buscar(int key);
  bool buscar_recursivo(ArvoreBNode *node, int key);
};

