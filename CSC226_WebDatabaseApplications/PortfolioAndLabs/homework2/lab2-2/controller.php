<?php
include('userdata.php');
$errors = [];
$success = [];
if(isset($_POST['submit'])){
    $name = $_POST['username'];
    $pass = $_POST['password'];
    //sanitizing the inputs
    $name = htmlspecialchars($name);
    $pass = htmlspecialchars($pass);

    //validating data
    if(empty($name)){
        $errors[] = "Please input a username.";
    }
    if(empty($pass)){
        $errors[] = "Please input a password.";
    }
    if(!empty($name) && !empty($pass)){
    foreach($userInfo as $key => $user){
        foreach($user as $username => $password){
            if($username == $name && $password == $pass){
                $success[] = "Username and password matches!";
            }
        }
    }
    if(!$success>0){
     $errors[] = "Username and password do not match.";   
    }
    }
    //cookies
    setcookie("username", "$name", time()+60*60, "/", "", 0, 0);
}
?>