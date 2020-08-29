1. Por que o Linux recebeu esse nome?
	```
	O Linux recebeu esse nome graças a junção do nome de seu criador, Linus Torvalds, e a palavra Unix.
	```
2. O que são daemons?
	```
	Daemons são programas que executam no computador em forma de processo em segundo plano, sem estar sob controle direto de um usuário interativo.
	```
3. O que é o shell?
	```
	Shell é um interpretador de comandos do Linux. Nele é possível utilizar vários comandos de interfaceamento entre o usuário e o sistema operacional.
	```
4. Por que é importante evitar executar o terminal como super-usuário?
	```
	Porque como super-usuário é possível que ao executar alguns comandos de forma errada pode acarretar em bugs e corrupção do sistema.
	```
5. Qual botão do teclado completa o que o usuário escreve no terminal, de acordo com o contexto?
	```
	É a tecla de tabulação (TAB).
	```
6. Quais botões do teclado apresentam instruções escritas anteriormente?
	```
	São os botões de direcionais  para cima e para baixo.
	```
7. Apresente os respectivos comandos no terminal para:

  (a) Obter mais informações sobre um comando.
   	```bash
	[comando] --help
	
	```
	
  (b) Apresentar uma lista com os arquivos dentro de uma pasta.
  	```bash
	ls
	```
	
  (c) Apresentar o caminho completo da pasta.
	```bash
	pwd
	```

  (d) Trocar de pasta.
  	```bash
	cd [caminho da pasta]
	```
	
  (e) Criar uma pasta.
  	```bash
	mkdir [nome da pasta]
	```
	
  (f) Apagar arquivos definitivamente.
  	```bash
	rm [arquivo]
	```
	
  (g) Apagar pastas definitivamente.
  	```bash
	rm -rf [pasta]
	```
	
  (h) Copiar arquivos.
  	```bash
	cp [arquivo] [destino]
	```
  (i) Copiar pastas.
  	```bash
	cp -r [pasta] [destino]
	```
	
  (j) Mover arquivos.
  	```bash
	mv [arquivo] [destino]
	```
	
  (k) Mover pastas.
  
  	```bash
	mv -r [pasta] [destino]
	```
	
  (l) Renomear pastas.
  	```bash
	mr [pasta] [mesmo diretório] [pasta]
	```
  (m) Apresentar o conteúdo de um arquivo.
  	```bash
	cat [arquivo]
	```
  (n) Apresentar o tipo de um arquivo.
	```bash
	file [arquivo]
	```
  (o) Limpar a tela do terminal.
  	```bash
	clear
	```
  (p) Encontrar ocorrências de palavras-chave em um arquivo-texto.
  	```bash
	grep [palavra-chave] [arquivo.txt]
	```
  (q) Ordenar informações em um arquivo-texto.
  	```bash
	sort[arquivo.txt]
	```
  (r) Substituir ocorrências de palavras-chave em um arquivo-texto.
  	```bash
	sed -e 's/[nome1]/nome2/' [arquivo.txt]
	```
  (s) Conferir se dois arquivos são iguais.
  	```bash
	diff
	```
  (t) Escrever algo na tela.
  	```bash
	echo
	```
