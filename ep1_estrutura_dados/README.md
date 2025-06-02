
# HealthSys - Sistema de Gerenciamento de Pacientes

## Descrição
Este projeto implementa um sistema de gerenciamento de pacientes para uma clínica, utilizando linguagem C. Os dados dos pacientes são armazenados em um arquivo CSV e carregados em um vetor estático na memória.

## Funcionalidades
- Consulta por prefixo de nome ou CPF
- Impressão da lista de todos os pacientes

## Como compilar e executar

```bash
make
make run
make clean
```

## Estrutura do repositório
- `include/paciente.h`: definição dos TADs e protótipos de função
- `src/paciente.c`: implementação da lógica do sistema
- `src/main.c`: menu principal
- `bd_paciente.csv`: base de dados exemplo
- `Makefile`: facilita compilação e execução

## TADs Utilizados
- `Paciente`: representa os dados de um paciente
- `BDPaciente`: vetor estático que armazena todos os pacientes na memória

## Decisões de implementação
- Utiliza vetor estático por ser mais simples
- Funções bem modularizadas
- Leitura do CSV com `sscanf` para evitar dependências externas

---

Projeto desenvolvido para a disciplina de Estrutura de Dados - IFES (Campus Serra)
