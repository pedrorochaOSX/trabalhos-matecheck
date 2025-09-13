#!/bin/bash

echo "=== MateCheck Challenges ==="
echo "Preparando ambiente de compilação..."

mkdir -p build

echo "Compilando todos os desafios..."

echo "Compilando CartasSuperTrunfo.c..."
gcc -o build/CartasSuperTrunfo CartasSuperTrunfo.c
if [ $? -eq 0 ]; then
    echo "CartasSuperTrunfo.c compilado com sucesso!"
else
    echo "Erro na compilação de CartasSuperTrunfo.c"
fi

echo "Compilando logicaSuperTrunfo.c..."
gcc -o build/logicaSuperTrunfo logicaSuperTrunfo.c
if [ $? -eq 0 ]; then
    echo "logicaSuperTrunfo.c compilado com sucesso!"
else
    echo "Erro na compilação de logicaSuperTrunfo.c"
fi

echo "Compilando xadrez.c..."
gcc -o build/xadrez xadrez.c
if [ $? -eq 0 ]; then
    echo "xadrez.c compilado com sucesso!"
else
    echo "Erro na compilação de xadrez.c"
fi

echo "Compilando batalhaNaval.c..."
gcc -o build/batalhaNaval batalhaNaval.c
if [ $? -eq 0 ]; then
    echo "batalhaNaval.c compilado com sucesso!"
else
    echo "Erro na compilação de batalhaNaval.c"
fi

echo "Para executar os programas, use:"
echo "1. Cartas Super Trunfo: ./build/CartasSuperTrunfo"
echo "2. Lógica Super Trunfo: ./build/logicaSuperTrunfo"
echo "3. Desafio de Xadrez: ./build/xadrez"
echo "4. Batalha Naval: ./build/batalhaNaval"