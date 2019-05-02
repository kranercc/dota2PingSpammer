from mouse import click
from keyboard import is_pressed, press, release
from time import sleep
import os

# readfile
cfg = open("config.txt",'r');

contents = [];
for line in cfg:
	contents = line.split("\t");

button = contents[0]; 
times = int(contents[1]);
typeOfPing = contents[2].lower();
							 

#some user info
os.system("@echo off"); os.system("title Ping Spammer @krane"); os.system("clear"); os.system("color a"); print("Script Working. \nMinimize this window.");



#clicking action
while (1):
	if (is_pressed(button)):
		if typeOfPing != "x":
				press("alt");
				click();
				sleep(1/times);
				release("alt");
		else:
				press("alt");
				press("ctrl");
				click();
				release("alt");
				release("ctrl");

				sleep(1/times);
