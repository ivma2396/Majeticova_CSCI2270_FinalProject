# Majeticova_CSCI2270_FinalProject

Project	Summary
My program is taking times from the 2016 East Coast Collegiate Nationals and pulling random facts out of this data set. It is
specifically analyzing the top 100 swims of the Girls 50yd Breaststroke. It is pretty self explanitory, it has a main menu of 
options that are briefly explained. Its main functionalities are printing the entire or partial list of names and times, find the 
average time, find individual people or individual and their performance. It also finds if an individual improved from their expected 
time to the time they actually swam. Lastly it can find all the individuals that tied and it prints those names out. It stores all of the
data in a linked list and searches through it to find what it needs.

How to Run
In order to run this program you have to download the document with the times in it. This is included in the repository as 
Times.txt it has been slightly altered so that a more simple program can read it. This txt file is the only thing that sould stop the
program from running. Also be careful as the inputs are case sensitive so for names "nicole" will not work, you must use "Nicole". As soon
as the program runs it gives you a main menu of options, options 1,4,5 and 9 require no input, they simply spit out data. For option 2
it will prompt you for a number, this number is the number of the place you want to display, if you want to see the third place winner input 
the number 3, it only goes to 99th place so keep your number between 1 and 100. Option 3 will ask you for a name, first it will ask if you
want to search by first name or last name input "f" or "l" depending on what you want. Then it will want the name, to find a name that
exists you can print the whole list and remember one or use a first name such as "Erica" or "Nicole" and a last name such as "Klein"
or "Fano". Option 6 will require the same input as option 3 but it will output differnt information. Option 7 prints out selected places, so 
for example if you input 1 and 5 it will print the winner up until 5th place, or the input 40-45 will print 40th place through 45th place.
Lastly option 8 is similar to option 7, but instead of places it asks for times, so you can input 30 and 31 and it will display all the 
swimmers that had a time between those two times, times range from about 29-39.


Dependencies
The only thing this program depends on is the Times.txt file. This file contains all of the times that get inputed, the program reads
this file by itself, all you need to do is download it similarly to the .txt files we used this semester in assignments. Make sure to save
it in the directory with the program or else it wont find it. You can find this file in the repository with the rest of the code.

System	Requirements
Im not really sure what the program needs, it was created in the virtual machine on code blocks so i know that it works there. So i would
imagine that it would work on any environment similar to what the VM is running so, Ubuntu?

Group	Members
No group members, just me (Iva Majeticova)

Contributors
As of right now none.

Open	issues/bugs
I do not know of any, but if you find some please let me know 
