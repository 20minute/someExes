<?php
    include_once 'functions.php';
    
    $fields = readQuestions();
    
    $check = 0;
    $names = getNames($fields);
    $res = array();
    foreach($names as $name) {
        $tmp = $_POST["$name"];
        array_push($res ,  $tmp);
    }
   
    $fname = 'data.csv'; //NAME OF THE FILE
    $fcon = fopen($fname,'a');
    // save the column headers
    fputcsv($fcon,  $res);
    fclose($fcon);
    header('Location: close.php');

?>


