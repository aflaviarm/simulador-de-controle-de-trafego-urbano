# Simulador de controle de tráfego urbano

O objetivo deste projeto é desenvolver um simulador de controle de tráfego urbano utilizando FreeRTOS, threads e semáforos (do sistema operacional) para gerenciar a sincronização entre as tarefas. O sistema irá controlar semáforos de trânsito em uma rede de cruzamentos, garantindo o fluxo seguro e eficiente de veículos. O projeto incluirá detalhes como distâncias entre semáforos, velocidades máximas permitidas, velocidades dos veículos e a possibilidade de os veículos virarem à esquerda ou à direita nos cruzamentos.

## Estrutura das vias e semáforos

Vamos considerar uma rede urbana composta por 4 cruzamentos interligados, formando uma grade 2x2. Cada cruzamento é a interseção de uma via norte-sul com uma via leste-oeste.

* Distância entre os cruzamentos: 500 metros.
* Total de semáforos controlados: 16 semáforos (4 por cruzamento).
* Direções consideradas em cada cruzamento:
    * Norte-Sul (NS): Veículos que se deslocam do norte para o sul e vice-versa.
    * Leste-Oeste (EW): Veículos que se deslocam do leste para o oeste e vice-versa.
    * Conversões: Veículos podem virar à esquerda ou à direita nos cruzamentos.

## Detalhes de velocidade e distâncias

* Velocidade máxima permitida nas vias:
    * Vias Norte-Sul (NS): 60 km/h.
    * Vias Leste-Oeste (EW): 50 km/h.
* Velocidade dos veículos:
    * Velocidade média dos veículos: Conforme a velocidade máxima permitida na via, com variações aleatórias de ±5 km/h para simular comportamento realista.
* Tempo para percorrer entre cruzamentos:
    * Vias NS: Aproximadamente 30 segundos a 60 km/h para 500 metros.
    * Vias EW: Aproximadamente 36 segundos a 50 km/h para 500 metros.
