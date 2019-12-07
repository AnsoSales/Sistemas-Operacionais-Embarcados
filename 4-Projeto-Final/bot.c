#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include<stdio.h>
#include<stdlib.h>
#include "tgbot/tgbot.h"
#include <dirent.h>
#include <string.h>
#include <wiringPi.h>
#include <linux/i2c-dev.h>
#include <pcf8591.h>
#define TOKEN "870108773:AAG75TI6yFPTl3zSEWxZAp6M-F-sDVHpjPQ"
#define SAIDA 25
#define MOTO1 0
#define MOTO2 2
using namespace std;
using namespace TgBot;
#define BASE 64
#define Address 0x48
#define A0 BASE

void *bomba1 (int parameters)
{
	//pid_t filhote;
		
	//	filhote = fork();
	//	if (filhote == 0)
	//	{
			
		digitalWrite(parameters, HIGH);
                usleep(8000000);
                digitalWrite(parameters, LOW);
		usleep(800);
	//	}else
	//	{
	//	digitalWrite(MOTO2, HIGH);
          //      usleep(8000000);
           //     digitalWrite(MOTO2, LOW);
	//	{return -1;}
	return NULL;
	}
	
	
void sqwv(int pin, int degree, int N)
{
	int t1 = (100*degree+4)/9+1500;
	int t2 = 20000-t1;
	int i;
	for(i=0; i<N; i++)
	{
		digitalWrite(pin, HIGH);
		usleep(t1);
		digitalWrite(pin, LOW);
		usleep(t2);
	}
}

int i2c_fd;
void ctrl_c(int sig)
{
	close(i2c_fd);
	exit(-1);
}


	int main (int argc, const char **argv)
	{
	
		 FILE *fp;
		
		 char teste[20] = "oi";
		 char *final;
	        wiringPiSetup();
		pcf8591Setup(BASE, Address);
		pinMode(MOTO1, OUTPUT);
		pinMode(MOTO2, OUTPUT);
   		pinMode(SAIDA, OUTPUT);
   		 char rom[20];
    	 
    	
         string photoFilePath = "urso.jpg";
         string photoMimeType = "image/jpeg";
         //char* temp_final;
        
         



        

		TgBot::Bot bot(TOKEN);
		bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        	bot.getApi().sendMessage(message->chat->id,"Olá! Eu sou o bot do Aquário! Segue lista de comandos;\n /temperatura: mostra a temperatura do aquário. \n /foto: envia uma foto do seu peixe.\n /colocarcomida: alimenta seu peixe.");
        	 });
		bot.getEvents().onCommand("help",[&bot](TgBot::Message::Ptr message ){
		bot.getApi().sendMessage(message->chat->id,"Segue lista de comandos;\n /info: mostra a temperatura do aquário e o ph. \n /foto: envia uma foto do seu peixe.\n /comida: alimenta seu peixe. \n /agua: troca a água do aquário.");
		
});
		bot.getEvents().onCommand("foto",[&bot, &photoFilePath, &photoMimeType](Message::Ptr message){
		int fd1;
		if ((fd1 = open("/dev/video0", O_RDONLY))<0)
			{
			bot.getApi().sendMessage(message->chat->id, "Camera desconectada ou não compatível.");
			return 1; 			
			}
		system("sudo fswebcam -d /dev/video0 640x480 --jpeg 85 -D 1 teste.jpg");
		bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("teste.jpg", photoMimeType));
		system("sudo rm teste.jpg");
       		bot.getApi().sendMessage(message->chat->id, "Foto enviada!");
    });
		bot.getEvents().onCommand("comida", [&bot](TgBot::Message::Ptr message) {
       	        int N = 40; 
		sqwv(SAIDA, -90,N);
		usleep(500000);
		sqwv(SAIDA, 90, N);
		bot.getApi().sendMessage(message->chat->id, "Comida servida!");
    });
					
		bot.getEvents().onCommand("agua", [&bot](TgBot::Message::Ptr message) { 
		system("./moto");
                bot.getApi().sendMessage(message->chat->id, "Água trocada!");
    });
			

	bot.getEvents().onCommand("info", [&bot](TgBot::Message::Ptr message) {
		
		system("sudo modprobe w1-gpio");
		system("sudo modprobe w1-therm");
		const char arquivo_temp[50] = "/sys/bus/w1/devices/28-0207917754c6/w1_slave";
		float temperatura,ph,ph_dado;
		char ola[10],oi[10];
		char frase[20] = "Temperatura = ";
		char frase2[20] = "PH = ";
		char *temp;
		char buf[100];
		int fd;
		if((fd = open(arquivo_temp,O_RDONLY)) < 0)
        {	
            printf("erro na abertura do arquivo\n");
            return 1;
         }
          
        if(read(fd,buf,sizeof(buf)) < 0)
        {
            printf("erro na leitura do arquivo!\n");
            return 1;
        }
		 	temp = strchr(buf,'t');
			sscanf(temp,"t=%s",temp);
			temperatura = atoi(temp)/1000;
			gcvt(temperatura,10,ola);
			strcat(frase,ola);
			strcat(frase, "°C");
		//final = strcat("Temperatura = ",temp_final);
		//message->text = temp_final;
		//read(i2c_fd, &ph_ret, 1);
		int l = 0;
		for (l = 0; l<9; l++)
		{
		ph_dado+=analogRead(A0)/10;
		}
		printf("%.1f",ph_dado);
		ph=(ph_dado*3.3/255)*(-5.7)+16.34;
		gcvt(ph,3,oi);
		strcat(frase2,oi);
        bot.getApi().sendMessage(message->chat->id, frase);
	bot.getApi().sendMessage(message->chat->id, frase2);
	//close(i2c_fd);
    });
		bot.getEvents().onCommand("Luisa", [&bot, &photoFilePath, &photoMimeType](Message::Ptr message) {
        bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("urso.jpg", photoMimeType));
    });
		bot.getEvents().onCommand("Anderson", [&bot, &photoFilePath, &photoMimeType](Message::Ptr message) {
        bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("bode.jpg", photoMimeType));
    });
		

		try {
        printf("Nome do bot: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
       
            printf("poll started\n");
            
            //message->text = temp_final;
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        printf("erro: %s\n", e.what());
    }
		return 0;
	}
