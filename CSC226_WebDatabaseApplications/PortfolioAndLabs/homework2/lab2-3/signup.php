<?php 
//setting variables
$errors = [];
$success = [];
if(isset($_POST['submit'])){
    $pattern = "/[a-z]{4}[0-9]{2}/";
    $name = $_POST['username'];
    $pass = $_POST['password'];
    //sanitizing inputs
    $name = htmlspecialchars($name);
    $pass = htmlspecialchars($pass);
    //validating data
    if(empty($name)){
        $errors[] = "Please enter a username.";
    }
    if(empty($pass)){
        $errors[] = "Please enter a password.";
    }
    if(!empty($name) && !empty($pass)){
        if(!preg_match($pattern, $pass)){
            $errors[] = "Password invalid.";
        }
        else{
        $success[] = "Sign up complete!";
    }
    }
}
?>
<!DOCTYPE html>
<html>
    <head>
        <title>sign up</title>
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    </head>
    <body style="background-color: #F4F9E9;">
        <form action="" method="POST">
            <input type="text" name="username" value="<?php if(!empty($name)){echo $name;}?>">
            <input type="password" name="password" value="">
            <input type="submit" name="submit" value="sign up!">
            <p><br>password format should be:
            <ul>
                <li>total 6 characters</li>
                <li>first 4 characters lowercase letters</li>
                <li>last 2 characters numbers</li>
            <b>example:</b> adam34
            </ul></p>
            <a style="font-size: 50px;" href="../lab2parts.html" title="go back?">&#8592;</a>
            <?php if(count($errors)>0): ?>
            <div class="alert alert-danger" role="alert">
                <?php foreach($errors as $key => $description){
                    echo "$description <br>";
                }?>
            </div>
            <?php endif; ?>
            <?php if(count($success) > 0): ?>
            <div class="alert alert-success" role="alert">
                <?php 
                foreach($success as $valid => $description){
                    echo $description;
                }
                ?>
            </div>
            <?php endif; ?>
        </form>
    <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
    </body>
</html>