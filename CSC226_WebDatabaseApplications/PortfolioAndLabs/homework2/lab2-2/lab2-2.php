<?php include('controller.php'); ?>
<!DOCTYPE html>
<html>
    <head>
        <title>lab 2-2</title>
    </head>
    <body style="background-color: #F4F9E9;">
        <form action="lab2-2.php" method="POST"> 
            <label for="username">Username</label>
            <input type="text" name="username" value="<?php if(!empty($name)){ echo $name; } ?>">
            <label for="password">Password</label>
            <input type="password" name="password" value="<?php if(!empty($pass)){ echo $pass; } ?>">
            <input type="submit" name="submit" value="submit">
        </form>
        <?php 
        if(count($errors)>0):
        ?>
        <ul>
            <?php 
            foreach($errors as $error => $description):
            ?>
            <li><?php echo $description?></li>
            <?php endforeach; ?>
        </ul>
        <?php else: ?>
        <ul>
            <?php 
            foreach($success as $success => $description):
            ?>
            <li><?php echo $description?></li>
            <a href="welcomepage.php">WELCOME</a>
            <?php endforeach; ?>
        </ul>
        <?php endif; ?>
        <a style="font-size: 50px;" href="../lab2parts.html" title="go back?">&#8592;</a>
    </body>
</html>