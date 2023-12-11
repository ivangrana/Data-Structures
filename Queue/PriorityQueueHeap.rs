//autor: <|Ivan Grana|>
//sobre: implementação de uma fila de prioridades

// Estrutura da lista de prioridades
struct ListaPrioridades {
    heap: Vec<i32>,
}

// Implementação das rotinas

impl ListaPrioridades {
    fn new() -> Self {
        ListaPrioridades { heap: Vec::new() }
    }

    // Metodo para construir o heap
    fn construir_heap(&mut self, valores: Vec<i32>) {
        self.heap = valores;
        let n = self.heap.len();
        // Calcula o índice do nó pai
        for i in (0..n / 2).rev() {
          // Calcula o índice do nó filho
            self.heapify_down(i, n); 
        }
    }

    // Metodo para manter a propriedade do heap movendo o maior valor para a raiz
    fn heapify_down(&mut self, mut i: usize, n: usize) {
        loop {
            let filho_esquerda = 2 * i + 1; // índice do filho esquerdo
            let filho_direita = 2 * i + 2; // índice do filho direito

            let mut filho_menor = filho_esquerda;

            // Caso o filho esquerdo seja menor que o tamanho do heap
            if filho_direita < n && self.heap[filho_direita] < self.heap[filho_esquerda]
            {
                filho_menor = filho_direita; // Atualiza o filho menor
            }

            if filho_menor < n && self.heap[i] > self.heap[filho_menor] {
                self.heap.swap(i, filho_menor);
                i = filho_menor;
            } else {
                break;
            }
        }
    }

    // metodo de inserção de um elemento na fila de prioridade
    fn inserir_elemento(&mut self, elemento: i32) {
        self.heap.push(elemento);
        let mut i = self.heap.len() - 1;
        // move o novo elemento inserido para a posição correta
        while i > 0 {
            let pai = (i - 1) / 2;
            if self.heap[i] < self.heap[pai] { // verifica se o novo elemento é menor que o pai
                self.heap.swap(i, pai);
                i = pai;
            } else {
                break;
            }
        }
    }

    // Metodo para remover o elemento de maior prioridade
    fn remover_maior_prioridade(&mut self) -> Option<i32> {
        if self.heap.is_empty() {
            // Caso a lista de prioridades esteja vazia, retorna None
            None
        } else {
            // remove a raiz e atualiza o heap
            let elemento_removido = Some(self.heap[0]);
            let ultimo_elemento = self.heap.pop().unwrap();
            if !self.heap.is_empty() {
                self.heap[0] = ultimo_elemento; // posiciona o ultimo elemento na raiz
                self.heapify_down(0, self.heap.len()); // atualiza o heap e mantém a propriedade do heap
            }
            elemento_removido
        }
    }

    // realizar o heap sort
    fn heapsort(&mut self) {
        let mut ordenado = Vec::new();
        // enquanto a lista de prioridades não estiver vazia
        while let Some(elemento) = self.remover_maior_prioridade() {
            ordenado.push(elemento); // adiciona o elemento removido à lista ordenada
        }
        self.heap = ordenado;
    }

    // Metodo para imprimir a lista de prioridades
    fn visualizar_fila(&self) {
        println!("Tamanho da fila: {}", self.heap.len());
        println!("Elementos da fila: {:?}", self.heap);
    }
}

fn main() {
    // cria uma nova fila de prioridades
    let mut lista_prioridades = ListaPrioridades::new();

    // 1. Construir Heap
    let valores_aleatorios = vec![3, 12, 4, 1, 5, 9, 2, 6, 14, 3];
    lista_prioridades.construir_heap(valores_aleatorios);

    // 2. Inserir elemento
    let novo_elemento = 7;
    lista_prioridades.inserir_elemento(novo_elemento);

    // 3. Remover o elemento de maior prioridade
    if let Some(removido) = lista_prioridades.remover_maior_prioridade() {
        println!("Elemento de maior prioridade removido: {}", removido);
    }

    // 4. Ordenar usando HeapSort
    lista_prioridades.heapsort();

    // 5. Visualizar a fila
    lista_prioridades.visualizar_fila();
}
