<?php
    $errors = [];
    $success = [];
	if(isset($_GET['submit'])){
    $pattern = "/^[1-9][0-9]{2}(\.|\-)[0-9]{3}(\.|\-)[0-9]{4}$/";
    $num = $_GET['phoneNum']; 
    //sanitize the input
    $filter = htmlspecialchars($num);
    /* Check the error from the input:
        if input from user is empty
          -> get an error string variable
        if input is not empty
          -> use preg_match() to match the pattern
          $pattern = "/^[1-9][0-9]{2}(\.|\-)[0-9]{3}(\.|\-)[0-9]{4}$/";
          -> if it's a matched, get a success string variable
    */
    if(empty($num)){
      $errors['phoneNum'] = "Please enter a valid phone number!";
    }
    elseif (!preg_match($pattern, $num)) {
      $errors['phoneNum'] = "Must enter a valid phone number!";
    }
    else{
      $success['phoneNum'] = "Phone number is valid!";
    }
  }
?>
<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" integrity="sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z" crossorigin="anonymous">
    <link rel="stylesheet" href="">
    <title>Lab 2-Part1</title>
  </head>
  <body style="background-color: #F4F9E9;">
  	<form action="assignmentfinal.php" class="main-form needs-validation">
      <div class="form-group">
       <label for="numbers">Phone Number</label>
       <input type="text" name="phoneNum" id="numbers" class="form-control" value=<?php if(!empty($num)){ echo $num; }?>>
       <small class="form-text text-muted">xxx.xxx.xxx or xxx-xxx-xxxx</small>
      <!-- Set a condition
            if there is an error string variable, print out the string in PHP
            if there is a success string variable, print out the string in PHP
      -->
      <?php
        if(count($errors) > 0 ):
      ?>    
	       	<div class="alert alert-danger">
           <?php foreach($errors as $error => $description){
             echo $description;
           } 
           ?>
         </div>
      <?php 
        elseif(count($success) > 0):
      ?>
	   		<div class="alert alert-success">
         <?php foreach($success as $valid => $description){
             echo $description;
           } 
           ?>
         </div>
         <?php
        endif;
         ?>
      </div>
      <button type="submit" name="submit" class="btn btn-primary" >Submit</button>
    </form>
    <a style="font-size: 50px;" href="./lab2parts.html" title="go back?">&#8592;</a>


    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js" integrity="sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js" integrity="sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV" crossorigin="anonymous"></script>
  </body>
</html>