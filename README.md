# german-grammar

German grammar can sometimes get a little hairy. However, certain aspects of it are surprisingly
simple to model with algorithms. Adjective endings, or Adjektivendungen, for example, follow a 
fairly steady pattern, despite seeming confusing at first glance. Determiner, gender, and case
are the three aspects of a noun which provide information on what kind of ending any adjectives
which may precede it should have. I decided to write this program to make the process of figuring
out German adjective endings a little easier to understand.

UPDATE 10/27/17: Added very basic test. Will update with more.

COMPILE AND RUN INSTRUCTIONS:
g++ main.cpp Adjektivendungen.cpp -o main
./main < test_file.txt > output.txt

TODO: Rewrite in Python as web application.
