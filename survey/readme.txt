Tools:
Visual Studio Code
XAMPP (Php,Apache)

Framework:
Bootstrap


If you want to add question, you just open questions.csv and add a question with this format:

question
type, question text, question id

ex:
text, how are you ?, question1

survey result is collected in the data.csv

for now i add two types of questions (text and scale), if you want to add more type of question, 
modify the function addQuestion($type, $question, $name) in functions.php



PS: there is a bug when closing the window
TODO : data check.