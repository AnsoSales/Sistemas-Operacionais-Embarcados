1. O que são sistemas embarcados?

	Sistemas embarcados são uma combinação de hardware e software, muitas vezes combinada com outras partes elétricas, projetada para a execução de uma atividade específica. Em muitos 	casos fazem parte de um sistema maior.

2. O que são sistemas microprocesssados?

	É um sistema no qual o computador é completamente encapsulado ou dedicado ao dispositivo ou sistema que ele controla, realizando um conjunto de tarefas predefinidas, em sua maior parte com requisitos específicos.

3. Apresente aplicações de sistemas embarcados:
	(a) Para a indústria automotiva;
		Sistema de GPS e navegação, alarmes, controle de tração.
	(b) Para eletrodomésticos;
		Smart TV, microondas, geladeiras
	(c) Para automação industrial.
		Braço robóticos, fresadoras CNC. 
4. Cite arquiteturas possíveis e as diferenças entre elas.

	Temos as arquiteturas em CI, FPGA e Microcontroladores. O CI já possui um circuito dedicado à alguma função em específica que pode auxiliar ou até mesmo executar alguma aplicação. A FPGA trabalha com a ideia de circuito reconfigurável por meio de uma linguagem de descrição de hardware (VHDL, Verilog...), ou seja, é possível reconfigurar o circuito uma vez implementado/programado nesta arquitetura. Microcontroladores por sua vez já possuem alguns periféricos na sua contrução que auxiliam na execução de algum projeto, como conversores AD, Timers, PWM, memórias RAM e ROM, dentre outros. Usando estes periféricos e uma linguagem de programação mais alto nivel pode-se usar o microcontrolador para executar inúmeras tarefas.


5. Por que usamos o Raspberry Pi na disciplina, ao invés de outro system-on-chip?

	Porque o Raspberry PI é um SoC que pode executar a versão completa do Linux. Ele é basicamente um mini computador. Possui saída HDMI e permite o uso de teclado, mouse e câmera, o que a torna uma placa muito versáril.
