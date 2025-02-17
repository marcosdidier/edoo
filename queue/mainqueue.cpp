#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    try {
        Queue<int> q;

        cout << "🔹 Enfileirando 10, 20, 30...\n";
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        cout << "📌 Tamanho da fila: " << q.length() << endl;
        cout << "📌 Primeiro da fila: " << q.frontValue() << endl;

        cout << "✅ Removendo: " << q.dequeue() << endl; // Deve remover 10
        cout << "✅ Removendo: " << q.dequeue() << endl; // Deve remover 20

        cout << "📌 Tamanho da fila após remoções: " << q.length() << endl;
        cout << "📌 Primeiro da fila agora: " << q.frontValue() << endl;

        cout << "✅ Removendo o último elemento...\n";
        cout << "✅ Removendo: " << q.dequeue() << endl; // Deve remover 30

        cout << "📌 Tamanho da fila: " << q.length() << endl;

        cout << "⚠ Tentando remover de uma fila vazia...\n";
        cout << "✅ Removendo: " << q.dequeue() << endl; // Deve lançar uma exceção

    } catch (const exception& e) {
        cout << "🚨 Erro capturado: " << e.what() << endl;
    }

    return 0;
}