#include "Btree.h"
#include <iomanip>
#include <iostream>
#include <queue>

const int grau = 3;

ArvoreBNode::ArvoreBNode(bool leaf) : e_folha(leaf) {}

ArvoreB::ArvoreB() : raiz(nullptr) {}

void ArvoreB::insert(int key)
{
    if (raiz == nullptr)
    {
        raiz = new ArvoreBNode();
        raiz->chaves.push_back(key);
    }
    else
    {
        if (raiz->chaves.size() == (2 * grau) - 1)
        {
            ArvoreBNode *new_raiz = new ArvoreBNode(false);
            new_raiz->filhos.push_back(raiz);
            split_child(new_raiz, 0);
            inserir_nao_nulo(new_raiz, key);
            raiz = new_raiz;
        }
        else
        {
            inserir_nao_nulo(raiz, key);
        }
    }
}

void ArvoreB::inserir_nao_nulo(ArvoreBNode *node, int key)
{
    int i = node->chaves.size() - 1;
    if (node->e_folha)
    {
        node->chaves.push_back(0);
        while (i >= 0 && key < node->chaves[i])
        {
            node->chaves[i + 1] = node->chaves[i];
            i--;
        }
        node->chaves[i + 1] = key;
    }
    else
    {
        while (i >= 0 && key < node->chaves[i])
        {
            i--;
        }
        i++;
        if (node->filhos[i]->chaves.size() == (2 * grau) - 1)
        {
            split_child(node, i);
            if (key > node->chaves[i])
            {
                i++;
            }
        }
        inserir_nao_nulo(node->filhos[i], key);
    }
}

void ArvoreB::split_child(ArvoreBNode *parent, int index)
{
    ArvoreBNode *child = parent->filhos[index];
    ArvoreBNode *new_child = new ArvoreBNode(child->e_folha);
    parent->chaves.insert(parent->chaves.begin() + index,
                          child->chaves[grau - 1]);
    parent->filhos.insert(parent->filhos.begin() + index + 1, new_child);
    new_child->chaves.assign(child->chaves.begin() + grau, child->chaves.end());
    child->chaves.erase(child->chaves.begin() + grau, child->chaves.end());
    if (!child->e_folha)
    {
        new_child->filhos.assign(child->filhos.begin() + grau, child->filhos.end());
        child->filhos.erase(child->filhos.begin() + grau, child->filhos.end());
    }
}

void ArvoreB::mostrarArvore()
{
    if (raiz == nullptr)
    {
        return;
    }

    std::queue<ArvoreBNode *> nodes;
    nodes.push(raiz);

    while (!nodes.empty())
    {
        int level_size = nodes.size();
        bool first_cell = true;

        for (int i = 0; i < level_size; i++)
        {
            ArvoreBNode *node = nodes.front();
            nodes.pop();

            if (node == raiz)
            {
                int padding = 15 * (raiz->chaves.size() - 1);
                std::cout << std::setw(padding) << " ";
            }

            if (first_cell)
            {
                std::cout << std::setw(4) << node->chaves[0] << " ";
                first_cell = false;
            }
            else
            {
                std::cout << std::setw(4) << ""
                          << " ";
            }

            for (int j = 1; j < node->chaves.size(); j++)
            {
                std::cout << std::setw(4) << node->chaves[j] << " ";
            }
            if (!node->e_folha)
            {
                for (ArvoreBNode *child : node->filhos)
                {
                    nodes.push(child);
                }
            }
        }
        std::cout << "\n\n\n\n\n";
    }
}

bool ArvoreB::buscar(int key)
{
    if (raiz == nullptr)
    {
        return false;
    }
    else
    {
        return buscar_recursivo(raiz, key);
    }
}

bool ArvoreB::buscar_recursivo(ArvoreBNode *node, int key)
{
    int i = 0;
    while (i < node->chaves.size() && key > node->chaves[i])
    {
        i++;
    }

    if (i < node->chaves.size() && key == node->chaves[i])
    {
        return true; // A chave foi encontrada
    }
    else if (node->e_folha)
    {
        return false; // A chave não foi encontrada
    }
    else
    {
        return buscar_recursivo(node->filhos[i],
                                key); // Continue a busca nos filhos apropriados
    }
}