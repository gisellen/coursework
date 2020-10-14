<!DOCTYPE html>
<html>
<head>
    <title>Fruits Array</title>
    <link rel="stylesheet" href="../style.css">
</head>
<body style="background-color: #F4F9E9;">
    <?php
    $fruits=["Apple", "Banana", "Mango", "Kiwi", "Strawberry"];

    echo "<b>Ouput array using a for loop:</b><br>";
    for($i=0; $i < count($fruits); $i++){
        echo "$fruits[$i] <br>";
    }

    echo "<br> <b>Output array using foreach():</b> <br>";
    foreach($fruits as $fruit){
        echo "$fruit <br>";
    }

    //sorting the array
    arsort($fruits);

    echo "<br><b> Ouputing the array using foreach after sort: </b><br>";
    foreach($fruits as $fruit){
        echo "$fruit <br>";
    }
    echo "<br> <b> What does the arsort() do? </b> <br>";
    echo "The arsort() sorts the array in a decreasing order.  Since the array is a string, it will decrease based on the value of the string.";

    $users = array(
        1 => array("user1" => "password1"),
        2 => array("user2" => "password2"),
        "3" => array("user3" => "password3"),
        array("user4" => "password4"),
    );
    echo "<br><br><b> What does the users array do? </b>";
    echo "<br>The array, 'users', that was created has an array of keys which contain more arrays.  Each array is basically set up like a linked list in order to keep data in order.
    Below is a display of each array: <br><br>";
    ?>
    <table border=1>
        <tr>
            <th>Username</th>
            <th>Password</th>
        </tr>
            <?php
            foreach($users as $key => $user){
                foreach($user as $username => $password){
                    echo "<tr>";
                    echo "<td>$username</td>";
                    echo "<td>$password</td>";
                    echo "</tr>";
                }
            }
            ?>
    </table>
<a style="font-size: 50px;" href="partB.html" title="go back?">&#8592;</a>
</body>
</html>