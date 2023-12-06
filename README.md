# CapiStud

## Sobre o Projeto
**CapiStud**, carinhosamente homenageando as icônicas capivaras, é um fórum de tira-dúvidas de alunos para monitores das universidades, desenvolvido durante
o curso de Programação e Desenvolvimento de Software II.  
Esse sistema é voltado exclusivamente para estudantes de nível superior, e visa, principalmente, direcionar a atenção dos alunos 
a tópicos e disciplinas específicas de seu interesse, poupando-os de distrações e facilitando o entendimento dos conteúdos.

## Funcionalidades
Com a CapiStud, você pode criar uma conta de usuário e usá-la conforme o tipo: se for aluno, será capaz de selecionar as matérias de seu interesse, 
fazer postagens de dúvidas, visualizar as postagens de outros alunos e avaliar a qualidade da resposta de um monitor. Se for um monitor, será capaz 
de se cadastrar em disciplinas que sejam da sua área de ensino, responder às dúvidas dos alunos e receber um _score_ de cada aluno que quiser avaliar 
sua reposta em relação ao quanto ela foi útil.  
O intuito de tal sistema de avaliação é servir como parâmetro para que os monitores saibam o quão efetivos estão sendo em seu trabalho, 
e também para que a universidade à qual estão inseridos possa gratificá-los conforme acharem pertinente.


## Tecnologias utilizadas:
### Back end:
- C++

### Front end:
- HTML
  
	> Para que o projeto fosse feito de maneira mais simples, sem o uso de muitas outras tecnologias adicionais, e o foco principal fosse a linguagem c++, foi desenvolvida a _Capibara Web Interface_,uma biblioteca que traduz o html para o c++.
	[https://github.com/LcsDeveloper/Capybara-Web-Interface]

## Guia de Instalação
Para executar o projeto final, é necessario a utilização de um server com suporte a tecnologia CGI. Em nosso projeto durante todo o desenvolvimento utilizamos o Apache.

### Instalando e configurando o servidor

> Atualizando os repositorios:
```
sudo apt-get update ; sudo apt-get upgrade
```

> Instalando o Apache:
```
sudo apt-get install apache2 -y
```

> Configurando o modulo CGI do servidor:
```
sudo nano /etc/apache2/mods-enabled/mime.conf
```
- Altere a linha: ``` #AddHandler cgi-script .cgi ```
- Para: ``` AddHandler cgi-script .cgi .out ```

> Ativando o modulo cgi:
```
sudo a2enmod cgi
```

> Reiniciando o servidor com as novas configurações:
```
sudo systemctl restart apache2
```

> Instalando o projeto final:
- Altere a pasta ```/usr/lib/cgi-bin```
- Para a pasta ```cgi-bin``` do projeto:
  [https://github.com/Trabalho-PDS/TrabalhoPDS/tree/main/PROJETO_FINAL]

> Adicione as permissões:
```
sudo chmod -R 777 /usr/lib/cgi-bin
```

> Em um navegador acesse:
- localhost/cgi-bin/forum/login_page.out

## Autores
Layane Garcia  
Lucas Bahia  
Lucas Rodrigues  
Sarah Azevedo
