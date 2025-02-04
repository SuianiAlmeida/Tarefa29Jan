# Simulações de Semáforo com Raspberry Pi Pico W

Este repositório contém duas simulações de semáforo utilizando o Raspberry Pi Pico W:

## Atividade 1: Semáforo com Temporizador Periódico
- Implementação de um semáforo usando `add_repeating_timer_ms()`
- LEDs alternam a cada 3 segundos (vermelho → amarelo → verde)
- Mensagens são impressas na porta serial a cada segundo

### Componentes
- Raspberry Pi Pico W
- 3 LEDs (vermelho, amarelo e verde)
- 3 Resistores de 330Ω

## Atividade 2: Semáforo com Botão e Temporizador
- Implementação usando `add_alarm_in_ms()`
- Controle por botão para iniciar sequência
- LEDs desligam sequencialmente a cada 3 segundos
- Proteção contra múltiplos acionamentos durante a sequência

### Componentes
- Raspberry Pi Pico W
- 3 LEDs (azul, vermelho e verde)
- 3 Resistores de 330Ω
- 1 Botão (Pushbutton)

1. Clone o repositório:
```bash
git clone [https://github.com/SuianiAlmeida/Tarefa27Jan.git]
```

2. Configure a variável de ambiente PICO_SDK_PATH apontando para o diretório do SDK:
```bash
export PICO_SDK_PATH=/caminho/para/pico-sdk
```
3. Abra o projeto no VS Code com a extensão Wokwi

4. Escolha qual atividade deseja simular:
   - Para Atividade 1: Use `Atividade1.c` e `diagram.json`
   - Para Atividade 2: Use `Atividade2.c` e `diagram.json`

5. Crie e entre no diretório de build:
```bash
mkdir build
cd build
```
6. Execute o CMake e compile:
```bash
cmake ..
make
```

## Observações
- Implementado em C usando Pico SDK
- Testado no simulador Wokwi
- Compatível com BitDogLab (GPIOs 11, 12, 13 para LED RGB, GPIO 05 para botão)

 ## 📝 Licença

Este projeto está licenciado sob a Licença MIT - veja para mais detalhes.

MIT License

Copyright (c) 2024 Embarcatech Team

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---
Desenvolvido como parte do projeto Embarcatech 2024

## 🎯 Desenvolvedora

<table>
</td>
    <td align="center">
      <a href="https://github.com/suianialmeida">
        <img src="https://github.com/suianialmeida.png" width="100px;" alt="Foto de Suiani Almeida no GitHub"/><br>
        <b>Suiani Almeida</b>
        <p>Desenvolvedora em Sistemas Embarcados e IoT</p>
      </a>
      </td>