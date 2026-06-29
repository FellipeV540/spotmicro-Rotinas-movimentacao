# spotmicro-Rotinas-movimentacao

Repositório de apoio ao artigo sobre **rotinas de movimentação com servomotores** no robô quadrúpede **SpotMicro**.

Este projeto reúne os códigos, parâmetros e materiais utilizados para implementar e testar padrões de movimento, com foco em controle de servos, estabilidade e repetibilidade dos experimentos.

---

## 📌 Sobre este repositório

Este repositório foi criado para dar suporte ao artigo, permitindo que leitores possam:

- consultar o código-fonte utilizado nos experimentos;
- reproduzir rotinas de movimentação descritas no texto;
- validar resultados e parâmetros de teste;
- usar este material como base para novos estudos.

---

## 🎯 Objetivo

Disponibilizar, de forma organizada e pública, os recursos técnicos usados no desenvolvimento e análise de movimentos com servomotores no SpotMicro, facilitando a reprodutibilidade dos resultados apresentados no artigo.

---

## 🧠 Contexto técnico

O conteúdo deste repositório aborda rotinas de movimentação para um robô SpotMicro, incluindo tópicos como:

- sequências de posições angulares dos servos;
- sincronização de movimentos entre membros;
- suavização de transições (interpolação);
- rotinas para deslocamento e ajustes de postura.

> **Observação:** os nomes dos arquivos e scripts refletem etapas de desenvolvimento e testes do artigo.

---

## 📁 Estrutura do repositório

A estrutura pode evoluir ao longo do projeto, mas em geral você encontrará:

- códigos em **C++** para controle das rotinas;
- arquivos auxiliares de configuração/ajuste;
- dados de teste e resultados obtidos durante os experimentos.

---

## ▶️ Como utilizar

1. Clone o repositório:
   ```bash
   git clone https://github.com/FellipeV540/spotmicro-Rotinas-movimentacao.git
   ```

2. Acesse a pasta do projeto:
   ```bash
   cd spotmicro-Rotinas-movimentacao
   ```

3. Compile e execute os arquivos conforme o ambiente utilizado no artigo (microcontrolador/sistema de controle do SpotMicro).

---

## ⚠️ Avisos importantes

- Este repositório tem finalidade acadêmica e experimental.
- Os resultados podem variar conforme hardware, montagem mecânica, calibração dos servos e superfície de teste.
- Recomenda-se testar movimentos com amplitude reduzida antes de operação contínua.
