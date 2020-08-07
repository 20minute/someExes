<?php
class Question {
    public $type;
    public $context;
    public $name;
    
    function __construct($type,$context,$name) {
        $this->type = $type;
        $this->context = $context;
        $this->name = $name;
    }
}

function addQuestion($type, $question, $name) {
    switch($type) {

        case "text": 
?>
            <div class="form-group">
            <label for="<?= $name?>"><?= $question ?></label>
            <textarea class="form-control" name="<?= $name?>" id="<?= $name?>"></textarea>
            </div>
<?php
        break;
       
        case "scale":
?>
            <div class="form-group">
                <label for="<?= $name?>"><?= $question ?></label>
                <select class="form-control"  name="<?= $name?>" id="<?= $name?>" >
                    <option value="1">very negative</option>
                    <option value="2">negative</option>
                    <option selected="selected" value="3">neutral</option>
                    <option value="4">positive</option>
                    <option value="5">very positive</option>
                </select>

            </div>
<?php
        break;
    }
}
?>

<?php

function addQuestionsInHTML(){
    $file = fopen('questions.csv', 'r');
    while (($line = fgetcsv($file)) !== FALSE) {
    //$line is an array of the csv elements

        $type = $line[0];
        $context = $line[1];
        $name = $line[2];

        addQuestion($type, $context, $name);
       
    }
    fclose($file);
}

function readQuestions(){
    $questions = array();
    $file = fopen('questions.csv', 'r');
    while (($line = fgetcsv($file)) !== FALSE) {
    //$line is an array of the csv elements

        $type = $line[0];
        $context = $line[1];
        $name = $line[2];
        $question = new Question($type,$context,$name);
        array_push($questions,$question);
    }
    fclose($file);

    return $questions;
}

function getNames($fields){
    
    $res = array();
    foreach($fields as $value) {
        $name = $value->name;
        array_push($res ,  $name);
    }

    return $res;
}
?>