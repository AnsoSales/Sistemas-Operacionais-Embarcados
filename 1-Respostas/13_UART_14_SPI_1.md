1. Cite as vantagens e desvantagens das comunicação serial:

(a) Assíncrona (UART).
```
Vantagens: Comunicação full-duplex, protocolo mais simples.
Desvantagens: Falta de sincronismo pode acarretar em mais erros de transmissão de bits.
```
(b) SPI.

```
Vantagens: Full-Duplex e sem limites de número de escravos conectados. Velocidade de comunicação muito boa.
Desvantagens: Quanto mais dispositivos conectados, mais fios e pinos serão necessários, tornando essa forma de conexão muitas vezes inviável.
```

2. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?
```
É possivel sim, já que se trata de uma comunicação full-duplex.
```

3. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?
```
Sim, também é possivel, por também se tratar de uma comunicação full-duplex.
```

4. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?
```
Deve-se setar um bit adicional do protocolo, que seria o bit de endereço. Os dispositivos conectados entenderão que, se esse bit de endereço for 0, o que se está enviando é um dado. Caso ele seja 1, será o endereço do dispositivo a se comunicar.
```

5. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?
