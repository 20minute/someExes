<?php
    include_once 'functions.php';
    
    $fields = readQuestions();
    
    $check = 0;
    $res = array();
    foreach($fields as $value) {
        $name = $value->name;
        $tmp = $_POST["$name"];
        array_push($res ,  $tmp);
    }
   
    $fname = 'data.csv'; //NAME OF THE FILE
    $fcon = fopen($fname,'a');
    // save the column headers
    fputcsv($fcon,  $res);
    fclose($fcon);

    $close = 1;
    echo "<script>alert('Thank you');location.href='index.php?close=$close'</script>";

?>


