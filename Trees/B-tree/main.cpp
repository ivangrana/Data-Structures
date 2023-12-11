#include "Btree.h"
#include <iomanip>
#include <iostream>
#include <queue>
int main() {
  ArvoreB arvore;
  std::vector<int> chaves = {15, 9,  30, 4, 20, 35};

  for (int key : chaves) {
    arvore.insert(key);
  }

  std::cout << "Arvore B:" << std::endl;
  arvore.mostrarArvore(); // metodo para mostrar a arvore

  int chave_procurada = 90; // Busca por um elemento na arvore
  if (arvore.buscar(chave_procurada)) {
    std::cout << "A chave " << chave_procurada << " foi encontrada na árvore B."<< std::endl;
  } else {
    std::cout << "A chave " << chave_procurada << " não foi encontrada na árvore B." << std::endl;
  }
  return 0;
}
